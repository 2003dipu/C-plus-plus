
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to store student data
struct Student
{
    int id;
    string name;
    string address;
    int grade;
};

// Vector to store the student database
vector<Student> students;

// Function to add a new student to the database
void AddStudent(const Student &student)
{
    students.push_back(student);
}

// Function to update an existing student in the database
void UpdateStudent(int id, const Student &student)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students[i] = student;
            return;
        }
    }

    cout << "Student with ID " << id << " not found." << endl;
}

// Function to delete a student from the database
void DeleteStudent(int id)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);
            return;
        }
    }

    cout << "Student with ID " << id << " not found." << endl;
}

// Function to search for a student in the database by name
Student *SearchStudentByName(const string &name)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == name)
        {
            return &students[i];
        }
    }

    return nullptr;
}

// Function to print all students in the database
void PrintStudents()
{
    cout << "Students:" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].id << " " << students[i].name << " " << students[i].address << " " << students[i].grade << endl;
    }
}

int main()
{
    cout << "\n\nProject Name: Students DBMS\n";

    // Add some students to the database
    Student student1 = {1, "Alice", "123 Main Street", 10};
    Student student2 = {2, "Bob", "456 Elm Street", 12};
    Student student3 = {3, "Carol", "789 Oak Street", 14};
    AddStudent(student1);
    AddStudent(student2);
    AddStudent(student3);

    // Update a student in the database
    Student student4 = {3, "Carol", "987 Maple Street", 16};
    UpdateStudent(3, student4);

    // Delete a student from the database
    DeleteStudent(2);

    // Search for a student in the database by name
    Student *student = SearchStudentByName("Carol");
    if (student != nullptr)
    {
        cout << "Student found:" << endl;
        cout << student->id << " " << student->name << " " << student->address << " " << student->grade << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }

    // Print all students in the database
    PrintStudents();

    cout << "\n\n";

    return 0;
}