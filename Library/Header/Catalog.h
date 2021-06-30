#ifndef C3BC5D7A_4077_4576_9D05_BD609D467DAD
#define C3BC5D7A_4077_4576_9D05_BD609D467DAD
#include "Book.h"
#include "Member.h"
#include "BookManage.h"
#include "Search.h"

class Catalog
    : public BookManage,
      public Search
{
    list<Book> books;

public:
    Catalog();
    ~Catalog();
    Catalog(list<Book> books);

    // friend ostream &operator<<(ostream &os, const Catalog &);
    // friend bool operator==(const Catalog &lhs, const Catalog &rhs);

    //manage
    bool add_book(Book);
    bool add_book();
    bool remove_book();
    bool remove_book(Book);
    Book *get_book(string name, string by);
    Book *pick_book();
    bool select_book();
    void books_list(list<Book> books);

    //book_request
    bool add_book_request();
    bool add_book_request(Member *);

    //search
    list<Book> getBooks(string pattern, string);
    void search_book();
    void search_books();

    list<Book> *getBooks();
    void setBooks(list<Book> books);
};

#endif /* C3BC5D7A_4077_4576_9D05_BD609D467DAD */
