#include "../Header/Book.h"

Book::Book() {}
Book::~Book() {}
Book::Book(string ISBN, string title,
           string publisher, list<string> authors, int year, BookStatus stat)
{
    this->ISBN = ISBN;
    this->title = title;
    this->publisher = publisher;
    this->authors_name = authors;
    this->publish_year = year;
    this->status = stat;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return (
        (lhs.ISBN == rhs.ISBN) &&
        (lhs.title == rhs.title) &&
        (lhs.publisher == rhs.publisher) &&
        (lhs.authors_name == rhs.authors_name) &&
        (lhs.publish_year == rhs.publish_year) &&
        (lhs.status == rhs.status));
}

ostream &operator<<(ostream &os, const Book &b)
{
    os
        << "ISBN: " << b.ISBN << endl
        << "Book title: " << b.title << endl
        << "Publisher: " << b.publisher << endl
        << "Publish at: " << b.publish_year << endl
        << "Authors list: " << endl;

    int count = 1;
    for (auto it = b.authors_name.begin(); it != b.authors_name.end(); it++)
    {
        os << setw(5) << "" << setw(3) << left << to_string(count++) + ".";
        if (Author::get_author(*it))
            os << *Author::get_author(*it) << endl;
        else
            os << *it << endl;
    }

    return os << "Status: " << (BookStatus)b.status;
}

Book Book::input()
{
    Book temp;
    temp.ISBN = input_str("ISBN: ");
    temp.title = input_str("Title: ");
    temp.publisher = input_str("Publisher: ");
    temp.publish_year = my_input_c<int>("Publish year: ");
    clear();
    temp.status = select_book_status();
    clear();
    while (!select_statement("Add one more author to this book", "Done"))
    {
        clear();
        temp.add_author();
        wait();
        clear();
    }
    return temp;
}

void Book::modify()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify title." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify publisher." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify publish year." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify status." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify authors." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            title = input_str("Title: ");

            break;
        case 2:
            clear();
            publisher = input_str("Publisher: ");

            break;
        case 3:
            clear();
            publish_year = my_input_c<int>("Publish year: ");

            break;
        case 4:
            clear();
            status = select_book_status();

            break;
        case 5:
            clear();
            modify_authors();

            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

void Book::modify_authors()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add author." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove author." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (!add_author())
                wait();

            break;
        case 2:
            clear();
            remove_author();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Book::add_author(string name)
{

    authors_name.remove(name);
    authors_name.push_back(name);
    return true;
}
bool Book::add_author()
{
    Author *author = Author::pick_author();
    if (!author)
    {
        clear();
        cout << "name doesn't exist\nDo you want to add new author\n";
        if (select_statement("Yes", "No"))
        {
            clear();
            return false;
        }
        clear();
        if (Author::add_author())
        {
            return add_author(Author::getAuthors()->back().getName());
        }
        cout << "fail";
    }
    return add_author(author->getName());
}
bool Book::remove_author()
{
    return remove_author(input_str("Enter author name: "));
}
bool Book::remove_author(string name)
{
    authors_name.remove(name);
    return true;
}

void Book::authors_list()
{
    cout
        << setw(42) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(5) << left << "|  # " << '|'
        << setw(30) << left << "  Name  " << '|'

        << endl
        << setw(42) << setfill('*') << "" << endl
        << setfill(' ');

    int count = 1;
    for (auto it = authors_name.begin(); it != authors_name.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(10) << left << "|" + to_string(count++) << '|'
            << setw(30) << left << *it << '|'
            << endl
            << setw(42) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

bool Book::write_by(string author)
{
    for (auto it = authors_name.begin(); it != authors_name.end(); it++)
    {
        if (*it == author)
            return true;
    }
    return false;
}

//getter setter
string Book::getISBN()
{
    return this->ISBN;
}

void Book::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

string Book::getTitle()
{
    return this->title;
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getPublisher()
{
    return this->publisher;
}

void Book::setPublisher(string publisher)
{
    this->publisher = publisher;
}

list<string> *Book::getAuthors_name()
{
    return &this->authors_name;
}

void Book::setAuthors_name(list<string> authors_name)
{
    this->authors_name = authors_name;
}

int Book::getPublish_year()
{
    return this->publish_year;
}

void Book::setPublish_year(int publish_year)
{
    this->publish_year = publish_year;
}

BookStatus Book::getStatus()
{
    return this->status;
}

void Book::setStatus(BookStatus status)
{
    this->status = status;
}
