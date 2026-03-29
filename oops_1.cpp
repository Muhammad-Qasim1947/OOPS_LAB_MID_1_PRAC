// Q1: You are asked to design a gym membership system. Each member has a
// constant membership ID, name, and the number of training sessions attended. The
// system should also track shared statistics: the total number of members registered
// and the total number of sessions attended across all members.
// Create a Member class with private data members and public functions. Include a
// parameterized constructor to initialize all attributes using an initializer list and update
// shared statistics. Implement a function to display individual member details, a const
// member function to return the number of sessions attended, and a static function to
// display total members and sessions.
// In main(), create an array of three members with different details, display their
// information in a loop, and finally show the overall statistics.
// Sample Output:
// Member Details:
// ID: 201, Name: Sara Ali, Sessions Attended: 5
// ID: 202, Name: Omar Shah, Sessions Attended: 3
// ID: 203, Name: Aisha Khan, Sessions Attended: 4
// Total Members Registered: 3
// Total Sessions Attended: 12

#include <iostream>
using namespace std;

class member
{
private:
    const int member_id;
    static int next_id;
    const string name;
    int sessions_attended;
    static int total_member_registered;
    static int total_sessions;

public:
    member(string n, int sessions) : name(n), sessions_attended(sessions), member_id(next_id)
    {
        next_id++;
        total_member_registered++;
        total_sessions += sessions_attended;
    }

    void display()
    {
        cout << "ID : " << member_id << ", Name : " << name << ", Sessions Attended : " << sessions_attended << endl;
    }

    static int get_total_members()
    {
        return total_member_registered;
    }

    static int get_total_sessions()
    {
        return total_sessions;
    }
};

int member ::total_member_registered = 0;
int member ::next_id = 201;
int member ::total_sessions = 0;

int main()
{
    member members[3] = {
        member("Sara Ali", 5),
        member("Omar Shah", 3),
        member("Aisha Khan", 4)};

    cout << "Member Details:\n";

    for (int i = 0; i < 3; i++)
    {
        members[i].display();
    }

    cout << "Total Members Registered : " << member::get_total_members() << endl;
    cout << "Total Sessions Attended : " << member::get_total_sessions() << endl;

    return 0;
}