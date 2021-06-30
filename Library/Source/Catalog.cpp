#include "../Header/Catalog.h"
#include "../Header/Library.h"

Catalog::Catalog()
{
}
Catalog::~Catalog()
{
}
Catalog::Catalog(list<Book> books)
{
    this->books = books;
}

// friend ostream &operator<<(ostream &os, const Catalog &);
// friend bool operator==(const Catalog &lhs, const Catalog &rhs);

//manage
bool Catalog::add_book(Book i)
{
    if (get_book(i.getISBN(), "ISBN") || get_book(i.getTitle(), "title"))
    {
        return false;
    }
    books.push_back(i);
    return true;
}
bool Catalog::add_book()
{
    cout << "add new book: " << endl;
    Book i = Book::input();
    return add_book(i);
}
bool Catalog::remove_book()
{
    Book *ptr = pick_book();
    if (!ptr)
    {
        cout << "Invalid pattern";
        return false;
    }
    cout << "success";
    return remove_book(*ptr);
}

bool Catalog::remove_book(Book i)
{
    books.remove(i);
    return true;
}

Book *Catalog::get_book(string pattern, string by)
{
    for (auto it = books.begin(); it != books.end(); it++)
    {
        if (
            (by == "ISBN" && it->getISBN() == pattern) ||
            (by == "title" && it->getTitle() == pattern)

        )
            return &*it;
    }
    return NULL;
}
Book *Catalog::pick_book()
{
    string by;
    if (select_statement("get book by ISBN", "get book by title"))
    {
        clear();
        return get_book(input_str("Enter book title: "), "title");
    }
    clear();
    return get_book(input_str("Enter book ISBN: "), "ISBN");
}
bool Catalog::select_book()
{
    Book *ptr = pick_book();
    if (!ptr)
    {
        cout << "Invalid name";
        wait();
        clear();
        return false;
    }
    clear();
    if (select_statement("View book", "modify book"))
    {
        ptr->modify();
    }
    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}
void Catalog::books_list(list<Book> lst)
{
    cout
        << setw(88) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "|  ISBN " << '|'
        << setw(12) << left << "publish year" << '|'
        << setw(20) << left << "publisher" << '|'
        << setw(10) << left << "status" << '|'
        << setw(30) << left << "            Title" << '|'

        << endl
        << setw(88) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(10) << left << "|" + it->getISBN() << '|'
            << setw(12) << left << it->getPublish_year() << '|'
            << setw(20) << left << it->getPublisher() << '|'
            << setw(10) << left << (BookStatus)it->getStatus() << '|'
            << setw(30) << left << it->getTitle() << '|'
            << endl
            << setw(88) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

list<Book> Catalog::getBooks(string pattern, string type)
{
    list<Book> temp;
    for (auto it = books.begin(); it != books.end(); it++)
    {
        if (type == "author")
        {
            if (it->write_by(pattern))
                temp.push_back(*it);
        }
        else if (type == "publisher")
        {
            if (it->getPublisher() == (pattern))
                temp.push_back(*it);
        }
        else if (type == "publication year")
        {
            if (to_string(it->getPublish_year()) == pattern)
                temp.push_back(*it);
        }
    }
    return temp;
}
void Catalog::search_book()
{
    Book *ptr = pick_book();
    if (!ptr)
    {
        cout << "book not found";
        wait();
    }
    cout << *ptr;
    wait();
}
void Catalog::search_books()
{
    cout << "Search by:" << endl;
    string typ = select_statements(
        {
            "author",
            "publication year",
            "publisher",
        });
    clear();
    string pattern = input_str("Enter " + typ + ": ");
    clear();
    return books_list(getBooks(pattern, typ));
}

bool Catalog::add_book_request(Member *member)
{
    clear();
    cout << "select a book:\n";
    Book *book = pick_book();
    if (!book)
    {
        cout << "invlaid book";
        return false;
    }
    BookRequest temp = BookRequest::input(member->getAccount_id(), book->getISBN());
    return ((Library *)Holder::library)->add_request(temp);
}
bool Catalog::add_book_request()
{
    Member *member = ((Library *)Holder::library)->pick_member();
    if (!member)
    {
        cout << "invlaid member";
        return false;
    }
    return add_book_request(member);
}

list<Book> *Catalog::getBooks()
{
    return &this->books;
}

void Catalog::setBooks(list<Book> books)
{
    this->books = books;
}