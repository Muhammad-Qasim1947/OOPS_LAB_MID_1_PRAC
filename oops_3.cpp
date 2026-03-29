// Q3: Create a home entertainment system management program. Create a base
// class Device with attributes for the device name, power rating (watts), and daily
// usage hours. A derived class EntertainmentRoom manages up to 5 devices,
// calculating total daily energy consumption in kWh.
// Include a Discount class to apply a percentage-based discount to the electricity
// cost. EntertainmentRoom should inherit from Device and Discount, integrating
// features to calculate total cost after discount. Implement displayEnergySummary()
// to show device details, total energy usage, total cost before and after discount, and
// the device consuming the most energy.
// 1. Device Class:
// o name (string): Device name (e.g., &quot;TV&quot;).
// o power (float): Power rating in watts.
// o hours (float): Daily usage in hours.
// 2. EntertainmentRoom Class:
// o deviceCount (int): Number of devices added (max 5).
// o Member Functions:

//  addDevice(Device): Adds a device (max 5).
//  calculateTotalEnergy(): Total energy consumption in kWh.
//  findHighestEnergyDevice(): Returns device consuming most energy.
//  displayEnergySummary(): Displays all device details, total energy,
// total cost before/after discount, and highest-consuming device.

// 3. Discount Class:
// o discountPercentage (float): Discount on electricity cost.
// o Member Function:
//  applyDiscount(float totalCost): Returns cost after discount.

// Assumptions:
//  Electricity cost per kWh = $0.15
// Sample Output:
// Entertainment Room Devices:
// TV: 100W, 6 hours/day
// Gaming Console: 200W, 4 hours/day
// Sound System: 150W, 5 hours/day
// Total Energy Consumption: 4.3 kWh
// Total Cost before discount: $0.65
// Total Cost after discount: $0.55
// Highest Energy Consuming Device: Gaming Console (200W, 4 hours/day)

#include <iostream>
using namespace std;

class device
{
public:
    string name;
    float power;
    float hours;

    device(string n = "N/A", float p = 0, float h = 0) : name(n), power(p), hours(h)
    {
    }

    float getenergy() const
    {
        return (power * hours) / 1000;
    }

    void display() const
    {
        cout << name << " - Power: " << power << " W, Hours: " << hours
             << ", Energy: " << getenergy() << " kWh" << endl;
    }
};

class discount
{
public:
    float discountpercentage;

    discount(float dp) : discountpercentage(dp)
    {
    }

    float applydiscount(float cost) const
    {
        return cost * (1 - discountpercentage);
    }
};

class entertainmentroom : public device, public discount
{
public:
    int devicecount;
    device devices[5];
    float costperkwh;

    entertainmentroom(string n, float p, float h, float cost, float dp) : device("n", p, h), discount(dp), devicecount(0), costperkwh(cost)
    {
    }

    void addDevice(device d)
    {
        if (devicecount < 5)
        {
            devices[devicecount] = d;
            devicecount++;
        }
        else
        {
            cout << "Cannot Add More Than 5 Devices" << endl;
        }
    }

    void calculatetotalenergy() const
    {
        float totalenergy = 0;
        for (int i = 1; i < devicecount; i++)
        {
            totalenergy += devices[i].getenergy();
        }

        float totalcost = totalenergy * costperkwh;
        float cost_after_discount = applydiscount(totalcost);
        cout << "Total Energy Consumed : " << totalenergy << endl;
        cout << "Total Cost : " << totalcost << endl;
        cout << "Total Cost After Discount : " << cost_after_discount << endl;
    }

    void findhighestenergydevice()
    {
        if (devicecount == 0)
        {
            cout << "No Devices Available" << endl;
            return;
        }
        int index = 0;
        float maxenergy = devices[0].getenergy();
        for (int i = 0; i < devicecount; i++)
        {
            if (devices[i].getenergy() > maxenergy)
            {
                maxenergy = devices[i].getenergy();
                index = i;
            }
        }
        cout << "Highest Consuming Device : " << devices[index].name << endl;
    }

    void displayEnergySummary()
    {
        for (int i = 0; i < devicecount; i++)
        {
            devices[i].display();
        }
        calculatetotalenergy();
        findhighestenergydevice();
    }
};

int main()
{
    entertainmentroom room("MyRoom", 0, 0, 0.15, 0.2);

    room.addDevice(device("TV", 150, 5));
    room.addDevice(device("AC", 2000, 3));
    room.addDevice(device("Fridge", 300, 24));

    room.displayEnergySummary();

    return 0 ;
}