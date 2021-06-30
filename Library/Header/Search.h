#ifndef A3BFA574_F8BD_4298_B514_F8572FBC3AA7
#define A3BFA574_F8BD_4298_B514_F8572FBC3AA7
#include "Book.h"
class Search
{
public:
    Search() {}
    virtual ~Search() {}
    void search_view()
    {
        int option;
        bool loop = true;
        while (loop)
        {
            print_option({
                "search book",
                "search books",

            });

            cin >> option;
            cin.ignore();
            switch (option)
            {
            case 1:
                clear();
                search_book();
                break;
            case 2:
                clear();
                search_books();
                wait();
                break;
            default:
                loop = false;
                break;
            }
        }

        return;
    }
    virtual list<Book> getBooks(string pattern, string) = 0;
    virtual void search_book() = 0;
    virtual void search_books() = 0;
};

#endif /* A3BFA574_F8BD_4298_B514_F8572FBC3AA7 */
