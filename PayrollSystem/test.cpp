#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the Employee structure
struct Employee
{
    string name;
    int employeeID;
    double hourlyRate;
    int hoursWorked;
    double totalSalary;
};

// Function to add a new employee to the system
int main()
{
    vector<Employee> employees; // vector is of struct type. This is not a typical vector
    Employee newEmployee;
    cout << "Enter employee name: ";
    getline(cin, newEmployee.name);

    cout << "Enter employee ID: ";
    cin >> newEmployee.employeeID;
    cout << "Enter hourly rate: ";
    cin >> newEmployee.hourlyRate;
    cout << "Enter hours worked: ";
    cin >> newEmployee.hoursWorked;
    newEmployee.totalSalary = newEmployee.hourlyRate * newEmployee.hoursWorked;
    employees.push_back(newEmployee);
    cout << "\nEmployee added to the system." << endl;
    cout << "==========================================\n";
    for (Employee element : employees)
    {
        cout << "Name: " << element.name << endl;
        cout << "Employee ID: " << element.employeeID << endl;
        cout << "Hourly Rate: " << element.hourlyRate << endl;
        cout << "Hours Worked: " << element.hoursWorked << endl;
        cout << "Total Salary: " << element.totalSalary << endl;
        cout << "-------------------------\n";
    }
    cout << "=====================================\n";
    cout << "==========================================\n";
}