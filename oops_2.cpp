// Q2: Develop a restaurant order management system. The system should manage
// tables, orders assigned to each table, and menu items included in the orders. Each
// table can have up to 4 orders, and each order can contain up to 3 menu items. The
// system should calculate the total bill for each table and display complete details.
// Classes:
// 1. Table Class:
// o tableNumber (int): Table number (e.g., 1).
// o orders[4] (array of Order): Orders placed at the table (max 4).
// o orderCount (int): Current number of orders (max 4).

// o Member Functions:
//  addOrder(Order): Adds an order to the table (max 4).
//  calculateTotalBill(): Returns the total cost of all orders.
//  displayTableInfo(): Displays table number, orders, and total bill.

// 2. Order Class:
// o orderID (int): Unique order ID.
// o items[3] (array of MenuItem): Up to 3 menu items per order.
// o itemCount (int): Number of items in the order.
// o Member Functions:
//  addItem(MenuItem): Adds an item to the order (max 3).
//  calculateOrderTotal(): Returns total cost of the order.

// 3. MenuItem Class:
// o name (string): Item name (e.g., &quot;Burger&quot;).
// o price (float): Price of the item (e.g., 12.5).

// Table 1 Orders:
// Order 101:
// Burger - $12.5
// Fries - $4.0
// Order 102:
// Pizza - $18.0
// Total Bill for Table 1: $34.5

#include <iostream>
using namespace std;

class MenuItem
{
private:
    string item_name;
    float price;
    static int total_items;

public:
    MenuItem(string n = "N/A", float p = 0.00) : item_name(n), price(p)
    {
        total_items++;
    }

    static int get_total_items()
    {
        return total_items;
    }

    float getPrice() const
    {
        return price;
    }

    void display()
    {
        cout << " " << item_name << " - " << price << endl;
    }
};

int MenuItem ::total_items = 0;

class orders
{
private:
    int order_id;
    MenuItem items[3];
    int itemcount;

public:
    orders()
    {
        itemcount = 0;
    }

    orders(int oid) : order_id(oid), itemcount(0)
    {
    }

    void additem(MenuItem mi)
    {
        if (itemcount < 3)
        {
            items[itemcount] = mi;
            itemcount++;
        }
        else
        {
            cout << "Cannot Add More Than 3 Orders" << endl;
        }
    }

    void calculateordertotal()
    {
        float total = 0;
        for (int i = 0; i < itemcount; i++)
        {
            total += items[i].getPrice();
        }
        cout << "Total Payment : " << total << endl;
    }

    int get_order_id()
    {
        return order_id;
    }

    void display()
    {
        cout << "Order " << order_id << ":\n";

        for (int i = 0; i < itemcount; i++)
        {
            items[i].display();
        }

        calculateordertotal();
    }
};

class table
{
private:
    int table_num;
    orders order[4];
    int ordercount;

public:
    table()
    {
        ordercount = 0;
    }

    table(int n) : table_num(n) , ordercount()
    {
    }

    void addorder(orders o)
    {
        if (ordercount < 4)
        {
            order[ordercount] = o;
            ordercount++;
        }
        else
        {
            cout << "You Cannot Place More Than 4 Orders" << endl;
        }
    }

    void displaytableinfo()
    {
        cout << "Table " << table_num << " Orders : " << endl;
        for (int i = 0; i < ordercount; i++)
        {
            order[i].display();
            cout << endl;
        }
    }
};

int main()
{
    table t(1);

    orders o1(101);
    o1.additem(MenuItem("Burger", 500));
    o1.additem(MenuItem("Fries", 200));
    o1.additem(MenuItem("Coke", 100));

    orders o2(102);
    o2.additem(MenuItem("Pizza", 800));
    o2.additem(MenuItem("Garlic Bread", 250));

    t.addorder(o1);
    t.addorder(o2);

    t.displaytableinfo();

    return 0 ;
}