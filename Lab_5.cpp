// Task 7: Hospital Management
// Objective: Combine static, const, HAS-A, and arrays.

// Requirements:

// 1. Create a Patient class with constant patientID and name.

// 2. Create a Hospital class that:

// o Contains an array of Patient objects

// o Uses a static variable to count total patients

// 3. Add functions to add a new patient and display all patient details.

// 4. Create 3 patients in main() and display the total number of patients.

#include <iostream>
using namespace std;

class patient
{
public:
    int id;
    static int next_id;
    const string name;
    static int total_patients;

    patient(string n) : name(n), id(next_id)
    {
        total_patients++;
        next_id++;
    }

    static int get_totalpatients()
    {
        return total_patients;
    }
};

int patient ::next_id = 1001;
int patient ::total_patients = 0;

class hospital
{
private:
    patient *patients[5];
    int patient_count;
    const string hospitalname;

public:
    hospital(string hn) : hospitalname(hn) , patient_count(0)
    {
    }

    void addpatients(patient *p)
    {
        if (patient_count < 5)
        {
            patients[patient_count] = p;
            patient_count++;
        }
        else
        {
            cout << "Cannot Add More Than 5 Patients" << endl;
        }
    }

    void display() const
    {
        cout << "-----Hospital Details-----" << endl;
        cout << "Hospital Name : " << hospitalname << endl;
        for (int i = 0; i < patient_count; i++)
        {
            cout << endl;
            cout << "Patient ID : " << patients[i]->id << endl;
            cout << "Patient Name : " << patients[i]->name << endl;
        }
        cout << endl ;
        cout << "Total Patients : " << patient::get_totalpatients() << endl;
    }
};

int main()
{
    patient p1("Qasim");
    patient p2("Yash");
    patient p3("Mahboor");

    hospital hosp("Agha Khan") ;

    hosp.addpatients(&p1);
    hosp.addpatients(&p2);
    hosp.addpatients(&p3);

    hosp.display();

    return 0 ;
}