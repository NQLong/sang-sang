#ifndef C3105AAA_6B54_480C_A7C4_25505A8F3EA1
#define C3105AAA_6B54_480C_A7C4_25505A8F3EA1
#include "Constraint.h"

class Author
{
private:
    string name;
    Gender gender;

    static list<Author> authors;

public:
    Author();
    ~Author();
    Author(string, Gender);

    static bool add_author(Author);
    static bool add_author();
    static bool remove_author();
    static bool remove_author(Author);
    static Author *get_author(string name);
    static Author *pick_author();
    static bool select_author();
    static void authors_list();
    static void manage_author();
    static Author input();

    void modify();
    
    friend bool operator==(const Author &lhs, const Author &rhs);
    friend ostream &operator<<(ostream &os, const Author &author);

    string getName();
    void setName(string);
    Gender getGender();
    void setGender(Gender gender);
    static list<Author> *getAuthors();
    static void setAuthors(list<Author> authors);

};
 
#endif /* C3105AAA_6B54_480C_A7C4_25505A8F3EA1 */
