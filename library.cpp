#include "library.h"
library::library() :head(nullptr) {}

void library::insertBookAtHead(string bName, string aName, string pName, string iDate, string rDate, string isbn)
{
	// create  new node
	book* newNode = new book(bName, aName, pName, iDate, rDate, isbn);
	// check if head is empyty
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		head->previous = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void library::insertBookAtTail(string bName, string aName, string pName, string iDate, string rDate, string isbn)
{
	// create new node
	book* newNode = new book(bName, aName, pName, iDate, rDate, isbn);
	// check if head is empty
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		// traverse node
		book* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		// move next which is pointing on null to newNode to add it to linked list  
		newNode->previous = temp;
		temp->next = newNode;
	}

}

void library::insertBookAtAnyIndex(string bName, string aName, string pName, string iDate, string rDate, string isbn, int index)
{
	// if index is equal to 1
	if (index == 1)
	{
		insertBookAtHead(bName, aName, pName, iDate, rDate, isbn);
		return;
	}
	// traversing linked list 
	book* temp = head;
	int count = 1;
	while (count < index - 1)
	{
		temp = temp->next;
		count++;
	}
	// if temp reached at last postion calling insertATTail funciton
	if (temp->next == nullptr)
	{
		insertBookAtTail(bName, aName, pName, iDate, rDate, isbn);
		return;
	}
	book* newBook = new book(bName, aName, pName, iDate, rDate, isbn);
	temp->next->previous = newBook;
	newBook->next = temp->next;
	newBook->previous = temp;
	temp->next = newBook;
}

void library::searchByIsbn(string isbn) const
{
	book* temp = head;
	bool isFound = false;
	while (temp != nullptr)
	{
		if (isbn == temp->ISBN)
		{
			cout << "Book found " << endl;
			cout << endl;
			temp->printBook();
			cout << endl;
			// to update book information 
			temp->updateBook();
			// after updating printing book information
			cout << endl;
			cout << "Book details after updating information ";
			temp->printBook();
			isFound = true;
			break;
		}
		else
			temp = temp->next;
	}
	if (!isFound)
		cout << "no book with this isbn is present";

}

void library::deleteBook(int index)
{
	// if head is equal to null
	if (head == nullptr) return;
	// if postion is 1;
	book* temp = head;
	if (index == 1)
	{
		head = head->next;
		if(head!=nullptr)
		head->previous = nullptr;
		delete temp;
		return;
	}
	else
	{
		int count = 1;
		while (count < index - 1 && temp != nullptr)
		{
			temp = temp->next;
			count++;
		}

		// check last
		if (temp == nullptr || temp->next == nullptr)
			return;

		book* nodeToDelete = temp->next;
		book* forward = nodeToDelete->next;
		temp->next = forward;
		if (forward != nullptr)
			forward->previous = temp;
		delete nodeToDelete;
	}
}

void library::print() const
{
	book* temp = head;
	while (temp != nullptr)
	{
		temp->printBook();
		temp = temp->next;
	}
	cout << endl;
}