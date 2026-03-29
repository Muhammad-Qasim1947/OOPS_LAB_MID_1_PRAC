// You are tasked with designing a Bank Account
// Management System where each account is
// assigned a unique account number that
// automatically increments when a new account is
// created. The bank also requires a way to track the
// total number of active accounts at any given
// time.
// To ensure security and data integrity:
// • The bank name should remain constant for all
// accounts.
// • The account number, once assigned, should not
// be modified.
// • The system must efficiently manage account
// creation and deletion while keeping track of
// active accounts.
// • Objects should be dynamically allocated and
// managed efficiently.
// Requirements:
// ● Account Creation:
// o Create an account with a unique number and an initial balance of zero.
// o Ensure that each new account is assigned a unique, auto-incremented account number that is immutable.
// ● Active Account Tracking:
// o Properly track the total number of active accounts.
// o Provide a method to retrieve the current count of active accounts.
// ● Memory Management:
// o Dynamically allocate account objects using references.
// o Ensure proper deletion of account objects to avoid memory leaks.
// ● Account Details and Operations:
// o Implement functionality to display account details, including the account number, balance, and bank name.
// o Provide deposit and withdrawal functionalities that update the account balance accordingly (utilizing
// references where applicable).
// Implement your solution in C++ and thoroughly test it by simulating account creation and deletion. Ensure that the total
// active account count updates correctly after each operation and that all dynamically allocated memory is efficiently
// managed

#include <iostream>
using namespace std;

class account
{
private:
    const int account_num;
    float balance;
    static int next_account_num;
    static int active_accounts;
    const string bankname = "HBL";

public:
    account() : account_num(next_account_num), balance(0)
    {
        next_account_num++;
        active_accounts++;
        cout << "Account Created With Account Number : " << account_num << endl;
    }

    ~account()
    {
        active_accounts--;
        cout << "Account Deleted : " << account_num << endl;
    }

    void deposit(float deposit)
    {
        if (deposit < 0)
        {
            cout << "Balance Cannot Be Less Than Zero" << endl;
        }
        else
        {
            balance = balance + deposit;
            cout << "Balance " << balance << " Has Been Deposited In Your Account" << endl;
        }
    }

    void withdraw(float withdraw)
    {
        if (withdraw > balance)
        {
            cout << "Not Enough Balance" << endl;
        }
        else
        {
            balance = balance - withdraw;
            cout << "Amount Of " << withdraw << " Has Been Withdraw" << endl;
        }
    }

    void display() const
    {
        cout << "\n-------Account Details-------" << endl;
        cout << "Bank : " << bankname << endl;
        cout << "Account Number : " << account_num << endl;
        cout << "Balance : " << balance << endl;
    }

    static int getactiveaccounts()
    {
        return active_accounts;
    }
};

int account ::next_account_num = 1001;
int account ::active_accounts = 0;

int main()
{
    account *acc1 = new account();
    account *acc2 = new account();

    float amount1 = 500;
    acc1->deposit(amount1);

    float amount2 = 1000;
    acc2->deposit(amount2);

    float withdrawl1 = 100;
    acc1->withdraw(withdrawl1);

    float withdrawl2 = 150;
    acc2->withdraw(withdrawl2);

    acc1->display();
    acc2->display();

    cout << "\nTotal Active Accounts: " << account::getactiveaccounts() << endl;

    cout << endl ;

    delete acc1;
    delete acc2;

    cout << endl ;

    cout << "Total Active Account After Deletion : " << account::getactiveaccounts() << endl;

    return 0;
}
