#include "../Header/Account.h"

int Account::new_id = 0;

Account::Account()
{
    this->account_id = new_id++;
}
Account::~Account()
{
}
Account::Account(
    AccountStatus _stat,
    AccountType _typ,
    string _full_name,
    time_t _date_of_birth,
    string _phone,
    string _email,
    Address _address,
    string _password)
    : stat(_stat),
      typ(_typ),
      full_name(_full_name),
      date_of_birth(_date_of_birth),
      phone(_phone),
      email(_email),
      address(_address),
      password(_password)
{
    this->account_id = new_id++;
}

ostream &operator<<(ostream &os, const Account &a)
{

    return os
           << "Account type: " << (AccountType)a.typ << endl
           << "Account status: " << (AccountStatus)a.stat << endl
           << "Full name: " << a.full_name << endl
           << "Date of birth: " << string_of_time(a.date_of_birth) << endl
           << "Phone: " << a.phone << endl
           << "Email: " << a.email << endl
           << "Address: " << a.address;
}

bool operator==(const Account &lhs, const Account &rhs)
{
    return (
        (lhs.typ == rhs.typ) &&
        (lhs.stat == rhs.stat) &&
        (lhs.full_name == rhs.full_name) &&
        (lhs.date_of_birth == rhs.date_of_birth) &&
        (lhs.phone == rhs.phone) &&
        (lhs.email == rhs.email) &&
        (lhs.address == rhs.address));
}

void Account::input_account()
{
    this->full_name = input_str("Full name: ");
    this->email = input_str("Email: ");
    this->password = input_str("Password: ");
    this->phone = input_str("Phone: ");
    clear();
    cout << "date of birth:" << endl;
    this->date_of_birth = input_date();
    clear();
    cout << "Address:" << endl;
    this->address = Address::inputAddress();
}

void Account::modify()
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({
            "modify name",
            "modify email",
            "modify DOB",
            "modify address",
            "modify phone",
            "modify password",
        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            this->full_name = input_str("Full name: ");
            break;
        case 2:
            clear();

            this->email = input_str("Email: ");
            break;

        case 3:
            clear();
            cout << "date of birth:" << endl;
            this->date_of_birth = input_date();
            break;
        case 4:
            clear();
            cout << "Address:" << endl;
            this->address = Address::inputAddress();
            break;
        case 5:
            clear();
            this->phone = input_str("Phone: ");
            break;
        case 6:
            clear();
            this->password = input_str("Password: ");
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void Account::render_account()
{

    cout << setw(10) << left << "|" + to_string(this->account_id) << '|'
         << setw(12) << left << (AccountStatus)this->stat << '|'
         << setw(12) << left << (AccountType)this->typ << '|'
         << setw(20) << left << email << '|'
         << setw(30) << left << full_name << '|'
         << endl
         << setw(90) << setfill('*') << "" << endl
         << setfill(' ');
}
//getter &&setter

string Account::getPassword()
{
    return password;
}

void Account::setPassword(string _password)
{
    password = _password;
}

int Account::getAccount_id()
{
    return this->account_id;
}

void Account::setAccount_id(int account_id)
{
    this->account_id = account_id;
}

AccountStatus Account::getStat()
{
    return this->stat;
}

void Account::setStat(AccountStatus stat)
{
    this->stat = stat;
}

AccountType Account::getTyp()
{
    return this->typ;
}

void Account::setTyp(AccountType typ)
{
    this->typ = typ;
}

string Account::getFull_name()
{
    return this->full_name;
}

void Account::setFull_name(string full_name)
{
    this->full_name = full_name;
}

time_t Account::getDate_of_birth()
{
    return this->date_of_birth;
}

void Account::setDate_of_birth(time_t date_of_birth)
{
    this->date_of_birth = date_of_birth;
}

string Account::getPhone()
{
    return this->phone;
}

void Account::setPhone(string phone)
{
    this->phone = phone;
}

string Account::getEmail()
{
    return this->email;
}

void Account::setEmail(string email)
{
    this->email = email;
}

Address Account::getAddress()
{
    return this->address;
}

void Account::setAddress(Address address)
{
    this->address = address;
}

int Account::getNew_id()
{
    return new_id;
}

void Account::setNew_id(int _new_id)
{
    new_id = _new_id;
}
