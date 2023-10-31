// -------------------------------------------------------------------kdtree.cpp
#include "kdtree.h"

KdTree::KdTree(distanceFuncType distanceFunction)
    :tree(), distanceFunction(distanceFunction)
{
}

void KdTree::formTree(const Matrix &X, const Matrix &y)
{  
    vector<Matrix> trainSet = X.merge(y, 1).splictRow();
    k = X.columnSize();

    int curDepth = 0;
    treePtr parentOfRoot(nullptr);
    tree = createNode(trainSet, curDepth, parentOfRoot);
    printTree();
}

Matrix KdTree::search(int neighbour, const Matrix &X)
{
    Matrix predict(X.rowSize(), 1);
    vector<Matrix> xVec(X.splictRow());
    for (auto it = xVec.begin(); it != xVec.end(); ++it){
        Matrix xSingle(*it);
        stack<treePtr> path;
        // 1. down to leaf, push node into path
        treePtr curNode(tree);
        while (curNode != nullptr) {
            path.push(curNode);
            int curSplit = curNode->split;
            if (xSingle(0, curSplit) < curNode->data(0, curSplit)) {
                curNode = curNode->left;
            }
            else {
                curNode = curNode->right;
            }
        }

        vector<treePtr> kNearestNeighbour;
        //should be Inf
        double longestInVec = 655536;
        set<treePtr> nodeWalked;
        // 2. start search, go back according to path, use set to record walked node,
        //      put node into vector, sort every time and pop last one, remember the longest
        //      in the vector
        while (!path.empty()) {
            curNode = path.top();

#ifdef DEBUG
            cout << "debug" << endl;
            cout << curNode->data << endl;
#endif

            path.pop();
            nodeWalked.insert(curNode);
            // insert into vec
            double curDistance = distanceFunction(curNode->data, xSingle);
            if (kNearestNeighbour.size() < neighbour) {
                kNearestNeighbour.push_back(curNode);
            }
            else if (curDistance < longestInVec) {
                kNearestNeighbour[neighbour - 1] = curNode;
                sort(kNearestNeighbour.begin(), kNearestNeighbour.end(),
                     [=](const treePtr &lhs, const treePtr &rhs)
                        {return (distanceFunction(lhs->data, xSingle) < distanceFunction(rhs->data, xSingle));});
                longestInVec = distanceFunction(kNearestNeighbour[neighbour - 1]->data, xSingle);
            }

            int curSplit =  curNode->split;
            double hyperplaneDistance = abs(curNode->data(0,curSplit) - xSingle(0, curSplit));
            if (hyperplaneDistance < longestInVec) {
                if (curNode->left != nullptr && nodeWalked.find(curNode->left) == nodeWalked.end()) {
                    path.push(curNode->left);
                }
                if (curNode->right != nullptr && nodeWalked.find(curNode->right) == nodeWalked.end()) {
                    path.push(curNode->right);
                }
            }
        }

        // 3. calculate the predict label
        vector<double> labelAll;
        labelAll.reserve(kNearestNeighbour.size());
        for (treePtr &node : kNearestNeighbour)
            labelAll.push_back(node->label);
        sort(labelAll.begin(), labelAll.end());

        int numMax = 0;
        double labelMax = labelAll[0];
        int curNum = 0;
        double curLabel = labelAll[0];
        for (auto label : labelAll) {
            if (label == curLabel) {
                ++curNum;
            }
            else {
                if (curNum > numMax) {
                    numMax = curNum;
                    labelMax = curLabel;
                }
                curNum = 1;
                curLabel = label;
            }
        }
        if (curNum > numMax) {
            labelMax = curLabel;
        }

#ifdef DEBUG
        for (auto label : labelAll)
            cout << label << '\t';
        cout << endl;
#endif

        auto indexOfMatrix = it - xVec.begin();
        predict(indexOfMatrix, 0) = labelMax;
    }

    return predict;
}

KdTree::treePtr KdTree::createNode(vector<Matrix> &trainSet, int curDepth, treePtr parent)
{
    if (trainSet.size() <=0) {
        return nullptr;
    }

    int split = curDepth % k;

    treePtr node(new treeNode);
    node->parent = parent;
    node->split = split;

    sort(trainSet.begin(), trainSet.end(), [split](Matrix &lhs, Matrix &rhs) {return lhs(0, split) < rhs(0, split);});
    Matrix dataCur = trainSet[trainSet.size() / 2];
    trainSet.erase(trainSet.begin() + trainSet.size() / 2);
    vector<Matrix> leftSet(trainSet.begin(), trainSet.begin() + trainSet.size() / 2);
    vector<Matrix> rightSet(trainSet.begin() + trainSet.size() / 2, trainSet.end());

    node->data = dataCur.splice(0, dataCur.columnSize() - 1, 1);
    node->label = dataCur(0, dataCur.columnSize() - 1);

    int childDepth = curDepth + 1;
    node->left = createNode(leftSet, childDepth, node);
    node->right = createNode(rightSet, childDepth, node);

    return node;
}

void KdTree::printTree(ostream & out) const
{
    deque<treePtr> q1;
    q1.push_back(tree);
    deque<treePtr> q2;
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            for (treePtr node : q1) {
                if (node->left != nullptr)
                    q2.push_back(node->left);
                if (node->right != nullptr)
                    q2.push_back(node->right);
                out << node->data;
            }
            out << endl;
            q1.clear();
        }
        else {
            for (treePtr node : q2) {
                if (node->left != nullptr)
                    q1.push_back(node->left);
                if (node->right != nullptr)
                    q1.push_back(node->right);
                out << node->data;
            }
            out << endl;
            q2.clear();
        }
    }
}
//--------------------------------------------------------------------------------------------------
// knn.cpp

#include "knn.h"

KNN::KNN(int neighbour, KdTree::distanceFuncType distanceFunc)
    :neighbour(neighbour), tree(distanceFunc)
{
}

void KNN::train(const Matrix &X, const Matrix &y)
{
    tree.formTree(X, y);
}

Matrix KNN::predict(const Matrix &X)
{
    return tree.search(neighbour, X);
}

//--------------------------------------------------------------------------------------------------
// main.cpp
#include <iostream>

#include "matrix.h"
#include "perceptron.h"
#include "knn.h"
#include "naivebayes.h"

using std::cout;
using std::endl;

void MatrixUnitTest();
void PerceptronUnitTest();
void KnnUnitTest();
void NaiveBayesUnitTest();

int main()
{
    NaiveBayesUnitTest();
    return 0;
}

void NaiveBayesUnitTest()
{
    Matrix X{{1, 4}, {1, 5}, {1, 5}, {1, 4}, {1, 4}, {2, 4}, {2, 5},
             {2, 5}, {2, 6}, {2, 6}, {3, 6}, {3, 5}, {3, 5}, {3, 6}, {3, 6}};
    Matrix y{{-1},    {-1},   {1},    {1},   {-1},   {-1},   {-1},
             {1},    {1},    {1},     {1},   {1},    {1},    {1},    {-1}};
    cout << "X" << endl << X << endl;
    cout << "y" << endl << y << endl;

    NaiveBayes naivebayesModel(1);
    naivebayesModel.train(X, y);

    X = Matrix{{2, 4}};
    auto predict = naivebayesModel.predict(X);
    cout << predict <<endl;


}

void KnnUnitTest()
{
    Matrix X{{4, 4}, {3, 2}, {7, 3}, {1, 1}, {2, 5}, {6, 6}, {5, 1}};
    Matrix y{{1},    {-1},   {1},    {1},    {-1},   {1},    {-1}};
    cout << "X" << endl << X << endl;
    cout << "y" << endl << y << endl;

    KNN knnModel(1);
    knnModel.train(X, y);

    cout << "start train..." << endl;
    Matrix predict = knnModel.predict(X);
    cout << predict << endl;
}

void PerceptronUnitTest()
{
    Matrix X{{3, 3}, {4, 3}, {1, 1}};
    Matrix y{{1}, {1}, {-1}};
    cout << "X" << endl << X << endl;
    cout << "y" << endl << y << endl;

    // Origin algorithm
    Perceptron percetronModel(1, 100);
    percetronModel.train(X, y);
    auto weight = percetronModel.getWeight();
    cout << "weight" << endl << weight << endl;

    auto yPredict = percetronModel.predict(X);
    cout << "yPredict" << endl << yPredict << endl;

    // Parallelism algorithm
    Perceptron percetronModel2(1, 100, Perceptron::Parallelism);
    percetronModel2.train(X, y);
    weight = percetronModel2.getWeight();
    cout << "weight" << endl <<weight << endl;

    yPredict = percetronModel2.predict(X);
    cout << "yPredict" << endl << yPredict << endl;
}

void MatrixUnitTest()
{
    Matrix m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    m(1, 1) = 99;
    cout << "m" << endl << m << endl;

    Matrix n{{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    cout << "n" << endl << n << endl;

    auto plus = m + n;
    cout << "plus" << endl << plus << endl;

    auto minus = m - n;
    cout << "minus" << endl << minus << endl;

    auto mutipleWithConstRight = n * 4;
    cout << "mutipleWithConstRight" << endl << mutipleWithConstRight << endl;

    auto mutipleWithConstLeft = 4 * n;
    cout << "mutipleWithConstLeft" << endl << mutipleWithConstLeft << endl;

    m = Matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    n = Matrix{{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    cout << "n" << endl << n << endl;

    auto mutipleWithMatrix = m * n;
    cout << "mutipleWithMatrix" << endl << mutipleWithMatrix << endl;

    m.merge(n, 1, true);
    cout << "mMergeNAxis1Inplace" << endl << m << endl;

    auto mMergeMAxis0 = m.merge(m, 0, true);
    cout << "mMergeMAxis0" << endl << mMergeMAxis0 << endl;

    cout << "equal test" << endl;
    cout << "m == n" << '\t' << (m == n) << endl;
    cout << "m == m" << '\t' << (m == m) << endl;

    cout << "m" << endl << m << endl;
    m.splice(1, 2, 1, true);
    cout << "m after splice" << endl << m << endl;

    m.merge(m, 1, true);
    cout << "m merge self" << endl << m << endl;

    auto mSpliceAxis0 = m.splice(2, m.rowSize(), 0);
    cout << "mSpliceAxis0" << endl << mSpliceAxis0 << endl;

    m = Matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    n = Matrix{{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    cout << "n" << endl << n << endl;

    cout << "m" << endl << m << endl;
    auto mReverse = m.reverse();
    cout << "mReverse" << endl << mReverse << endl;

    m = Matrix{{1, 2, 3}};
    cout << "m" << endl << m << endl;

    n = Matrix{{4, 5, 6}};
    cout << "n" << endl << n << endl;

    double innerProductExample = m.innerProduct(n);
    cout << "innerProductExample" << endl << innerProductExample << endl;
    cout << endl;

    m = Matrix{{-1, 1, -10, -100, 3}};
    cout << "m" << endl << m << endl;

    auto mSign = m.sign();
    cout << "mSign" << endl << mSign << endl;

    n = Matrix{{4}, {5}, {6}};
    cout << "n" << endl << n << endl;
    auto k = n * n.reverse();
    cout << "k" << endl << k << endl;

    m = Matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    n = Matrix{{0, 0, 0}, {1, 1, 1}, {2, 2, 2}};
    cout << "n" << endl << n << endl;

    auto dotProductExample = m.dotProduct(n);
    cout << "dotProductExample" << endl << dotProductExample << endl;

    m = Matrix{{1, -2, 3}, {4, -5, 6}, {7, -8, 9}};
    cout << "m" << endl << m << endl;

    m.abs(true);
    cout << "mAbs" << endl << m << endl;

    m = Matrix{{1, -2, 3}, {4, -5, 6}, {7, -8, 9}};
    cout << "m" << endl << m << endl;

    m.square(true);
    cout << "mSquare" << endl << m << endl;

    m = Matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    auto mSum = m.sum();
    cout << "mSum" << endl << mSum << endl << endl;

    m = Matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "m" << endl << m << endl;

    auto mMax = m.max();
    cout << "mMax" << endl << mMax << endl << endl;

    cout << "m" << endl << m << endl;
    auto mVec = m.splictRow();
    for (auto &unit : mVec)
        cout << "row: " << unit;

    m = Matrix{{1, 2, 3}, {1, 5, 3}, {1, 2, 7}};
    cout << "m" << endl << m << endl;

    auto distinctVV = m.distinctColumn();
    cout << "distinctVV" << endl << distinctVV << endl;
}

// -------------------------------------------------- matrix.cpp

#include "matrix.h"

Matrix::Matrix()
    :row(0), column(0), mat()
{

}

Matrix::Matrix(initializer_list<initializer_list<double>> initArray)
    :row(initArray.size()), column(initArray.begin()->size()),
    mat(row * column, 0)
{
    auto copyPlace = mat.begin();
    for (auto &rowInArray : initArray)
        copyPlace = copy(rowInArray.begin(), rowInArray.end(), copyPlace);
}

Matrix::Matrix(size_t row, size_t column, double initNum)
    :row(row), column(column), mat(row * column, initNum)
{

}

Matrix::Matrix(const Matrix &origin)
    :row(origin.row), column(origin.column),
      mat(origin.mat)
{

}

double &Matrix::operator()(size_t i, size_t j)
{
    assert(i < row);
    assert(j < column);

    return mat[i * column + j];
}

double Matrix::operator()(size_t i, size_t j) const
{
    assert(i < row);
    assert(j < column);

    return mat[i * column + j];
}
Matrix Matrix::operator+(const Matrix &rhs) const
{
    assert(row == rhs.row);
    assert(column == rhs.column);
    Matrix result(row, column);
    transform(mat.begin(), mat.end(), rhs.mat.begin(), result.mat.begin(),
              [](const double lhs, const double rhs) {return lhs + rhs;});

    return result;
}

Matrix Matrix::operator-(const Matrix &rhs) const
{
    assert(row == rhs.row);
    assert(column == rhs.column);
    Matrix result(row, column);
    transform(mat.begin(), mat.end(), rhs.mat.begin(), result.mat.begin(),
              [](const double lhs, const double rhs)->double {return lhs - rhs;});

    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const
{
    assert(column == rhs.row);
    Matrix result(row, rhs.column);
    for (int i = 0; i < result.row; ++i) {
        for (int j = 0; j < result.column; ++j)
            for (int k = 0; k < this->column; ++k)
                result(i, j) += this->operator ()(i, k) * rhs(k, j);
     }

    return result;
}

Matrix Matrix::operator*(const double c) const
{
    Matrix result(row, column);
    transform(mat.begin(), mat.end(), result.mat.begin(),
              [c](const double unitInVector) {return c * unitInVector;});
    return result;
}

bool Matrix::operator==(const Matrix &rhs) const
{
    bool rowEqual = (row == rhs.row);
    bool columnEqual = (column == rhs.column);
    bool matEqual = (mat == rhs.mat);
    return rowEqual && columnEqual && matEqual;
}

double Matrix::innerProduct(const Matrix &rhs)
{
    assert(this->row == 1 || this->column == 1);
    assert(this->row == rhs.row && this->column == rhs.column);

    double sum = inner_product(this->mat.begin(), this->mat.end(),
                              rhs.mat.begin(), 0.0);
    return sum;
}

Matrix Matrix::merge(const Matrix &rhs, int axis, bool inplace)
{
    // check the limit condition
    assert(axis == 0 || axis == 1);
    if (axis == 1) {
        assert(row == rhs.row);
    }
    else {
        assert(column == rhs.column);
    }

    // Matrix merge it self inplace
    Matrix rhsCopy(0, 0);
    const Matrix *rhsPtr = nullptr;
    if (this == &rhs && inplace) {
        rhsCopy = rhs;
        rhsPtr = &rhsCopy;
    }
    else {
        rhsPtr = &rhs;
    }

    // inplace? initialize result matrix
    Matrix copyMatrix(0, 0);
    Matrix *result = nullptr;
    if (inplace)
        result = this;
    else {
        copyMatrix = *this;
        result = &copyMatrix;
    }

    result->mat.reserve(row * column + rhsPtr->row * rhsPtr->column);
    if (axis == 1) {
        result->column += rhsPtr->column;
        int insertPosition = -static_cast<int>(rhsPtr->column);
        for (int i = 0; i < row; ++i) {
            auto sourceStart = rhsPtr->mat.begin() + i * rhsPtr->column;
            auto sourceEnd = sourceStart + rhsPtr->column;
            insertPosition += static_cast<int>(result->column);
            auto destStart = result->mat.begin() + insertPosition;
            result->mat.insert(destStart, sourceStart, sourceEnd);
        }
    }
    else {
        auto sourceStart = rhsPtr->mat.begin();
        auto sourceEnd = rhsPtr->mat.end();
        auto destStart = result->mat.begin() + result->row * result->column;
        result->mat.insert(destStart, sourceStart, sourceEnd);
        result->row += rhsPtr->row;
    }
    if (inplace)
        return Matrix();
    else
        return *result;
}

Matrix Matrix::merge(const Matrix &rhs, int axis) const
{
    return const_cast<Matrix *>(this)->merge(rhs, axis, false);
}
Matrix Matrix::splice(size_t start, size_t end, int axis, bool inplace)
{
    // assert base condition
    assert(axis == 0 || axis == 1);
    assert(start >= 0 && start < end);
    if (axis == 1) {
        assert(end <= column);
    }
    else {
        assert(end <= row);
    }

    // put number in result
    Matrix result;
    if (axis == 1) {
        result.row = row;
        result.column = end - start;
        result.mat.reserve(result.column * result.row);
        for (auto i = start; i < end; ++i) {
            for (decltype(row) j = 0; j < row; ++j) {
                result.mat.insert(result.mat.end(), this->operator ()(j, i));
            }
        }
    }
    else {
        result.row = end - start;
        result.column = column;
        result.mat.reserve(result.column * result.row);
        auto sourceStart = mat.begin() + start * column;
        auto sourceEnd = sourceStart + result.row * column;
        result.mat.insert(result.mat.end(), sourceStart, sourceEnd);
    }

    // inplace ?
    if (inplace) {
        *this = result;
        return Matrix();
    }
    else
        return result;

}

Matrix Matrix::splice(size_t start, size_t end, int axis) const
{
    Matrix *matrixPtr = const_cast<Matrix *>(this);
    return matrixPtr->splice(start, end, axis, false);
}

Matrix Matrix::reverse(bool inplace)
{
    Matrix result(this->column, this->row);
    for (decltype(result.row) i = 0; i < result.row; ++i) {
        for (decltype(result.row) j = 0; j < result.column; ++j) {
            result(i, j) = this->operator ()(j, i);
        }
    }

    if (inplace) {
        *this = result;
        return Matrix();
    }
    else
        return result;
}

Matrix Matrix::reverse() const
{
    Matrix result = const_cast<Matrix *>(this)->reverse(false);
    return result;
}

Matrix Matrix::dotProduct(const Matrix &rhs)
{
    assert(this->row== rhs.row);
    assert(this->column == rhs.column);

    Matrix result(this->row, this->column);
    transform(this->mat.begin(), this->mat.end(), rhs.mat.begin(), result.mat.begin(),
              [](double left, double right) {return left * right;});
    return result;
}

Matrix Matrix::sign(bool inplace)
{
    Matrix result(*this);
    for_each(result.mat.begin(), result.mat.end(), [](double &unit) {unit = unit > 0 ? 1 : -1;});

    if (inplace) {
        *this = result;
        return Matrix();
    }
    else
        return result;
}

Matrix Matrix::abs(bool inplace)
{
    Matrix result(*this);
    for_each(result.mat.begin(), result.mat.end(), [](double &unit) {unit = unit > 0 ? unit : -unit;});

    if (inplace) {
        *this = result;
        return Matrix();
    }
    else
        return result;
}
Matrix Matrix::square(bool inplace)
{
    Matrix result(*this);
    for_each(result.mat.begin(), result.mat.end(), [](double &unit) {unit = unit * unit;});

    if (inplace) {
        *this = result;
        return Matrix();
    }
    else
        return result;
}

double Matrix::sum()
{
    double sum = accumulate(mat.begin(), mat.end(), 0.0);
    return sum;
}

double Matrix::max()
{
    double max = 0;
    for_each(mat.begin(), mat.end(),
             [&](double current) {max = max > current ? max : current;});
    return max;
}

vector<Matrix> Matrix::splictRow() const
{
    vector<Matrix> matrixVec(this->row);
    for (decltype(this->row) i = 0; i < this->row; ++i) {
        matrixVec[i] = this->splice(i, i + 1, 0);
    }
    return matrixVec;
}

double Matrix::toDouble() const
{
    assert(row == 1 && column == 1);
    return mat[0];
}

vector<vector<double>> Matrix::distinctColumn() const
{
    vector<vector<double>> result(column);
    for (size_type i = 0; i < column; ++i) {
        set<double> distinct;
        for (size_type j = 0; j < row; ++j) {
            distinct.insert(this->operator ()(j, i));
        }
        result[i].assign(distinct.begin(), distinct.end());
    }
    return result;
}

Matrix operator*(const double c, const Matrix &lhs)
{
    Matrix result(lhs * c);
    return result;
}

ostream &operator<<(ostream &out, Matrix &m)
{
    for (int i = 0; i < m.rowSize(); ++i) {
        for (int j = 0; j < m.columnSize(); ++j)
            out << m(i, j) << '\t';
        out << endl;
    }
    return out;
}

ostream &operator<<(ostream &out, vector<vector<double>> vV)
{
    for (auto &v : vV) {
        for (auto cell : v)
            out << cell << '\t';
        out << endl;
    }
    return out;
}
// ------------------------------------------ naivebayes.cpp
#include "naivebayes.h"

NaiveBayes::NaiveBayes(int lambda)
    :lambda(lambda)
{

}

NaiveBayes::~NaiveBayes()
{

}

void NaiveBayes::train(const Matrix &X, const Matrix &y)
{
    // clear last data
    labelDistinct.clear();
    attributeUniqueNumber.clear();
    labelProbability.clear();
    attributeProbability.clear();

    // y distinct
    vector<double> labels;
    for (Matrix::size_type i = 0; i < y.rowSize(); ++i) {
        labels.push_back(y(i, 0));
    }
    sort(labels.begin(), labels.end());
    unique_copy(labels.begin(), labels.end(), back_inserter(labelDistinct));
#ifdef DEBUG
    cout << "all labels" << endl;
    for (auto label : labels)
        cout << label << '\t';
    cout << endl;

    cout << "distinct labels" << endl;
    for (auto label : labelDistinct)
        cout << label << '\t';
    cout << endl << endl;
#endif

    // calculate labelPro
    auto N = y.rowSize();
    double yDistinct = static_cast<double>(y.distinctColumn()[0].size());
    for (auto yEach : labelDistinct) {
        auto range = equal_range(labels.begin(), labels.end(), yEach);
        auto yCount = range.second - range.first;
        labelProbability[yEach] = (yCount + lambda) / (static_cast<double>(N) + yDistinct * lambda);
#ifdef DEBUG
        cout << "y = " << yEach << " ";
        cout << "labelPro = " << labelProbability[yEach] << endl;
#endif
    }

    // calculate distinct number of attribute in each column
    vector<vector<double>> distinctAttribute = X.distinctColumn();
    attributeUniqueNumber.resize(X.columnSize());
    transform(distinctAttribute.begin(), distinctAttribute.end(), attributeUniqueNumber.begin(),
              [](const vector<double> &distinctUnit) {return distinctUnit.size();});
#ifdef DEBUG
    for (auto &distinctNumber : attributeUniqueNumber)
        cout << distinctNumber << '\t';
    cout << endl;
#endif

    // attributeProbability
    vector<Matrix> trainVec = X.merge(y, 1).splictRow();
    for (auto yEach : labelDistinct) {
#ifdef DEBUG
        cout << "y = " << yEach << endl;
#endif
        attributeProbability[yEach].resize(X.columnSize());
        auto partitionIter = partition(trainVec.begin(), trainVec.end(),
                  [=](const Matrix &m) {return m(0, m.columnSize() - 1) == yEach;});
        auto xWithSameY = partitionIter - trainVec.begin();
        vector<vector<double>> attributes(X.columnSize());
        for (vector<Matrix>::iterator it = trainVec.begin(); it != partitionIter; ++it) {
            for (Matrix::size_type col = 0; col < it->columnSize() - 1; ++col) {
                attributes[col].push_back(it->operator()(0, col));
            }
        }
        for (auto i = 0; i < attributes.size(); ++i) {
            vector<double> columnEach = attributes[i];
            sort(columnEach.begin(), columnEach.end());
            vector<double> columnDistinct;
            unique_copy(columnEach.begin(), columnEach.end(), back_inserter(columnDistinct));
            for (double &attributeEach : columnDistinct) {
                auto range = equal_range(columnEach.begin(), columnEach.end(), attributeEach);
                auto xCount = range.second - range.first;
                attributeProbability[yEach][i][attributeEach] =
                        (xCount + lambda) / (static_cast<double>(xWithSameY) + attributeUniqueNumber[i] * lambda);
#ifdef DEBUG
                cout << "y = " << yEach << " " << i << "th column ";
                cout << " attribute = " << attributeEach ;
                cout << " attributePro = " << xCount / static_cast<double>(xWithSameY) << endl;
#endif
            }
        }
    }

}

Matrix NaiveBayes::predict(const Matrix &X)
{
#ifdef DEBUG
    cout << endl << "Start predicting..." << endl;
#endif
    Matrix result(X.rowSize(), 1);

    for (auto i = 0; i < X.rowSize(); ++i) {
        vector<pair<double, double>> yAndProb;
        for (auto label : labelDistinct) {
            double Py = labelProbability[label];
#ifdef DEBUG
            cout << endl;
            cout << "label = " << label <<" Py = " << Py << endl;
#endif
            double PxTotal = 1;
            for (auto j = 0; j < X.columnSize(); ++j) {
                double attribute = X(i, j);
                double PxSingle;
                double Sj = attributeUniqueNumber[j];
                auto &proMap = attributeProbability[label][j];
                if (proMap.find(attribute) == proMap.end()) {
                    PxSingle = 1 / Sj;
                }
                else {
                    PxSingle = proMap[attribute];
                }
                PxTotal *= PxSingle;
#ifdef DEBUG
                cout << "attribute = " << attribute;
                cout << " PxSingle = " << PxSingle ;
                cout << endl;
#endif
            }
            yAndProb.push_back({label, PxTotal * Py});
        }
        nth_element(yAndProb.begin(), yAndProb.begin(), yAndProb.end(),
             [](const pair<double, double> &lhs, const pair<double, double> &rhs)
             {return lhs.second > rhs.second;});
        result(i, 0) = yAndProb[0].first;
#ifdef DEBUG
        cout << endl;
        for (auto &pairOfYAndProb : yAndProb)
            cout << "label = " << pairOfYAndProb.first << " Prob = " << pairOfYAndProb.second << endl;
#endif
    }

    return result;
}
// ---------------------------------------- perceptron.cpp

#include "perceptron.h"

Perceptron::Perceptron(double learningRate, int iterationMax,
                       Algorithm algorithmUse)
    :learningRate(learningRate),
      iterationMax(iterationMax),
      algorithmUse(algorithmUse)
{
}

void Perceptron::train(const Matrix &X, const Matrix &y)
{
    // basic condition
    assert(X.rowSize() > 0);
    assert(X.rowSize() == y.rowSize());
    assert(X.columnSize() > 0);

    if (algorithmUse == Algorithm::Origin) {
        //add intercept, column of ones
        Matrix Xtrain(X.rowSize(), 1, 1);
        Xtrain.merge(X, 1, true);
        default_random_engine randomEngin;
        uniform_int_distribution<Matrix::size_type> uniDistri(0, Xtrain.rowSize() - 1);

        weight = Matrix(Xtrain.columnSize(), 1, 0);
        for (int i = 0; i < iterationMax; ++i) {
            auto xTrainIndex = uniDistri(randomEngin);
            auto xSingle = Xtrain.splice(xTrainIndex, xTrainIndex + 1, 0);
            auto ySingle = y(xTrainIndex, 0);
            double yPredictSingle = xSingle.reverse().innerProduct(weight) * ySingle;
            if (yPredictSingle <= 0) {
                Matrix delta = learningRate * ySingle * xSingle;
                delta.reverse(true);
                weight = weight + delta;
            }
        }

    }
    else {
        Matrix Xtrain(X);
        default_random_engine randomEngin;
        uniform_int_distribution<Matrix::size_type> uniDistri(0, Xtrain.rowSize() - 1);

        Matrix alpha = Matrix(Xtrain.rowSize(), 1);
        double b = 0;
        Matrix Gram = Xtrain * Xtrain.reverse();
        for (int i = 0; i < iterationMax; ++i) {
            auto xTrainIndex = uniDistri(randomEngin);
            auto xSingleGram = Gram.splice(xTrainIndex, xTrainIndex + 1, 1);
            auto ySingle = y(xTrainIndex, 0);
            double yPredictSingle = (alpha.dotProduct(y).innerProduct(xSingleGram) + b) * ySingle;
            if (yPredictSingle <= 0) {
                alpha(xTrainIndex, 0) = alpha(xTrainIndex, 0) = 1;
                b = b + learningRate * ySingle;
            }
        }
        auto weightLast = alpha.dotProduct(y).reverse() * Xtrain;
        weight = Matrix(1, 1, b);
        weight.merge(weightLast.reverse(), 0, true);
    }
}

Matrix Perceptron::predict(const Matrix &X) const
{ 
    Matrix Xtrain(X.rowSize(), 1, 1);
    Xtrain.merge(X, 1, true);
    assert(Xtrain.columnSize() == weight.rowSize());
    Matrix yPredict = Xtrain * weight;
    yPredict.sign(true);
    return yPredict;
}

Matrix Perceptron::getWeight() const
{
    return weight;

}