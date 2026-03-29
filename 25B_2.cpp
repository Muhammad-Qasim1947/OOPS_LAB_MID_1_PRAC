// You are tasked with designing a Hospital Doctor Management System that tracks doctors and their assigned departments,
// emphasizing the Has-a relationship between the Doctor and Department classes. Your system should address the following
// requirements:
// 1. Department Management:
// o Ensure each department is uniquely identified.
// o Maintain an up-to-date count of the total number of hospital departments.
// 2. Doctor Management:
// o Automatically assign a unique, auto-incremented doctor ID to every doctor.
// o Ensure each doctor has an immutable name.
// o Associate each doctor permanently with a specific department upon creation (establishing a Has-a
// relationship).
// 3. Memory Management:
// o Dynamically allocate memory for doctor objects when they are added to the system.
// o Properly deallocate memory when a doctor resigns, ensuring no memory leaks occur.
// 4. Data Integrity and Constraints:
// o Enforce that a doctor's name and assigned department cannot be modified after creation.
// o Dynamically update the total count of doctors and departments as changes occur.
// Considerations:
// ● How will you implement an auto-incrementing, immutable doctor ID?
// ● What strategy will you use to dynamically track and update the count of doctors and departments?
// ● How can you enforce the permanent association between a doctor and a department?
// ● What measures will you take to handle memory allocation and deallocation safely?
// Implement your solution in C++ and validate it by simulating various scenarios such as doctor assignments, department
// updates, and doctor resignations. Ensure that all counts update correctly and that memory is managed efficiently.

#include <iostream>
using namespace std;

class department
{
private:
    const string dept_name;
    static int total_depts;

public:
    department(string n) : dept_name(n)
    {
        total_depts++;
    }

    static int get_totaldepts()
    {
        return total_depts;
    }

    void display() const
    {
        cout << "Department Name : " << dept_name << endl;
    }
};

int department ::total_depts = 0;

class doctor
{
private:
    const int id;
    const string doc_name;
    department *dept;
    static int total_doctors;
    static int next_id;

public:
    doctor(string n, department *d) : id(next_id), doc_name(n)
    {
        dept = d;
        total_doctors++;
        next_id++;
    }

    ~doctor()
    {
        cout << "Doctor Removed With ID : " << id << endl;
    }

    static int get_totaldoctors()
    {
        return total_doctors;
    }

    void display() const
    {
        cout << "-----Doctors-----" << endl;
        cout << "ID : " << id << endl;
        cout << "Doctor Name : " << doc_name << endl;
        dept->display();
    }
};

int doctor ::total_doctors = 0;
int doctor ::next_id = 1001;

int main()
{
    department *d1 = new department("Cardio");
    department *d2 = new department("ICU");

    cout << "Total Departmnets : " << department::get_totaldepts() << endl;

    doctor *doc1 = new doctor("Dr.Qasim", d1);
    doctor *doc2 = new doctor("Dr.Yash", d2);
    doctor *doc3 = new doctor("Dr.Mahboor", d1);

    cout << "Total Doctors : " << doctor::get_totaldoctors() << endl;

    cout << endl;
    doc1->display();
    cout << endl;
    doc2->display();
    cout << endl;
    doc3->display();
    cout << endl;

    delete doc1;
    delete doc2;
    delete doc3;

    return 0;
}