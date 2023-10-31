#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Define the Student structure
struct Student
{
    int studentID;
    string name;
    double grade;
    string address;
};

// Function to add a new student
void addStudent(vector<Student> students)
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

    // Store the user data in a structured file format (e.g., CSV)
    ofstream userFile("users.csv", ios::app);
    userFile << student.studentID << "," << student.name << "," << student.grade << "," << student.address << endl;
    userFile.close();

    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No students in the database." << endl;
        return;
    }

    for (const Student &student : students)
    {
        cout << "ID: " << student.studentID << " | Name: " << student.name
             << " | Grade: " << student.grade << " | Address: " << student.address << endl;
    }
}

// Function to search for a student by name
void searchStudentByName(const vector<Student> &students)
{
    string searchName;
    cout << "Enter the name to search for: ";
    cin.ignore(); // Clear the newline character
    getline(cin, searchName);

    vector<Student> matchingStudents;
    for (const Student &student : students)
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
        cout << "Matching Students:" << endl;
        displayStudents(matchingStudents);
    }
}

// Function to load student data from a file
void loadStudentsFromFile(vector<Student> &students)
{
    ifstream userFile("users.csv");
    if (userFile.is_open())
    {
        string line;
        while (getline(userFile, line))
        {
            Student student;
            // Assuming the CSV format is: ID,Name,Grade,Address
            sscanf(line.c_str(), "%d,%[^,],%lf,%[^,]", &student.studentID, &student.name[0], &student.grade, &student.address[0]);
            students.push_back(student);
        }
        userFile.close();
    }
}

// Function to save student data to a file
void saveStudentsToFile(const vector<Student> &students)
{
    ofstream userFile("users.csv");
    if (userFile.is_open())
    {
        for (const Student &student : students)
        {
            userFile << student.studentID << "," << student.name << "," << student.grade << "," << student.address << endl;
        }
        userFile.close();
    }
}

int main()
{
    // Load existing student data from the file (if any)
    vector<Student> students;
    loadStudentsFromFile(students);

    char choice;

    while (true)
    {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
            // Save student data to the file when exiting the program
            saveStudentsToFile(students);
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
