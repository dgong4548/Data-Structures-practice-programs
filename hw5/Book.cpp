#include "Book.h"

//Book constructor 
Book::Book(const string& title, const string& publisher, int yearOfPublication, string* authors, int numAuthors): title(title),
	publisher(publisher), year(yearOfPublication), authors(authors, authors + numAuthors) {}

//getter function to retrieve a Book's title (used in bookDatabase class)
string Book::getTitle(){ return title; }

//getter function to retrieve a Book's publisher (used in bookDatabase class)
string Book::getPublisher(){ return publisher; }

//getter function to retrieve a Book's year of publication (used in bookDatabase class)
int Book::getYear(){ return year; }

//getter function to retrieve a vector of a Book's authors (used in bookDatabase class)
vector<string> Book::getAuthors() {return authors; }

//overloaded == operator; returns true iff the titles of the two Books are the same
bool operator ==(const Book& b1,const  Book& b2)
{
	if(b1.title == b2.title)
		return true;
	else
		return false;
}

//overloaded < operator; returns true iff the title of Book1 is lexicographically before the title of Book2
bool operator <(const Book& b1, const Book& b2)
{
	if(b1.title < b2.title)
		return true;
	else
		return false;
}


