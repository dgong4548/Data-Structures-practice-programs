#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include <map>
#include <set>
#include <iostream>
#include "Book.h"
using namespace std;

class BookDatabase{
public:

	//returns a reference to a Book object that contains the given title
	Book& searchByTitle(const string& title);
	
	//returns a set of Books by the given author
	set<Book> searchByAuthor(const string& author);

	//returns a set of Books that were published before a given year
	set<Book> publishedBefore(int year);

	//returns a set of Books that were published by the given publisher
	set<Book> searchByPublisher(const string& publisher);	

	//adds a Book to a bookDatabase if it is not there already
	void addBook(Book& book);

	//removes a Book from a bookDatabase if it is found in there already
	void removeBook(const string& title);

	//overloaded printing operator to print out a bookDatabase
	friend ostream& operator <<(ostream& os, BookDatabase& bookDatabase)
	{
		for(map<string, Book>::iterator it = bookDatabase.bookData.begin(); it != bookDatabase.bookData.end(); it++)
			os<<it -> second;
		return os;
	}

private:
	
	//bookData maps string keys to Book-object values	
	map <string, Book> bookData;

};

#endif
