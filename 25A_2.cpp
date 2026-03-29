// Q2. [16 marks | 8 weightage]
// You are tasked with designing an Office Management System that keeps track of Employees and their respective
// Departments. Each employee belongs to a department, establishing a Has-a relationship between the Employee and
// Department classes.
// Your implementation should allow:
// Tracking Departments:
// Ensure that each department has a unique name.
// Provide a mechanism to monitor the total number of departments created.
// Managing Employees:
// Assign every employee a unique identifier that automatically increments.
// Ensure that each employee's name is immutable once set.
// Guarantee that an employee is permanently assigned to a specific department upon creation.
// Efficient Memory Management:
// Dynamically allocate memory for employee and department objects.
// Properly deallocate memory when objects are no longer needed, ensuring no memory leaks occur.
// Ensuring Constraints:
// The employee's department assignment should be fixed upon creation and not modifiable.
// The system should dynamically track the total number of employees and departments.
// Considerations:
// How will you ensure that each employee has a unique ID that automatically increments?
// How can the system track the number of departments and employees dynamically?
// What is the best way to establish a Has-a relationship between employees and departments?
// How will you prevent modifications to an employee’s name or department after they are assigned?
// What mechanisms should be in place to properly allocate and free memory when objects are created and deleted?
// Implement your solution in C++ and test it by creating multiple employees and departments, verifying that the total count
// for each is updated correctly, and ensuring that memory is managed efficiently

#include <iostream>
using namespace std;

class departments
{
private:
    const string dept_name;
    static int total_depts;

public:
    departments(string n) : dept_name(n)
    {
        total_depts++;
        cout << "Department Created : " << dept_name << endl;
    }

    ~departments()
    {
        total_depts--;
        cout << endl ;
        cout << "Department Removed : " << dept_name << endl;
    }

    string getdeptname() const
    {
        return dept_name;
    }
    static int get_total_depts()
    {
        return total_depts;
    }
};

int departments :: total_depts = 0 ;

class employee
{
private:
    const int id;
    static int next_id;
    const string emp_name;
    static int total_emps;
    departments *depts;

public:
    employee(string emp_n, departments *d) : emp_name(emp_n), id(next_id), depts(d)
    {
        next_id++;
        total_emps++;
        cout << "-----Employee Added-----" << endl;
        cout << "ID : " << id << endl;
        cout << "Department : " << depts->getdeptname() << endl;
    }

    ~employee()
    {
        total_emps--;
        cout << endl;
        cout << "-----Employee Removed-----" << endl;
        cout << "ID : " << id << endl;
    }

    void display() const
    {
        cout << "ID: " << id << "\nName: " << emp_name
             << "\nDepartment: " << depts->getdeptname() << endl;
    }

    static int get_total_employees()
    {
        return total_emps;
    }
};

int employee ::total_emps = 0;
int employee ::next_id = 1001;

int main()
{
    departments *d1 = new departments("HR");
    departments *d2 = new departments("Manager");

    cout << "\nTotal Departments: " << departments::get_total_depts() << endl;

    employee *e1 = new employee("Yash", d1);
    employee *e2 = new employee("Qasim", d2);
    employee *e3 = new employee("Mahboor", d1);

    e1->display();
    e2->display();
    e3->display();

    delete e1;
    delete e2;
    delete e3;

    delete d1;
    delete d2;

    cout << "\nAfter deletion:" << endl;
    cout << "Total Employees: " << employee::get_total_employees() << endl;
    cout << "Total Departments: " << departments::get_total_depts() << endl;

    return 0;
}