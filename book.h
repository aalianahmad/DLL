#pragma once
#include<iostream>
#include<string>
using namespace std;
class book
{
public:
	string bookName;
	string authorName;
	string publisherName;
	string issueDate;
	string returDate;
	const string ISBN;
	book* next;
	book* previous;
	book(string, string, string, string, string, string);
	void updateBook();
	void printBook()const;
};