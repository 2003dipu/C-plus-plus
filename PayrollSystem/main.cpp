#include <iostream>
#include <vector>
#include <string>

// Define structures for employee and payroll information
struct Employee {
    std::string name;
    int id;
    double hourlyRate;
    double hoursWorked;
};

struct Payroll {
    int employeeId;
    double grossSalary;
    double deductions;
    double netSalary;
};

// Function to calculate and display payroll
Payroll calculatePayroll(const Employee& employee) {
    Payroll payroll;
    payroll.employeeId = employee.id;
    payroll.grossSalary = employee.hourlyRate * employee.hoursWorked;

    // Calculate deductions (e.g., tax, insurance, etc.)
    payroll.deductions = 0.1 * payroll.grossSalary; // Example: 10% deduction

    payroll.netSalary = payroll.grossSalary - payroll.deductions;

    return payroll;
}

int main() {
    std::vector<Employee> employees;
    std::vector<Payroll> payrolls;

    // Example: Add two employees
    employees.push_back({"John Doe", 1, 15.0, 40.0});
    employees.push_back({"Jane Smith", 2, 20.0, 45.0});

    // Calculate and display payroll for each employee
    for (const Employee& employee : employees) {
        Payroll payroll = calculatePayroll(employee);
        payrolls.push_back(payroll);

        std::cout << "Employee Name: " << employee.name << std::endl;
        std::cout << "Gross Salary: $" << payroll.grossSalary << std::endl;
        std::cout << "Deductions: $" << payroll.deductions << std::endl;
        std::cout << "Net Salary: $" << payroll.netSalary << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
