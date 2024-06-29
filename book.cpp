#include "book.h"
book::book(string bName, string aName, string pName, string iDate, string rDate, string isbn) :ISBN(isbn), next(nullptr),previous(nullptr)
{
	bookName = bName;
	authorName = aName;
	publisherName = pName;
	issueDate = iDate;
	returDate = rDate;
}
void book::updateBook()
{
	cout << "Enter book name ";
	cin >> this->bookName;
	cout << "Enter author name ";
	cin >> this->authorName;
	cout << "Enter publisher name ";
	cin >> this->publisherName;
	cout << "Enter issue Date ";
	cin >> this->issueDate;
	cout << "Enter return Date ";
	cin >> this->returDate;
	cout << endl << "Book information updated " << endl;
}
void book::printBook()const
{
	cout << "bookName " << this->bookName << endl;
	cout << "authorName " << this->authorName << endl;
	cout << "publisherName " << this->publisherName << endl;
	cout << "issueDate " << this->issueDate << endl;
	cout << "returnDate " << this->returDate << endl;
	cout << "ISBN " << this->ISBN << endl;
	cout << endl;
}
