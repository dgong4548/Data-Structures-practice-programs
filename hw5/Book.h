#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book{
public:
	
	//constructor for a Book object		
	Book(const string& title, const string& publisher, int yearOfPublication, string* authors, int numAuthors);
	
	//getter function for title member variable (used in bookDatabase class)
	string getTitle();

	//getter function for publisher member variable (used in bookDatabase class)
	string getPublisher();

	//getter function for year member variable (used in bookDatabase class)
	int getYear();	
	
	//getter function for authors member variable (used in bookDatabase class)	
	vector<string> getAuthors();

	//overloaded == operator to compare if two Book objects are equivalent
	friend bool operator ==(const Book& book1, const Book& book2);	

	//overloaded < operator to compare which of two Book objects comes first
	friend bool operator <(const Book& book1, const Book& book2);

	//overloaded printing operator
	friend ostream& operator <<(ostream& os, const Book& b)
	{
		vector<string>::const_iterator it;
		os<<"Title: "<<b.title<<endl;

		os<<"Authors: ";

		for(it = b.authors.begin(); it != b.authors.end(); it++)
			os<<*(it)<<", ";

		os<<endl;
		
		os<<"Publisher: "<<b.publisher<<endl;	
		os<<"Year: "<<b.year<<endl<<endl;
		return os;
	}

private:
		
	//a Book's title
	string title;

	//a Book's publisher
	string publisher;

	//a Book's year of publication
	int year;

	//a vector of a Book's authors
	vector<string> authors;		

};

#endif

