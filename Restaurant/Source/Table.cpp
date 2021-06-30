#include "../Header/Table.h"

int Table::new_index = 0;

Table::Table()
{
    this->table_id = new_index++;
}

Table::~Table() {}

Table::Table(int max)
{
    this->table_id = new_index++;
    this->max_capacity = max;
}

Table::Table(const Table &other)
{
    this->table_id = other.table_id;
    this->max_capacity = other.max_capacity;
}

Table &Table::operator=(const Table &other)
{
    this->table_id = other.table_id;
    this->max_capacity = other.max_capacity;
    return *this;
}

bool operator==(const Table &lhs, const Table &rhs)
{
    return (
        (lhs.table_id == rhs.table_id) &&
        (lhs.max_capacity == rhs.max_capacity)

    );
}
ostream &operator<<(ostream &os, const Table &t)
{
    return os
           << "Table id : " << t.table_id << endl
           << "Table maxcapacity : " << t.max_capacity << endl

        ;
}

Table Table::input()
{
    Table temp;
    cout << "Table max capacity :";
    cin >> temp.max_capacity;
    cin.ignore();
    return temp;
}

void Table::modify()
{
    cout << "Table max capacity :";
    cin >> this->max_capacity;
    cin.ignore();
}

int Table::getTable_id()
{
    return this->table_id;
}

void Table::setTable_id(int table_id)
{
    this->table_id = table_id;
}

int Table::getMax_capacity()
{
    return this->max_capacity;
}

void Table::setMax_capacity(int max_capacity)
{
    this->max_capacity = max_capacity;
}

int Table::getNew_index()
{
    return new_index;
}

void Table::setNew_index(int _new_index)
{
    new_index = _new_index;
}
