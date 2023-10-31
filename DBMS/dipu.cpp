#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

class Student
{
public:
  string name;
  int student_id;
  string major;

  Student(const string &name, int student_id, const string &major) : name(name), student_id(student_id), major(major) {}
};

class Database
{
public:
  Database() {}

  void create_student(const Student &student)
  {
    ofstream file("students.txt", ios::app);
    if (!file.is_open())
    {
      throw std::runtime_error("Unable to open file for writing.");
    }
    file << student.name << "," << student.student_id << "," << student.major << endl;
    file.close();
  }

  Student read_student(int student_id)
  {
    ifstream file("students.txt");
    if (!file.is_open())
    {
      throw std::runtime_error("Unable to open file for reading.");
    }

    string line;
    while (getline(file, line))
    {
      vector<string> tokens = split(line, ',');
      if (stoi(tokens[1]) == student_id)
      {
        file.close();
        return Student(tokens[0], stoi(tokens[1]), tokens[2]);
      }
    }
    file.close();
    throw std::runtime_error("Student not found");
  }

  void update_student(const Student &student)
  {
    // Implement the update_student function.
  }

  void delete_student(int student_id)
  {
    // Implement the delete_student function.
  }

private:
  vector<Student> students;

  vector<string> split(const string &s, char delimiter)
  {
    vector<string> tokens;
    istringstream tokenStream(s);
    string token;
    while (getline(tokenStream, token, delimiter))
    {
      tokens.push_back(token);
    }
    return tokens;
  }
};

int main()
{
  Database database;

  // Create a new student
  Student student1("Alice", 12345, "Computer Science");
  database.create_student(student1);

  // Read a student record
  Student retrievedStudent = database.read_student(12345);
  cout << retrievedStudent.name << ", " << retrievedStudent.student_id << ", " << retrievedStudent.major << endl;

  // Update a student record
  retrievedStudent.major = "Mathematics";
  database.update_student(retrievedStudent);

  // Delete a student record
  database.delete_student(12345);

  return 0;
}
