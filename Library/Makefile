all: Compiled/Library.o  Compiled/Librarian.o Compiled/Constraint.o Compiled/main.o Compiled/Account.o Compiled/Author.o Compiled/Book.o Compiled/BookRequest.o Compiled/Catalog.o Compiled/Member.o Compiled/View.o
	g++ Compiled/*.o -o app 


Compiled/main.o: main.cpp
	g++ -c main.cpp -o Compiled/main.o


Compiled/Account.o: Source/Account.cpp Header/Account.h
	g++ -c Source/Account.cpp -o Compiled/Account.o


Compiled/Author.o: Source/Author.cpp Header/Author.h
	g++ -c Source/Author.cpp -o Compiled/Author.o


Compiled/Book.o: Source/Book.cpp Header/Book.h
	g++ -c Source/Book.cpp -o Compiled/Book.o


Compiled/BookRequest.o: Source/BookRequest.cpp Header/BookRequest.h
	g++ -c Source/BookRequest.cpp -o Compiled/BookRequest.o


Compiled/Catalog.o: Source/Catalog.cpp Header/Catalog.h
	g++ -c Source/Catalog.cpp -o Compiled/Catalog.o


Compiled/Constraint.o: Source/Constraint.cpp Header/Constraint.h
	g++ -c Source/Constraint.cpp -o Compiled/Constraint.o


Compiled/Librarian.o: Source/Librarian.cpp Header/Librarian.h
	g++ -c Source/Librarian.cpp -o Compiled/Librarian.o


Compiled/Library.o: Source/Library.cpp Header/Library.h
	g++ -c Source/Library.cpp -o Compiled/Library.o


Compiled/Member.o: Source/Member.cpp Header/Member.h
	g++ -c Source/Member.cpp -o Compiled/Member.o


Compiled/View.o: Source/View.cpp Header/View.h
	g++ -c Source/View.cpp -o Compiled/View.o


clean:
	rm -rf Compiled
	mkdir Compiled
	reset

clear:
	del Compiled
	mkdir Compiled
	cls


test:
	