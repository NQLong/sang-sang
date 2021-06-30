#include "../Header/BookRequest.h"
#include "../Header/Library.h"
int BookRequest::new_code = 0;

bool BookRequest::take_action()
{
    clear();
    print_option({
        "Approve request",
        "Decline request",
        "return book of request",
    });
    int option;
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case 1:
        clear();
        approve();
        wait();
        break;
    case 2:
        clear();
        decline();
        wait();
        break;

    case 3:
        clear();
        returned();
        break;
    default:

        break;
    }
    return true;
}

BookRequest::BookRequest()
{
    this->BLcode = new_code++;
}
BookRequest::~BookRequest() {}
BookRequest::BookRequest(
    string ISBN,
    int memberID,
    time_t borrow_date,
    int duration,
    time_t return_date,
    BookRequestStatus status)
{
    this->BLcode = new_code++;
    this->ISBN = ISBN;
    this->memberID = memberID;
    this->borrow_date = borrow_date;
    this->duration = duration;
    this->return_date = return_date;
    this->status = status;
}

void BookRequest::modify() {}

BookRequest BookRequest::input(int member_id, string book_isbn)
{
    BookRequest temp;
    temp.memberID = member_id;
    temp.ISBN = book_isbn;
    return temp;
}

bool BookRequest::approve()
{
    if (this->status != HOLD)
    {
        cout << "invalid action on request";
        return false;
    }
    Book *book = ((Library *)Holder::library)->getCatalog()->get_book(this->ISBN, "ISBN");
    Member *member = ((Library *)Holder::library)->get_member(this->memberID);
    if (!book)
    {
        cout << "Invalid book ISBN";
        return false;
    }
    else if (book->getStatus() == LOANED)
    {
        cout << "book is not available to be loaned";
        return false;
    }
    else if (!member)
    {
        cout << "Invalid book member";
        return false;
    }
    else if (member->getStat() != ACTIVE)
    {
        cout << "member is not available to loan";
        return false;
    }
    book->setStatus(LOANED);
    this->status = APPROVE;
    this->borrow_date = time(0);
    this->duration = my_input_c<double>("Enter loaned duration: ");
    return true;
}

bool BookRequest::decline()
{
    if (this->status != HOLD)
    {
        cout << "invalid action on request";
        return false;
    }
    this->status = DECLINE;
    return true;
}

bool BookRequest::returned()
{
    if (this->status != APPROVE)
    {
        cout << "invalid action on request";
        return false;
    }
    Book *book = ((Library *)Holder::library)->getCatalog()->get_book(this->ISBN, "ISBN");
    if (book)
        book->setStatus(AVAILABLE);
    this->status = RETURNED;

    return true;
}

void BookRequest::render(list<BookRequest> lst, BookRequestStatus stat)
{

    cout
        << setw(46) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "| BLcode " << '|'
        << setw(12) << left << "  ISBN  " << '|'
        << setw(10) << left << "member id" << '|'
        << setw(10) << left << "  Status  " << '|'

        << endl
        << setw(46) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (!&*it)
            continue;
        if (stat != NONE)
        {
            if (it->getStatus() != stat)
                continue;
        }
        cout
            << setw(10) << left << "|" + to_string(it->getBLcode()) << '|'
            << setw(12) << left << it->getISBN() << '|'
            << setw(10) << left << it->getMemberID() << '|'
            << setw(10) << left << (BookRequestStatus)it->getStatus() << '|'
            << endl
            << setw(46) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

bool operator==(const BookRequest &lhs, const BookRequest &rhs)
{
    return (
        (lhs.BLcode == rhs.BLcode) &&
        (lhs.ISBN == rhs.ISBN) &&
        (lhs.memberID == rhs.memberID) &&
        (lhs.borrow_date == rhs.borrow_date) &&
        (lhs.return_date == rhs.return_date) &&
        (lhs.status == rhs.status) &&
        (true)

    );
}

ostream &operator<<(ostream &os, const BookRequest &r)
{
    os
        << "Blcode: " << r.BLcode << endl
        << "ISBN: " << r.ISBN << endl
        << "member id: " << r.memberID << endl
        << "Status: " << (BookRequestStatus)r.status;
    switch (r.status)
    {
    case HOLD:
    case DECLINE:
        return os;
    case RETURNED:
        os << endl
           << "Resturned date: " << string_of_time(r.return_date);
    case APPROVE:
        os << endl
           << "borrowed date: " << string_of_time(r.borrow_date) << endl;
        os
            << "borrowed duration: " << r.duration << " day(days)";
    }

    return os;
}

int BookRequest::getBLcode()
{
    return this->BLcode;
}

void BookRequest::setBLcode(int BLcode)
{
    this->BLcode = BLcode;
}

string BookRequest::getISBN()
{
    return this->ISBN;
}

void BookRequest::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

int BookRequest::getMemberID()
{
    return this->memberID;
}

void BookRequest::setMemberID(int memberID)
{
    this->memberID = memberID;
}

time_t BookRequest::getBorrow_date()
{
    return this->borrow_date;
}

void BookRequest::setBorrow_date(time_t borrow_date)
{
    this->borrow_date = borrow_date;
}

int BookRequest::getDuration()
{
    return this->duration;
}

void BookRequest::setDuration(int duration)
{
    this->duration = duration;
}

BookRequestStatus BookRequest::getStatus()
{
    return this->status;
}

void BookRequest::setStatus(BookRequestStatus status)
{
    this->status = status;
}

int BookRequest::getNew_code()
{
    return new_code;
}

void BookRequest::setNew_code(int _new_code)
{
    new_code = _new_code;
}
