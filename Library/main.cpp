#include "Header/View.h"

Library init_data();

int main()
{
    Library library = init_data();
    Holder::library = &library;
    View view;
    view.start_app();
}
Library init_data()
{
    Address address("Bleeker", "New York", "New York", "123456", "USA");
    Library library;
    Holder::library = &library;
    library.setName("Hell");
    library.setLibrarians({
        Librarian(ACTIVE, "Peter Davidson 0", time(0), "1234560", "2", address, "2"),
        Librarian(SUSPENDED, "Peter Davidson 1", time(0), "1234561", "3", address, "3"),
        Librarian(CLOSED, "Peter Davidson 2", time(0), "1234562", "4", address, "4"),
        Librarian(ACTIVE, "Peter Davidson 3", time(0), "1234563", "5", address, "5"),
        Librarian(ACTIVE, "Peter Davidson 4", time(0), "1234564", "6", address, "6"),
    });
    library.setMembers({
        Member(ACTIVE, "Peter Davidson 5 ", time(0), "123456", "1", address, "1"),
        Member(ACTIVE, "Peter Davidson 6", time(0), "123456", "7", address, "1"),
        Member(SUSPENDED, "Peter Davidson 7", time(0), "123456", "8", address, "1"),
        Member(CLOSED, "Peter Davidson 8", time(0), "123456", "9", address, "1"),
        Member(ACTIVE, "Peter Davidson 9", time(0), "123456", "10", address, "1"),
        Member(ACTIVE, "Peter Davidson 10", time(0), "123456", "11", address, "1"),
    });
    library.getCatalog()->setBooks({
        Book(
            "1",                //isbn
            "1",                //title
            "123",              //publihser
            {"Ben 1", "Ben 2"}, //Authors
            1945,
            AVAILABLE),
        Book(
            "2",                //isbn
            "2",                //title
            "456",              //publihser
            {"Ben 3", "Ben 4"}, //Authors
            1989,
            LOANED),
        Book(
            "3",                //isbn
            "3",                //title
            "456",              //publihser
            {"Ben 3", "Ben 4"}, //Authors
            1989,
            AVAILABLE),
        Book(
            "4",                //isbn
            "4",                //title
            "456",              //publihser
            {"Ben 3", "Ben 4"}, //Authors
            1989,
            AVAILABLE),
    });
    library.setRequests({
        BookRequest("1",5,-1,-1,-1,HOLD),
        BookRequest("2",6,-1,-1,-1,APPROVE),
    });
    Author::setAuthors({
        Author("Ben 1", MALE),
        Author("Ben 2", MALE),
        Author("Ben 3", MALE),
        Author("Ben 4", MALE),
    });
    return library;
}
