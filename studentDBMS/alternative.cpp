/*! Implementing a complete student database management system in C++ is a substantial project. Here, I'll provide
 you with a simplified console-based example to get you started. Please note that this example doesn't include
 advanced error handling, data validation, or file storage. It's meant to give you a basic structure
 to build upon.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define the Student structure
struct Student
{
    double studentID;
    string name;
    double grade;
    string address;
};

// Function to add a new student
void addStudent(vector<Student> &students)
{
    Student student;
    cout << "Enter Student ID: ";
    cin >> student.studentID;
    cin.ignore(); // Clear the newline character
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Grade: ";
    cin >> student.grade;
    cin.ignore(); // Clear the newline character
    cout << "Enter Address: ";
    getline(cin, student.address);

    students.push_back(student);
    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents(vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No students in the database." << endl;
        return;
    }

    cout << "\n\n";
    for (Student &student : students)
    {
        cout << "ID: " << student.studentID << " | Name: " << student.name
             << " | Grade: " << student.grade << " | Address: " << student.address << endl;
    }
}

// Function to search for a student by name
void searchStudentByName(vector<Student> &students)
{
    string searchName;
    cout << "Enter the name to search for: ";
    cin.ignore(); // Clear the newline character
    getline(cin, searchName);

    vector<Student> matchingStudents;
    for (Student &student : students)
    {
        if (student.name.find(searchName) != string::npos)
        {
            matchingStudents.push_back(student);
        }
    }

    if (matchingStudents.empty())
    {
        cout << "No matching students found." << endl;
    }
    else
    {
        cout << "\nMatching Students:" << endl;
        displayStudents(matchingStudents);
    }
}

int main()
{
    cout << "\n\nProject Name: Students DBMS\n";
    vector<Student> students;
    char choice;

    while (true)
    {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search by Name\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addStudent(students);
            break;
        case '2':
            displayStudents(students);
            break;
        case '3':
            searchStudentByName(students);
            break;
        case '4':
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    cout << "\n\n";

    return 0;
}
/*
This is a basic console-based student database management system. It allows you to add students, display all
students, and search for students by name. You can extend and improve this system by adding features like
data validation, file storage, editing and deleting records, and sorting the student list.
*/