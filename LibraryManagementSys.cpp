//Libraries
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Book
{
    private:
        string id, title, author, edition, publication; //private variables
    
    public:
        //setters-used to assign values to the private variables
        void setID(string a)
        {
            id = a;
        }
        void setTitle(string b)
        {
            title = b;
        }
        void setAuthor(string c)
        {
            author = c;
        }
        void setEdition(string d)
        {
            edition = d;
        }
        void setPublication(string e)
        {
            publication = e;
        }

        //getters-used to get values from private variables
        string getID()
        {
            return id;
        }
        string getTitle()
        {
            return title;
        }
        string getAuthor()
        {
            return author;
        }
        string getEdition()
        {
            return edition;
        }
        string getPublication()
        {
            return publication;
        }
};

//initializing functions with counter as parameter
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();

int counter = 0;

//function for incrementing counter
void increment(int a)
{
    a++;
    counter = a;
}

//function for decrementing counter
void decrement(int a)
{
    a--;
    counter = a;
}

//Book class array initialization
Book books[10];

//main function
int main()
{
    string choice;

    //Main menu
    system("CLS");

    cout << "Library Management System\n\n";
    cout << "[1] Add Book\n";
    cout << "[2] Delete Book\n";
    cout << "[3] Edit Book\n";
    cout << "[4] Search Book\n";
    cout << "[5] View All Books\n";
    cout << "[6] Quit\n\n";

    cout << "Enter Choice: ";
    getline(cin, choice);
    system("CLS");

    if(choice == "1")
    {
        addBook(counter);
    }
    else if(choice == "2")
    {
        deleteBook(counter);
    }
    else if(choice == "3")
    {
        editBook(counter);
    }
    else if(choice == "4")
    {
        searchBook(counter);
    }
    else if(choice == "5")
    {
        viewAllBooks(counter);
    }
    else if(choice == "6")
    {
        quit();
    }
    else
    {
        main(); //function call to self
    }

    _getch();
    return 0;
}

//addBook function
void addBook(int counter)
{
    string id, title, author, edition, publication;
    cout << "Add Book\n\n";

    if(counter<10)
    {
        cout << "Enter ID: ";
        getline(cin, id);

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Edition: ";
        getline(cin, edition);

        cout << "Enter Publication: ";
        getline(cin, publication);

        books[counter].setID(id);
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setEdition(edition);
        books[counter].setPublication(publication);
        increment(counter);

        cout << "Your book added successfully!\n\nPress any key to continue...";
        _getch();
        main();
    }
    else
    {
        cout << "You have reached the maximum number of books to be added!\n\nPress any key to continue...";
        _getch();
        main();
    }
}

void deleteBook(int counter)
{
    string id;
    int choice;
    cout << "Delete Book\n\n";

    if(counter == 0)
    {
        cout << "There is no book to delete!\n\nPress any key to continue...";
        _getch();
        main();
    }

    cout << "Enter ID: ";
    getline(cin, id);

    for(int i=0; i<counter; i++)
    {
        if(books[i].getID() == id)
        {
            cout << "\nBook Found\n\n";
            cout << "Do you want to delete?\n[1] Yes\n[2] No\n\nEnter Choice: ";
            cin >> choice;

            if(choice == 1)
            {
                books[i].setID("");
                books[i].setTitle("");
                books[i].setAuthor("");
                books[i].setEdition("");
                books[i].setPublication("");

                for(int a=1; a<counter; a++)
                {
                    books[a] = books[a+1];
                }

                books[9].setID("");
                books[9].setTitle("");
                books[9].setAuthor("");
                books[9].setEdition("");
                books[9].setPublication("");
                decrement(counter);

                cout << "\nYour book deleted successfully!\n\nPress any key to continue...";
                _getch();
                main();
            }
            else
            {
                main();
            }
        }
    }

    cout << "\nYour book is not found!\n\nPress any key to continue...";
    _getch();
    main();
}

void editBook(int counter)
{
    system("CLS");
    string editID, choice;
    string id, title, author, edition, publication;
    cout << "\nEdit Book\n\n";

    if(counter == 0)
    {
        cout << "There is no book to edit!\n\nPress any key to continue...";
        _getch();
        main();
    }

    cout << "Enter ID: ";
    getline(cin, editID);

    for(int i=0; i<counter; i++)
    {
        if(books[i].getID() == editID)
        {
            cout << "\nBook Found!\n\n";
            cout << "ID: " << books[i].getID() << endl;
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
            cout << "Edition: " << books[i].getEdition() << endl;
            cout << "Publication: " << books[i].getPublication() << endl;
            cout << "\nDo you want to edit?\n[1] Yes\n[2] No\n\nEnter Choice: ";
            getline(cin, choice);

            if(choice == "1")
            {
                cout << "Enter ID: ";
                getline(cin, id);

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Edition: ";
                getline(cin, edition);

                cout << "Enter Publication: ";
                getline(cin, publication);

                books[i].setID(id);
                books[i].setTitle(title);
                books[i].setAuthor(author);
                books[i].setEdition(edition);
                books[i].setPublication(publication);

                cout << "\nYour book is edited successfully!\n\nPress any key to continue...";
                _getch();
                editBook(counter);
            }
            else
            {
                main();
            }
        }
    }

    cout << "\nBook not found!\n\nPress any key to continue...";
    _getch();
    main();
}

void searchBook(int counter)
{
    string id;
    int choice;
    bool print = false;
    cout << "Search Book\n\n";
    
    if(counter == 0)
    {
        cout << "There is no book to search!\n\nPress any key to continue...";
        _getch();
        main();
    }

    cout << "Enter ID: ";
    getline(cin, id);

    for(int i=0; i<counter; i++)
    {
        if(books[i].getID() == id)
        {
            cout << "\nBook Found\n\n";
            cout << "ID: " << books[i].getID() << endl;
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
            cout << "Edition: " << books[i].getEdition() << endl;
            cout << "Publication: " << books[i].getPublication() << endl;
            print = true;
        }
    }

    if(print)
    {
        cout << "\n\nPress any key to continue...";
        _getch();
        main();
    }
    else
    {
        cout << "\nBook not found!\n\nPress any key to continue...";
        _getch();
        main();
    }
}

void viewAllBooks(int counter)
{
    cout << "View All Books\n\n";
    
    for(int i=0; i<counter; i++)
    {
        cout << "Book Details\n\n";
        cout << "ID: " << books[i].getID() << endl;
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Edition: " << books[i].getEdition() << endl;
        cout << "Publication: " << books[i].getPublication() << endl;
    }

    cout << "Press any key to continue...";
    _getch();
    main();
}

void quit()
{
    _exit(1);
}