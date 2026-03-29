// You are tasked with designing a University Staff Management System that efficiently manages different types of staff
// members, such as Professors and Administrative Staff. Since all staff members share common attributes, your
// implementation should avoid redundancy.
// Your system should:
// 1. Manage staff members, ensuring each has a unique identifier and an unchangeable name.
// 2. Differentiate between staff roles, such as Professors (who have subject specializations) and Administrative Staff (who
// belong to a department).
// 3. Enforce structured behavior, ensuring that every staff member can display their details appropriately.
// 4. Efficiently allocate and deallocate memory, properly managing dynamically created objects.
// 5. Demonstrate move semantics by utilizing move constructors where appropriate.
// Think about:
// a. How does inheritance help in reducing redundancy when dealing with different staff roles?
// b. How can you ensure that every staff member has a unique and immutable staff ID?
// c. What mechanism will enforce that all staff types implement a function to display their details?
// d. How should memory be handled when objects are dynamically allocated?
// Implement your solution in C++ and test it by creating multiple professors and administrative staff members while
// ensuring proper memory management and correct staff count tracking. Use comments in your code to explain how
// inheritance helps in reducing redundancy and improving maintainability. Also create an object an move an original object
// details to another while also deleting the old object..

#include <iostream>
using namespace std;

class staff
{
public:
    const int staff_id;
    const string name;
    static int next_id;
    static int total_staff;

public:
    staff(string n) : name(n), staff_id(next_id)
    {
        next_id++;
        total_staff++;
        cout << "-----Staff Member Added-----" << endl;
        cout << "ID : " << staff_id << endl;
        cout << "Name : " << name << endl;
        cout << endl;
    }

    virtual ~staff()
    {
        total_staff--;
        cout << "-----Staff Deleted-----" << endl;
        cout << "ID : " << staff_id << endl;
    }

    static int get_total_staff()
    {
        return total_staff;
    }

    virtual void display()
    {
        cout << "-----Staff Details-----" << endl;
        cout << "ID : " << staff_id << endl;
        cout << "Name : " << name << endl;
    }
};

int staff ::next_id = 1001;
int staff ::total_staff = 0;

class professor : public staff
{
private:
    string subj_specialization;

public:
    professor(string n, string subject) : staff(n), subj_specialization(subject)
    {
    }

    void display()
    {
        cout << "-----Staff Details-----" << endl;
        cout << "ID : " << staff_id << endl;
        cout << "Name : " << name << endl;
        cout << "Subject : " << subj_specialization << endl;
    }
};

class administrator : public staff
{
private:
    string department;

public:
    administrator(string n, string dept) : staff(n), department(dept)
    {
    }

    void display()
    {
        cout << "-----Staff Details-----" << endl;
        cout << "ID : " << staff_id << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
    }
};

int main()
{
    staff *s1 = new professor("Qasim", "Computer Science");
    staff *s2 = new administrator("Yash", "Cyber");

    cout << endl;

    s1->display();
    cout << endl;
    s2->display();

    cout << "\nTotal Staff: " << staff::get_total_staff() << endl;

    delete s1;
    delete s2;

    cout << "\nTotal Staff: " << staff::get_total_staff() << endl;

    return 0;
}