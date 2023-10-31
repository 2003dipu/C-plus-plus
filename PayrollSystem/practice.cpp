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
void addEmployee(vector<Employee> &employees)
{
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
}

// Function to display employee information
void displayEmployees(const vector<Employee> &employees)
{
    if (employees.empty())
    {
        cout << "\nNo employees in the system." << endl;
    }
    else
    {
        cout << "\nEmployee List:\n=====================================\n";
        for (const Employee &employee : employees)
        {
            cout << "Name: " << employee.name << endl;
            cout << "Employee ID: " << employee.employeeID << endl;
            cout << "Hourly Rate: " << employee.hourlyRate << endl;
            cout << "Hours Worked: " << employee.hoursWorked << endl;
            cout << "Total Salary: " << employee.totalSalary << endl;
            cout << "-------------------------\n";
        }
        cout << "=====================================\n";
    }
}

int main()
{
    vector<Employee> employees;

    bool continueRunning = true;
    while (continueRunning)
    {
        cout << "\nPayroll System Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            displayEmployees(employees);
            break;
        case 3:
            continueRunning = false;
            cout << "Exiting the Payroll System. Goodbye Dear!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
