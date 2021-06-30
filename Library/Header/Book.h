#ifndef AC8A705F_36F0_42E5_900F_5F11A1B2DA72
#define AC8A705F_36F0_42E5_900F_5F11A1B2DA72

#include "Author.h"

class Book
{
private:
    string ISBN;
    string title;
    string publisher;
    list<string> authors_name;
    int publish_year;
    BookStatus status;

public:
    Book();
    ~Book();
    Book(string ISBN, string title,
         string publisher, list<string>, int, BookStatus);

    friend ostream &operator<<(ostream &os, const Book &);
    friend bool operator==(const Book &lhs, const Book &rhs);

    bool write_by(string author);

    static Book input();

    void modify();

    bool add_author(string);
    bool add_author();
    bool remove_author();
    bool remove_author(string);
    void authors_list();
    void modify_authors();

    string getISBN();
    string getPublisher();
    string getTitle();
    void setISBN(string);
    void setPublisher(string);
    void setTitle(string);
    list<string>* getAuthors_name();
    void setAuthors_name(list<string> authors_name);
    int getPublish_year();
    void setPublish_year(int publish_year);
    BookStatus getStatus();
    void setStatus(BookStatus status);
};

#endif /* AC8A705F_36F0_42E5_900F_5F11A1B2DA72 */
