#ifndef DD79F05B_2B26_43BB_980B_87950CC35148
#define DD79F05B_2B26_43BB_980B_87950CC35148

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>
#include <sstream>

using namespace std;

#define SECOND_IN_DAY 86400
#define SECOND_IN_HOUR 3600

class Holder
{
public:
    static void *restaurant;
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
#endif /* DD79F05B_2B26_43BB_980B_87950CC35148 */
