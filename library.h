#pragma once
#include"book.h"
using namespace std;
class library
{
	// data member
	book* head;
public:
	// constructor
	library();
	// member functions
	void insertBookAtHead(string bName, string aName, string pName, string iDate, string rDate, string isbn);
	void insertBookAtTail(string bName, string aName, string pName, string iDate, string rDate, string isbn);
	void insertBookAtAnyIndex(string bName, string aName, string pName, string iDate, string rDate, string isbn, int index);
	void searchByIsbn(string isbn)const;
	void deleteBook(int index);
	void print()const;
};
