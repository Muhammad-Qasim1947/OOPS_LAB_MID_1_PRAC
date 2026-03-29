// A smart home company wants to develop a C++ program to monitor electricity usage in houses.
// In this system, each House has a unique house ID and an owner name. Every house contains
// multiple rooms, and each Room contains multiple electrical devices such as lights, fans, or air
// conditioners. Each Device has a device ID, a power rating (in watts), and the number of hours it is
// used per day. The company wants the program to calculate the total daily electricity consumption
// of a house based on the usage of all devices in all rooms. You are required to design three classes
// — House, Room, and Device — using the has-a relationship (composition), where a House
// contains Room objects and a Room contains Device objects. Include constructors to initialize all
// data members. The Device class should have a function to calculate daily energy usage using the
// formula powerRating × hoursUsedPerDay. The Room class should have a function to calculate the
// total energy usage of all its devices, and the House class should have a function to calculate the
// total electricity consumption of the entire house. In the main() function, create at least one House
// object with at least two Room objects, each containing multiple Device objects, and display the
// total daily electricity consumption of the house.

#include <iostream>
using namespace std;

class device
{
private:
    static int next_id;
    float powerating;
    int hoursperday;
    int id;
    static int total_devices;
    string name;

public:
    device()
    {
    }

    device(float pr, int h, string n) : powerating(pr), hoursperday(h), id(next_id), name(n)
    {
        next_id++;
        total_devices++;
    }

    void display()
    {
        cout << "-----Devices-----" << endl;
        cout << "Device Name : " << name << endl;
        cout << "Power Rating : " << powerating << endl;
        cout << "Hours Per Day : " << hoursperday << endl;
    }

    ~device()
    {
        total_devices--;
        cout << "Device Removed With ID : " << id << endl;
    }

    static int get_totaldevices()
    {
        return total_devices;
    }

    int getpowerrating()
    {
        return powerating;
    }

    int gethoursperday()
    {
        return hoursperday;
    }
};

int device ::total_devices = 0;
int device ::next_id = 1001;

class room
{
private:
    device devices[5];
    int roomnumber;
    int devicecount;
    static int total_rooms;

public:
    room()
    {
    }

    room(int rn) : roomnumber(rn)
    {
        devicecount = 0;
        total_rooms++;
    }

    void adddevice(device d)
    {
        if (devicecount >= 5)
        {
            cout << "cannot add more than 5 devices in a room" << endl;
        }
        else
        {
            devices[devicecount] = d;
            devicecount++;
        }
    }

    float total_energy ;

    void total_eletricity_consumption()
    {
        total_energy = 0 ;
        for (int i = 0; i < devicecount; i++)
        {
            total_energy += devices[i].getpowerrating() * devices[i].gethoursperday();
        }

        cout << "Total Energy Consumed By The Devices : " << total_energy << endl;
    }

    ~room()
    {
        total_rooms--;
        cout << "Room Removed With Number : " << roomnumber << endl;
    }

    static int get_totalrooms()
    {
        cout << "Total Rooms : " << total_rooms << endl;
    }

    float get_totalenergy()
    {
        return total_energy;
    }

    void display()
    {
        cout << "-----Room Details-----" << endl;
        cout << "Room Number : " << roomnumber << endl;
        for (int i = 0; i < devicecount; i++)
        {
            devices[i].display();
        }
    }
};

int room ::total_rooms = 0;

class house
{
private:
    int id;
    const string name;
    room rooms[2];
    static int total_house;
    int roomcount;

public:
    house(string n , int i) : id(i), name(n)
    {
        total_house++;
        roomcount = 0;
    }

    void addroom(room r)
    {
        if (roomcount >= 2)
        {
            cout << "This House Cannot Have More Than 2 Rooms" << endl;
        }
        else
        {
            rooms[roomcount] = r;
            roomcount++;
        }
    }

    void total_house_energy_consumed()
    {
        float total_energy = 0;
        for (int i = 0; i < roomcount; i++)
        {
            total_energy += rooms[i].get_totalenergy();
        }
        cout << "Total Energy Consumed In The House : " << total_energy << endl;
    }

    ~house()
    {
        total_house--;
        cout << "Total Houses : " << total_house << endl;
    }

    void display()
    {
        cout << "-----House Details-----" << endl;
        cout << "House Name : " << name << endl;
        cout << "House ID : " << id << endl ;
        for (int i = 0; i < roomcount; i++)
        {
            rooms[i].display();
        }
    }

    static int get_totalhouses()
    {
        return total_house;
    }
};

int house ::total_house = 0;

int main()
{
}