#ifndef A5DEDFF8_A157_4186_9BDB_0607F7B0CD12
#define A5DEDFF8_A157_4186_9BDB_0607F7B0CD12

#include "Book.h"
#include "Account.h"
#include "Member.h"
class BookRequest
{
private:
    int BLcode;
    string ISBN;
    int memberID;
    time_t borrow_date = -1;
    int duration = -1;
    time_t return_date = -1;
    BookRequestStatus status = HOLD;

    static int new_code;

public:
    BookRequest();
    ~BookRequest();
    BookRequest(
        string ISBN,
        int memberID,
        time_t borrow_date,
        int duration,
        time_t return_date,
        BookRequestStatus status

    );

    friend bool operator==(const BookRequest &lhs, const BookRequest &rhs);
    friend ostream &operator<<(ostream &os, const BookRequest &);

    static BookRequest input();
    static BookRequest input(int member_id, string book_isbn);

    void modify();

    static void render(list<BookRequest> lst, BookRequestStatus stat);

    bool approve();
    bool decline();
    bool returned();

    bool take_action();

    Book *get_book(void *source);

    int getBLcode();
    void setBLcode(int BLcode);
    string getISBN();
    void setISBN(string ISBN);
    int getMemberID();
    void setMemberID(int memberID);
    time_t getBorrow_date();
    void setBorrow_date(time_t borrow_date);
    int getDuration();
    void setDuration(int duration);
    BookRequestStatus getStatus();
    void setStatus(BookRequestStatus status);
    static int getNew_code();
    static void setNew_code(int new_code);
};

#endif /* A5DEDFF8_A157_4186_9BDB_0607F7B0CD12 */
