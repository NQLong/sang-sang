#ifndef A85FB8BB_28EF_4676_9B7A_5459FD1367A9
#define A85FB8BB_28EF_4676_9B7A_5459FD1367A9

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>
#include <sstream>

using namespace std;

#define SECOND_IN_DAY 86400
#define SECOND_IN_HOUR 3600

enum AccountType
{
    LIBRARIAN,
    MEMBER
};
ostream &operator<<(ostream &os, const AccountType &a);
AccountType select_account_type();

enum AccountStatus
{
    ACTIVE,
    SUSPENDED,
    CLOSED
};
ostream &operator<<(ostream &os, const AccountStatus &a);
AccountStatus select_account_status();

enum BookRequestStatus
{
    HOLD,
    APPROVE,
    DECLINE,
    RETURNED,
    NONE
};
ostream &operator<<(ostream &os, const BookRequestStatus &a);
BookRequestStatus select_book_request_status();

enum BookStatus
{
    LOANED,
    AVAILABLE
};
ostream &operator<<(ostream &os, const BookStatus &a);
BookStatus select_book_status();

enum Gender
{
    MALE,
    FEMALE,
    OTHER
};
ostream &operator<<(ostream &os, const Gender &a);
Gender select_gender();

class Holder
{
public:
    static void *library;
};

class Address
{
public:
    string
        street,
        city,
        state,
        zip_code,
        country;
    Address();
    ~Address();
    Address(string _street, string _city, string _state, string _zip_code, string _country)
        : street(_street), city(_city), state(_state), zip_code(_zip_code), country(_country) {}

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        return os << address.street << " street, " << address.city << " city, " << address.state << " state, " << address.country << ", zipcode: " << address.zip_code;
    }

    friend bool operator==(const Address &, const Address &address);

    static Address inputAddress();
};

bool is_consist(list<int>, int);

bool is_valid_date(time_t);

time_t input_time();

time_t input_date();

void wait();

void clear();

bool select_statement(string false_stmt, string true_stmt);

string lower_string(string in);

string select_statements(list<string>);

string input_str(string stm);

template <class T>
T my_input_c(string stm)
{
    T inp;
    cout << stm;
    cin >> inp;
    cin.ignore();
    return inp;
}

string string_of_time(time_t);


void print_option(list<string>);

#endif /* A85FB8BB_28EF_4676_9B7A_5459FD1367A9 */
