// Q1. [10 marks |5 weightage ]
// You are tasked with designing a Library Book
// Management System that keeps track of the
// library's collection and circulation of books. Each
// book is assigned a unique book ID that
// automatically increments when a new book is
// added, and the system must also track the total
// number of books currently available for
// borrowing.
// Your implementation should:
// 1. Unique Book Identification:
// Automatically assign an immutable,
// incrementing book ID to each new book added to
// the collection.
// 2. Library-wide Consistency: Ensure that
// the library name remains consistent across all
// book records.
// 3. Borrowing and Returns: Allow borrowers to check out and return books, updating each book's availability
// status.
// 4. Efficient Memory Management: Dynamically allocate and deallocate book records as needed, ensuring no
// memory leaks occur.
// 5. Real-time Count Updates: Accurately update the total number of available books when books are added,
// borrowed, or returned.
// Implement your solution in C++ and test it by simulating multiple book additions, checkouts, and returns. Ensure that the
// total available book count updates correctly and that all memory is properly managed.

#include <iostream>
using namespace std;

class book
{
private:
    const int id;
    static int next_id;
    static int total_books;
    const string name;
    bool isavailable;
    static int availablebooks;

public:
    book(string n) : id(next_id), name(n)
    {
        next_id++;
        total_books++;
        availablebooks++;
        isavailable = true;
    }

    void borrow()
    {
        if (isavailable)
        {
            isavailable = false;
            availablebooks--;
            cout << "Book " << name << " Borrowed Successfully" << endl;
        }
        else
        {
            cout << "Book " << name << " Is Not Available" << endl;
        }
    }

    void returnbook()
    {
        if (!isavailable)
        {
            isavailable = true;
            availablebooks++;
            cout << "Book " << name << " Returned Successfully" << endl;
        }
    }

    ~book()
    {
        total_books--;
        if (isavailable)
        {
            availablebooks--;
            cout << "Book " << name << " Removed" << endl;
        }
    }

    static int get_totalbooks()
    {
        return total_books;
    }

    static int get_availablebooks()
    {
        return availablebooks;
    }

    void display(){
        cout << "-----Library-----" << endl ;
        cout << "Book Name : " << name << endl ;
        cout << "Book ID : " << id << endl ;
    }
};

int book ::total_books = 0;
int book ::next_id = 1001;
int book ::availablebooks = 0;

int main()
{
    book *b1 = new book("Chemistry");
    book *b2 = new book("Physics");
    book *b3 = new book("Mathematics");

    cout << "Total Books : " << book::get_totalbooks() << endl;
    cout << "Available Books : " << book::get_availablebooks() << endl;

    b1->display();
    b2->display();
    b3->display();

    b1->borrow();
    b2->borrow();

    cout << "Total Books : " << book::get_totalbooks() << endl;
    cout << "Available Books : " << book::get_availablebooks() << endl;

    b1->returnbook();

    cout << "Total Books : " << book::get_totalbooks() << endl;
    cout << "Available Books : " << book::get_availablebooks() << endl;

    delete b1;
    delete b2;
    delete b3;

    cout << "Total Books : " << book::get_totalbooks() << endl;
    cout << "Available Books : " << book::get_availablebooks() << endl;

    return 0 ;
}

