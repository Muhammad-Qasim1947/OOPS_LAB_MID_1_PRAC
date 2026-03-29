// You are tasked with designing an F1 Racing Team Management System that efficiently manages different types of team
// members, such as Drivers and Engineers. Since all team members share common attributes, your implementation should
// avoid redundancy.
// Your system should:
// 1. Manage team members, ensuring each has a unique identifier and an unchangeable name.
// 2. Differentiate between roles, such as Drivers (who have a car number and track race wins) and Engineers (who have a
// specialization).
// 3. Enforce structured behavior, ensuring that every team member can display their details appropriately.
// 4. Efficiently allocate and deallocate memory, properly managing dynamically created objects.
// 5. Demonstrate move semantics by utilizing move constructors where appropriate to ensure efficient object transfers.
// Think About:
// a. How does inheritance help in reducing redundancy when managing different team members?
// b. How can you ensure that every team member has a unique and immutable ID?
// c. What mechanism will enforce that all team members implement a function to display their details?
// d. How should memory be handled when objects are dynamically allocated?
// Implement your solution in C++ and validate it by simulating multiple drivers and engineers, tracking their details, and
// ensuring memory is properly managed. Use comments in your code to explain how inheritance reduces redundancy and
// improves maintainability. Also create an object an move an original object details to another while also deleting the old
// object.

#include <iostream>
using namespace std;

class teammembers
{
public:
    const int id;
    const string name;
    static int total_members;
    static int next_id;

    teammembers(string n = "N/A") : id(next_id), name(n)
    {
        next_id++;
        total_members++;
    }

    virtual ~teammembers()
    {
        total_members--;
    }

    static int get_total_members()
    {
        return total_members;
    }

    virtual void display() const
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
    }
};

int teammembers ::total_members = 0;
int teammembers ::next_id = 1001;

class drivers : public teammembers
{
public:
    int carnumber;
    int race_wins;
    static int totaldrivers;

    drivers(string n, int carnum, int rw) : teammembers(n), carnumber(carnum), race_wins(rw)
    {
        totaldrivers++;
    }

    void display() const
    {
        cout << "-----Drivers Details-----" << endl;
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Car Number : " << carnumber << endl ;
    }

    ~drivers()
    {
        totaldrivers--;
        cout << "Driver Removed With ID : " << id << endl;
    }

    static int get_totaldrivers()
    {
        return totaldrivers;
    }
};

int drivers ::totaldrivers = 0;

class engineers : public teammembers
{
public:
    string specialization;
    static int total_engineers;

    engineers(string n, string skill) : teammembers(n), specialization(skill)
    {
        total_engineers++;
    }

    ~engineers()
    {
        total_engineers--;
        cout << "Engineer Removed With ID : " << id << endl;
    }

    static int get_totalengineers()
    {
        return total_engineers;
    }

    void display() const
    {
        cout << "-----Engineers Details-----" << endl;
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Specialization : " << specialization << endl;
    }
};

int engineers ::total_engineers = 0;

int main()
{
    teammembers *tm1 = new drivers("Qasim", 995, 9);
    teammembers *tm2 = new engineers("YASH", "Engine Specialist");

    cout << endl;

    tm1->display();
    cout << endl;
    tm2->display();

    cout << endl;
    cout << "Total Members : " << teammembers::get_total_members() << endl;
    cout << "Total Engineers : " << engineers ::get_totalengineers() << endl;
    cout << "Total Drivers : " << drivers ::get_totaldrivers() << endl;
    cout << endl;

    delete tm1;
    delete tm2;

    cout << endl;
    cout << "Total Members After : " << teammembers::get_total_members() << endl;
    cout << "Total Engineers After : " << engineers ::get_totalengineers() << endl;
    cout << "Total Drivers After : " << drivers ::get_totaldrivers() << endl;
    cout << endl;

    return 0;
}