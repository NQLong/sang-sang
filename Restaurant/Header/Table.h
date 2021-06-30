#ifndef B95B56D6_B551_43DF_B6E7_C67B603B1582
#define B95B56D6_B551_43DF_B6E7_C67B603B1582

#include "Constraint.h"

class Table
{
    int table_id;
    int max_capacity;

    static int new_index;

public:
    Table();
    ~Table();
    Table(int max);
    Table(const Table &);
    Table &operator=(const Table &);
    friend bool operator==(const Table &, const Table &);
    friend ostream &operator<<(ostream &, const Table &);

    static Table input();

    void modify();

    int getTable_id();
    void setTable_id(int table_id);
    int getMax_capacity();
    void setMax_capacity(int max_capacity);
    static int getNew_index();
    static void setNew_index(int new_index);
};

#endif /* B95B56D6_B551_43DF_B6E7_C67B603B1582 */
