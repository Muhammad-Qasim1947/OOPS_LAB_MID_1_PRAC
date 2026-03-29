// The system should manage members, books, and borrowing records.
// Each member can borrow up to 3 books, and each book has an availability status.
// The system should allow issuing and returning books, and display complete member details.

// 🔹 Classes:
// 1. Member Class:
// Data Members:
// memberID (int) → Unique member ID
// name (string) → Member name
// borrowedBooks[3] (array of Book) → Max 3 books
// bookCount (int) → Current borrowed books
// Member Functions:
// borrowBook(Book) → Borrow a book (max 3, only if available)
// returnBook(Book) → Return a book
// displayMemberInfo() → Show member details + borrowed books
// 2. Book Class:
// Data Members:
// bookID (int) → Unique ID
// title (string) → Book name
// author (string) → Author name
// isAvailable (bool) → Availability status
// Member Functions:
// issueBook() → Marks book as not available
// returnBook() → Marks book as available
// displayBookInfo() → Displays book details
// 3. Library Class:
// Data Members:
// books[5] (array of Book) → Max 5 books
// totalBooks (int) → Current number of books
// Member Functions:
// addBook(Book) → Add book to library (max 5)
// displayAllBooks() → Show all books
// searchBookByID(int) → Find book

#include <iostream>
using namespace std;

class book
{
private:
    int id;
    static int next_id;
    static int totalbooks;
    const string title;
    const string author;
    bool isavailable;
    static int availablebooks;

public:
    book(string t, string a) : id(next_id), author(a), title(t)
    {
        next_id++;
        totalbooks++;
        availablebooks++;
        isavailable = true;
    }

    void issuebook()
    {
        if (isavailable)
        {
            isavailable = false;
            availablebooks--;
            cout << "Book " << title << " Has Been Issued" << endl;
        }
        else
        {
            cout << "Book" << title << "Not Available" << endl;
        }
    }

    void returnbook()
    {
        if (!isavailable)
        {
            availablebooks++;
            isavailable = true;
            cout << "Book " << title << " Has Been Returned" << endl;
        }
        else
        {
            cout << "All Books Are Available" << endl;
        }
    }

    void display() const
    {
        cout << "-----Library-----" << endl;
        cout << "Book Title : " << title << endl;
        cout << "Book ID : " << id << endl;
        cout << "Book Author : " << author << endl;
    }

    static void show()
    {
        cout << "Total Books : " << totalbooks << endl;
        cout << "Available Books : " << availablebooks << endl;
    }

    ~book()
    {
        totalbooks--;
        if (isavailable)
        {
            availablebooks--;
            cout << "Book " << title << " Has Been Removed" << endl;
        }
    }
};

int book ::totalbooks = 0;
int book ::availablebooks = 0;
int book ::next_id = 1001;

class member
{
private:
    const int member_id;
    static int next_id;
    const string member_name;
    book *borrowedbooks[3];
    int bookcount;
    static int totalmembers;

public:
    member(string n) : member_name(n), member_id(next_id)
    {
        bookcount = 0;
        next_id++;
        totalmembers++;
    }

    void borrowbook(book *b)
    {
        if (bookcount < 3)
        {
            borrowedbooks[bookcount] = b;
            bookcount++;

            b->issuebook();
        }
        else
        {
            cout << "Limit reached (3 books max)" << endl;
        }
    }

    void returnbook(book *b)
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
        {
            if (borrowedbooks[i] == b)
            {
                found = true;
                for (int j = i; j < bookcount - 1; j++)
                {
                    borrowedbooks[j] = borrowedbooks[j + 1];
                }
                bookcount--;
                b->returnbook();
            }
        }
        if (found)
        {
            cout << "Book Returned Successfully" << endl;
        }
        else
        {
            cout << "This book was not borrowed by this member" << endl;
        }
    }

    void display() const
    {
        cout << "-----Member Details-----" << endl;
        cout << "Member ID : " << member_id << endl;
        cout << "Member Name : " << member_name << endl;
        cout << endl;

        if (bookcount == 0)
        {
            cout << "No Books Borrowed" << endl;
            return;
        }

        cout << "-----Books Borrowed-----" << endl;

        for (int i = 0; i < bookcount; i++)
        {
            borrowedbooks[i]->display();
        }
    }

    static void show()
    {
        cout << "Total Number Of Members : " << totalmembers << endl;
    }
};

int member ::totalmembers = 0;
int member ::next_id = 2007;

int main()
{
    book b1("Chemistry", "Qasim");
    book b2("Maths", "Yash");
    book b3("Physics", "Agha");

    // Create Member
    member m1("Ali");

    cout << "\n--- Initial Status ---\n";
    book::show();
    member::show();

    cout << "\n--- Borrowing Books ---\n";
    m1.borrowbook(&b1);
    m1.borrowbook(&b2);
    m1.borrowbook(&b3);

    // Try exceeding limit
    m1.borrowbook(&b1);

    cout << "\n--- Member Details ---\n";
    m1.display();

    cout << "\n--- Books Status ---\n";
    book::show();

    cout << "\n--- Returning Book ---\n";
    m1.returnbook(&b2);

    cout << "\n--- Member Details After Return ---\n";
    m1.display();

    cout << "\n--- Final Book Status ---\n";
    book::show();

    return 0;
}