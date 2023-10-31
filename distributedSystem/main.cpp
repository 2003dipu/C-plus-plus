// ------------------------------------------ main.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stdc++.h>
using namespace std;

class KeyValue{
public:
    string key;
    string value;
};

/**
 * @brief 自己写的字符串按照单词分割函数，因为mapReduce中经常用到
 * 
 * @param text 传入的文本内容，数据量极大
 * @param length 传入的字符串长度
 * @return vector<string> 返回各个分割后的单词列表
 */
vector<string> split(char* text, int length){
    vector<string> str;
    string tmp = "";
    for(int i = 0; i < length; i++){
        if((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
            tmp += text[i];
        }else{
            if(tmp.size() != 0) str.push_back(tmp);      
            tmp = "";
        }
    }
    if(tmp.size() != 0) str.push_back(tmp);
    return str;
}

/**
 * @brief mapFunc，需要打包成动态库，并在worker中通过dlopen以及dlsym运行时加载
 * @param kv 将文本按单词划分并以出现次数代表value长度存入keyValue
 * @return 类似{"my 11111", "you 111"} 即文章中my出现了5次，you出现了3次
 */
extern "C" vector<KeyValue> mapF(KeyValue kv){
    vector<KeyValue> kvs;
    int len = kv.value.size();
    char content[len + 1];
    strcpy(content, kv.value.c_str());
    vector<string> str = split(content, len);
    for(const auto& s : str){
        KeyValue tmp;
        tmp.key = s;
        tmp.value = "1";
        kvs.emplace_back(tmp);
    }
    return kvs;
}

/**
 * @brief redecuFunc，也是动态加载，输出对特定keyValue的reduce结果
 * @param reduceTaskIdx 好像多余了，后来才发现的，放着也没事，懒得重新编译.so了
 * @return vector<string>
 */
extern "C" vector<string> reduceF(vector<KeyValue> kvs, int reduceTaskIdx){
    vector<string> str;
    string tmp;
    for(const auto& kv : kvs){
        str.push_back(to_string(kv.value.size()));
    }
    return str;
}

// ------------------------------------------ master.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "locker.h"
#include "./buttonrpc-master/buttonrpc.hpp"
#include <bits/stdc++.h>
using namespace std;

#define MAP_TASK_TIMEOUT 3
#define REDUCE_TASK_TIMEOUT 5

class Master{
public:
    static void* waitMapTask(void *arg);        //回收map的定时线程
    static void* waitReduceTask(void* arg);     //回收reduce的定时线程
    static void* waitTime(void* arg);           //用于定时的线程
    Master(int mapNum = 8, int reduceNum = 8);  //带缺省值的有参构造，也可通过命令行传参指定，我偷懒少打两个数字直接放构造函数里
    void GetAllFile(char* file[], int index);   //从argv[]中获取待处理的文件名
    int getMapNum(){                            
        return m_mapNum;
    }
    int getReduceNum(){
        return m_reduceNum;
    }
    string assignTask();                        //分配map任务的函数，RPC
    int assignReduceTask();                     //分配reduce任务的函数，RPC
    void setMapStat(string filename);           //设置特定map任务完成的函数，RPC
    bool isMapDone();                           //检验所有map任务是否完成，RPC
    void setReduceStat(int taskIndex);          //设置特定reduce任务完成的函数，RPC
    void waitMap(string filename);
    void waitReduce(int reduceIdx);
    bool Done();                                //判断reduce任务是否已经完成
    bool getFinalStat(){                        //所有任务是否完成，实际上reduce完成就完成了，有点小重复
        return m_done;
    }
private:
    bool m_done;
    list<char *> m_list;                        //所有map任务的工作队列
    locker m_assign_lock;                       //保护共享数据的锁
    int fileNum;                                //从命令行读取到的文件总数
    int m_mapNum;
    int m_reduceNum;
    unordered_map<string, int> finishedMapTask; //存放所有完成的map任务对应的文件名
    unordered_map<int, int> finishedReduceTask; //存放所有完成的reduce任务对应的reduce编号
    vector<int> reduceIndex;                    //所有reduce任务的工作队列
    vector<string> runningMapWork;              //正在处理的map任务，分配出去就加到这个队列，用于判断超时处理重发
    int curMapIndex;                            //当前处理第几个map任务
    int curReduceIndex;                         //当前处理第几个reduce任务
    vector<int> runningReduceWork;              //正在处理的reduce任务，分配出去就加到这个队列，用于判断超时处理重发
};


Master::Master(int mapNum, int reduceNum):m_done(false), m_mapNum(mapNum), m_reduceNum(reduceNum){
    m_list.clear();
    finishedMapTask.clear();
    finishedReduceTask.clear();
    runningMapWork.clear();
    runningReduceWork.clear();
    curMapIndex = 0;
    curReduceIndex = 0;
    if(m_mapNum <= 0 || m_reduceNum <= 0){
        throw std::exception();
    }
    for(int i = 0; i < reduceNum; i++){
        reduceIndex.emplace_back(i);
    }
}

void Master::GetAllFile(char* file[], int argc){
    for(int i = 1; i < argc; i++){
        m_list.emplace_back(file[i]);
    }
    fileNum = argc - 1;
}

//map的worker只需要拿到对应的文件名就可以进行map
string Master::assignTask(){
    if(isMapDone()) return "empty";
    if(!m_list.empty()){
        m_assign_lock.lock();
        char* task = m_list.back(); //从工作队列取出一个待map的文件名
        m_list.pop_back();            
        m_assign_lock.unlock();
        waitMap(string(task));      //调用waitMap将取出的任务加入正在运行的map任务队列并等待计时线程
        return string(task);
    }
    //m_hashSet.erase(task);
    return "empty";
}

void* Master::waitMapTask(void* arg){
    Master* map = (Master*)arg;
    // printf("wait maphash is %p\n", &map->master->finishedMapTask);
    void* status;
    pthread_t tid;
    char op = 'm';
    pthread_create(&tid, NULL, waitTime, &op);
    pthread_join(tid, &status);  //join方式回收实现超时后解除阻塞
    map->m_assign_lock.lock();
    //若超时后在对应的hashmap中没有该map任务完成的记录，重新将该任务加入工作队列
    if(!map->finishedMapTask.count(map->runningMapWork[map->curMapIndex])){
        printf("filename : %s is timeout\n", map->runningMapWork[map->curMapIndex].c_str());
        // char text[map->runningMapWork[map->curMapIndex].size() + 1];
        // strcpy(text, map->runningMapWork[map->curMapIndex].c_str());
        // printf("text is %s\n", text);   打印正常的，该线程结束后text就变成空字符串了
        const char* text = map->runningMapWork[map->curMapIndex].c_str();//这钟方式加入list后不会变成空字符串
        map->m_list.push_back((char*)text);
        map->curMapIndex++;
        map->m_assign_lock.unlock();
        return NULL;
    }
    printf("filename : %s is finished at idx : %d\n", map->runningMapWork[map->curMapIndex].c_str(), map->curMapIndex);
    map->curMapIndex++;
    map->m_assign_lock.unlock();
}

void Master::waitMap(string filename){
    m_assign_lock.lock();
    runningMapWork.push_back(string(filename));  //将分配出去的map任务加入正在运行的工作队列
    m_assign_lock.unlock();
    pthread_t tid;
    pthread_create(&tid, NULL, waitMapTask, this); //创建一个用于回收计时线程及处理超时逻辑的线程
    pthread_detach(tid);
}

//分map任务还是reduce任务进行不同时间计时的计时线程
void* Master::waitTime(void* arg){
    char* op = (char*)arg;
    if(*op == 'm'){
        sleep(MAP_TASK_TIMEOUT);
    }else if(*op == 'r'){
        sleep(REDUCE_TASK_TIMEOUT);
    }
}

void* Master::waitReduceTask(void* arg){
    Master* reduce = (Master*)arg;
    void* status;
    pthread_t tid;
    char op = 'r';
    pthread_create(&tid, NULL, waitTime, &op);
    pthread_join(tid, &status);
    reduce->m_assign_lock.lock();
    //若超时后在对应的hashmap中没有该reduce任务完成的记录，将该任务重新加入工作队列
    if(!reduce->finishedReduceTask.count(reduce->runningReduceWork[reduce->curReduceIndex])){
        for(auto a : reduce->m_list) printf(" before insert %s\n", a);
        reduce->reduceIndex.emplace_back(reduce->runningReduceWork[reduce->curReduceIndex]);
        printf(" reduce%d is timeout\n", reduce->runningReduceWork[reduce->curReduceIndex]);
        reduce->curReduceIndex++;
        for(auto a : reduce->m_list) printf(" after insert %s\n", a);
        reduce->m_assign_lock.unlock();
        return NULL;
    }
    printf("%d reduce is completed\n", reduce->runningReduceWork[reduce->curReduceIndex]);
    reduce->curReduceIndex++;
    reduce->m_assign_lock.unlock();
}

void Master::waitReduce(int reduceIdx){
    m_assign_lock.lock();
    runningReduceWork.push_back(reduceIdx); //将分配出去的reduce任务加入正在运行的工作队列
    m_assign_lock.unlock();
    pthread_t tid;
    pthread_create(&tid, NULL, waitReduceTask, this); //创建一个用于回收计时线程及处理超时逻辑的线程
    pthread_detach(tid);
}

void Master::setMapStat(string filename){
    m_assign_lock.lock();
    finishedMapTask[filename] = 1;  //通过worker的RPC调用修改map任务的完成状态
    // printf("map task : %s is finished, maphash is %p\n", filename.c_str(), &finishedMapTask);
    m_assign_lock.unlock();
    return;
}

bool Master::isMapDone(){
    m_assign_lock.lock();
    if(finishedMapTask.size() != fileNum){  //当统计map任务的hashmap大小达到文件数，map任务结束
        m_assign_lock.unlock();
        return false;
    }
    m_assign_lock.unlock();
    return true;
}

int Master::assignReduceTask(){
    if(Done()) return -1;
    if(!reduceIndex.empty()){
        m_assign_lock.lock();
        int reduceIdx = reduceIndex.back(); //取出reduce编号
        reduceIndex.pop_back();
        m_assign_lock.unlock();
        waitReduce(reduceIdx);    //调用waitReduce将取出的任务加入正在运行的reduce任务队列并等待计时线程
        return reduceIdx;
    }
    return -1;
}


void Master::setReduceStat(int taskIndex){
    m_assign_lock.lock();
    finishedReduceTask[taskIndex] = 1;  //通过worker的RPC调用修改reduce任务的完成状态
    // printf(" reduce task%d is finished, reducehash is %p\n", taskIndex, &finishedReduceTask);
    m_assign_lock.unlock();
    return;
}

bool Master::Done(){
    m_assign_lock.lock();
    int len = finishedReduceTask.size(); //reduce的hashmap若是达到reduceNum，reduce任务及总任务完成
    m_assign_lock.unlock();
    return len == m_reduceNum;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        cout<<"missing parameter! The format is ./Master pg*.txt"<<endl;
        exit(-1);
    }
    // alarm(10);
    buttonrpc server;
    server.as_server(5555);
    Master master(13, 9);
    master.GetAllFile(argv, argc);
    server.bind("getMapNum", &Master::getMapNum, &master);
    server.bind("getReduceNum", &Master::getReduceNum, &master);
    server.bind("assignTask", &Master::assignTask, &master);
    server.bind("setMapStat", &Master::setMapStat, &master);
    server.bind("isMapDone", &Master::isMapDone, &master);
    server.bind("assignReduceTask", &Master::assignReduceTask, &master);
    server.bind("setReduceStat", &Master::setReduceStat, &master);
    server.bind("Done", &Master::Done, &master);
    server.run();
    return 0;
}
//------------------------------ worker.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include "locker.h"
#include "./buttonrpc-master/buttonrpc.hpp"
#include <bits/stdc++.h>
#include <pthread.h>
#include <dlfcn.h>
using namespace std;

#define LIB_CACULATE_PATH "./libmrFunc.so"  //用于加载的动态库的路径
#define MAX_REDUCE_NUM 15
//可能造成的bug，考虑write多次写，每次写1024用while读进buf
//c_str()返回的是一个临时指针，值传递没事，但若涉及地址出错

int disabledMapId = 0;   //用于人为让特定map任务超时的Id
int disabledReduceId = 0;   //用于人为让特定reduce任务超时的Id

//定义master分配给自己的map和reduce任务数，实际无所谓随意创建几个，我是为了更方便测试代码是否ok
int map_task_num;
int reduce_task_num;

//定义实际处理map任务的数组，存放map任务号
//(map任务大于总文件数时，多线程分配ID不一定分配到正好增序的任务号，如10个map任务，总共8个文件，可能就是0,1,2,4,5,7,8,9)

class KeyValue{
public:
    string key;
    string value;
};

//定义的两个函数指针用于动态加载动态库里的map和reduce函数
typedef vector<KeyValue> (*MapFunc)(KeyValue kv);
typedef vector<string> (*ReduceFunc)(vector<KeyValue> kvs, int reduceTaskIdx);
MapFunc mapF;
ReduceFunc reduceF;

//给每个map线程分配的任务ID，用于写中间文件时的命名
int MapId = 0;            
pthread_mutex_t map_mutex;
pthread_cond_t cond;
int fileId = 0;

//对每个字符串求hash找到其对应要分配的reduce线程
int ihash(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum += (str[i] - '0');
    }
    return sum % reduce_task_num;
}

//删除所有写入中间值的临时文件
void removeFiles(){
    string path;
    for(int i = 0; i < map_task_num; i++){
        for(int j = 0; j < reduce_task_num; j++){
            path = "mr-" + to_string(i) + "-" + to_string(j);
            int ret = access(path.c_str(), F_OK);
            if(ret == 0) remove(path.c_str());
        }
    }
}

//取得  key:filename, value:content 的kv对作为map任务的输入
KeyValue getContent(char* file){
    int fd = open(file, O_RDONLY);
    int length = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    char buf[length];
    bzero(buf, length);
    int len = read(fd, buf, length);
    if(len != length){
        perror("read");
        exit(-1);
    }
    KeyValue kv;
    kv.key = string(file);
    kv.value = string(buf);
    close(fd);
    return kv;
}

//将map任务产生的中间值写入临时文件
void writeKV(int fd, const KeyValue& kv){
    string tmp = kv.key + ",1 ";
    int len = write(fd, tmp.c_str(), tmp.size());
    if(len == -1){
        perror("write");
        exit(-1);
    }
    close(fd);
}

//创建每个map任务对应的不同reduce号的中间文件并调用 -> writeKV 写入磁盘
void writeInDisk(const vector<KeyValue>& kvs, int mapTaskIdx){
    for(const auto& v : kvs){
        int reduce_idx = ihash(v.key);
        string path;
        path = "mr-" + to_string(mapTaskIdx) + "-" + to_string(reduce_idx);
        int ret = access(path.c_str(), F_OK);
        if(ret == -1){
            int fd = open(path.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0664);
            writeKV(fd, v);
        }else if(ret == 0){
            int fd = open(path.c_str(), O_WRONLY | O_APPEND);
            writeKV(fd, v);
        }   
    }
}

//以char类型的op为分割拆分字符串
vector<string> split(string text, char op){
    int n = text.size();
    vector<string> str;
    string tmp = "";
    for(int i = 0; i < n; i++){
        if(text[i] != op){
            tmp += text[i];
        }else{
            if(tmp.size() != 0) str.push_back(tmp);
            tmp = "";
        }
    }
    return str;
}

//以逗号为分割拆分字符串
string split(string text){
    string tmp = "";
    for(int i = 0; i < text.size(); i++){
        if(text[i] != ','){
            tmp += text[i];
        }else break;
    }
    return tmp;
}

//获取对应reduce编号的所有中间文件
vector<string> getAllfile(string path, int op){
    DIR *dir = opendir(path.c_str());
    vector<string> ret;
    if (dir == NULL)
    {
        printf("[ERROR] %s is not a directory or not exist!", path.c_str());
        return ret;
    }
    struct dirent* entry;
    while ((entry=readdir(dir)) != NULL)
    {
        int len = strlen(entry->d_name);
        int oplen = to_string(op).size();
        if(len - oplen < 5) continue;
        string filename(entry->d_name);
        if(!(filename[0] == 'm' && filename[1] == 'r' && filename[len - oplen - 1] == '-')) continue;
        string cmp_str = filename.substr(len - oplen, oplen);
        if(cmp_str == to_string(op)){
            ret.push_back(entry->d_name);
        }
    }
    closedir(dir);
    return ret;
}

//对于一个ReduceTask，获取所有相关文件并将value的list以string写入vector
//vector中每个元素的形式为"abc 11111";
vector<KeyValue> Myshuffle(int reduceTaskNum){
    string path;
    vector<string> str;
    str.clear();
    vector<string> filename = getAllfile(".", reduceTaskNum);
    unordered_map<string, string> hash;
    for(int i = 0; i < filename.size(); i++){
        path = filename[i];
        char text[path.size() + 1];
        strcpy(text, path.c_str());
        KeyValue kv = getContent(text);
        string context = kv.value;
        vector<string> retStr = split(context, ' ');
        str.insert(str.end(), retStr.begin(), retStr.end());
    }
    for(const auto& a : str){
        hash[split(a)] += "1";
    }
    vector<KeyValue> retKvs;
    KeyValue tmpKv;
    for(const auto& a : hash){
        tmpKv.key = a.first;
        tmpKv.value = a.second;
        retKvs.push_back(tmpKv);
    }
    sort(retKvs.begin(), retKvs.end(), [](KeyValue& kv1, KeyValue& kv2){
        return kv1.key < kv2.key;
    });
    return retKvs;
}


void* mapWorker(void* arg){

//1、初始化client连接用于后续RPC;获取自己唯一的MapTaskID
    buttonrpc client;
    client.as_client("127.0.0.1", 5555);
    pthread_mutex_lock(&map_mutex);
    int mapTaskIdx = MapId++;
    pthread_mutex_unlock(&map_mutex);
    bool ret = false;
    while(1){
    //2、通过RPC从Master获取任务
    //client.set_timeout(10000);
        ret = client.call<bool>("isMapDone").val();
        if(ret){
            pthread_cond_broadcast(&cond);
            return NULL;
        }
        string taskTmp = client.call<string>("assignTask").val();   //通过RPC返回值取得任务，在map中即为文件名
        if(taskTmp == "empty") continue; 
        printf("%d get the task : %s\n", mapTaskIdx, taskTmp.c_str());
        pthread_mutex_lock(&map_mutex);

        //------------------------自己写的测试超时重转发的部分---------------------
        //注：需要对应master所规定的map数量，因为是1，3，5被置为disabled，相当于第2，4，6个拿到任务的线程宕机
        //若只分配两个map的worker，即0工作，1宕机，我设的超时时间比较长且是一个任务拿完在拿一个任务，所有1的任务超时后都会给到0，
        if(disabledMapId == 1 || disabledMapId == 3 || disabledMapId == 5){
            disabledMapId++;
            pthread_mutex_unlock(&map_mutex);
            printf("%d recv task : %s  is stop\n", mapTaskIdx, taskTmp.c_str());
            while(1){
                sleep(2);
            }
        }else{
            disabledMapId++;   
        }
        pthread_mutex_unlock(&map_mutex);
        //------------------------自己写的测试超时重转发的部分---------------------

    //3、拆分任务，任务返回为文件path及map任务编号，将filename及content封装到kv的key及value中
        char task[taskTmp.size() + 1];
        strcpy(task, taskTmp.c_str());
        KeyValue kv = getContent(task);

    //4、执行map函数，然后将中间值写入本地
        vector<KeyValue> kvs = mapF(kv);
        writeInDisk(kvs, mapTaskIdx);

    //5、发送RPC给master告知任务已完成
        printf("%d finish the task : %s\n", mapTaskIdx, taskTmp.c_str());
        client.call<void>("setMapStat", taskTmp);

    }
} 

//用于最后写入磁盘的函数，输出最终结果
void myWrite(int fd, vector<string>& str){
    int len = 0;
    char buf[2];
    sprintf(buf,"\n");
    for(auto s : str){
        len = write(fd, s.c_str(), s.size());
        write(fd, buf, strlen(buf));
        if(len == -1){
            perror("write");
            exit(-1);
        }
    }
}

void* reduceWorker(void* arg){
    //removeFiles();
    buttonrpc client;
    client.as_client("127.0.0.1", 5555);
    bool ret = false;
    while(1){
        //若工作完成直接退出reduce的worker线程
        ret = client.call<bool>("Done").val();
        if(ret){
            return NULL;
        }
        int reduceTaskIdx = client.call<int>("assignReduceTask").val();
        if(reduceTaskIdx == -1) continue;
        printf("%ld get the task%d\n", pthread_self(), reduceTaskIdx);
        pthread_mutex_lock(&map_mutex);

        //人为设置的crash线程，会导致超时，用于超时功能的测试
        if(disabledReduceId == 1 || disabledReduceId == 3 || disabledReduceId == 5){
            disabledReduceId++;
            pthread_mutex_unlock(&map_mutex);
            printf("recv task%d reduceTaskIdx is stop in %ld\n", reduceTaskIdx, pthread_self());
            while(1){
                sleep(2);
            }
        }else{
            disabledReduceId++;   
        }
        pthread_mutex_unlock(&map_mutex);

        //取得reduce任务，读取对应文件，shuffle后调用reduceFunc进行reduce处理
        vector<KeyValue> kvs = Myshuffle(reduceTaskIdx);
        vector<string> ret = reduceF(kvs, reduceTaskIdx);
        vector<string> str;
        for(int i = 0; i < kvs.size(); i++){
            str.push_back(kvs[i].key + " " + ret[i]);
        }
        string filename = "mr-out-" + to_string(reduceTaskIdx);
        int fd = open(filename.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0664);
        myWrite(fd, str);
        close(fd);
        printf("%ld finish the task%d\n", pthread_self(), reduceTaskIdx);
        client.call<bool>("setReduceStat", reduceTaskIdx);  //最终文件写入磁盘并发起RPCcall修改reduce状态
    }
}

//删除最终输出文件，用于程序第二次执行时清除上次保存的结果
void removeOutputFiles(){
    string path;
    for(int i = 0; i < MAX_REDUCE_NUM; i++){
        path = "mr-out-" + to_string(i);
        int ret = access(path.c_str(), F_OK);
        if(ret == 0) remove(path.c_str());
    }
}

int main(){
    
    pthread_mutex_init(&map_mutex, NULL);
    pthread_cond_init(&cond, NULL);

    //运行时从动态库中加载map及reduce函数(根据实际需要的功能加载对应的Func)
    void* handle = dlopen("./libmrFunc.so", RTLD_LAZY);
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        exit(-1);
    }
    mapF = (MapFunc)dlsym(handle, "mapF");
    if (!mapF) {
        cerr << "Cannot load symbol 'hello': " << dlerror() <<'\n';
        dlclose(handle);
        exit(-1);
    }
    reduceF = (ReduceFunc)dlsym(handle, "reduceF");
    if (!mapF) {
        cerr << "Cannot load symbol 'hello': " << dlerror() <<'\n';
        dlclose(handle);
        exit(-1);
    }

    //作为RPC请求端
    buttonrpc work_client;
    work_client.as_client("127.0.0.1", 5555);
    work_client.set_timeout(5000);
    map_task_num = work_client.call<int>("getMapNum").val();
    reduce_task_num = work_client.call<int>("getReduceNum").val();
    removeFiles();          //若有，则清理上次输出的中间文件
    removeOutputFiles();    //清理上次输出的最终文件

    //创建多个map及reduce的worker线程
    pthread_t tidMap[map_task_num];
    pthread_t tidReduce[reduce_task_num];
    for(int i = 0; i < map_task_num; i++){
        pthread_create(&tidMap[i], NULL, mapWorker, NULL);
        pthread_detach(tidMap[i]);
    }
    pthread_mutex_lock(&map_mutex);
    pthread_cond_wait(&cond, &map_mutex);
    pthread_mutex_unlock(&map_mutex);
    for(int i = 0; i < reduce_task_num; i++){
        pthread_create(&tidReduce[i], NULL, reduceWorker, NULL);
        pthread_detach(tidReduce[i]);
    }
    while(1){
        if(work_client.call<bool>("Done").val()){
            break;
        }
        sleep(1);
    }

    //任务完成后清理中间文件，关闭打开的动态库，释放资源
    removeFiles();
    dlclose(handle);
    pthread_mutex_destroy(&map_mutex);
    pthread_cond_destroy(&cond);
}