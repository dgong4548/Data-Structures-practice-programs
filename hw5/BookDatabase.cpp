#include "BookDatabase.h"

//returns a reference to the Book object that contains the title parameter requested
Book& BookDatabase::searchByTitle(const string& title)
{
	map<string, Book>::iterator it = bookData.find(title);					//declare iterator to use find function on map
	if(it != bookData.end())								//if find was successful
		return (it -> second);								//return reference to the Book at the found iterator
	else if(it == bookData.end())								//if find was not successful
	{
		//cout<<"Unable to find book with given title in the database."<<endl;		
		string err = "Unable to find book with given title in the database.";		//throw error message
		throw err;
	}
}

//returns a set of Books by the given author
set<Book> BookDatabase::searchByAuthor(const string& author)
{
	set<Book> booksAuthor;									//declare a set of Books to be returned
	for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++)	//iterate through map
	{
		vector<string> temp = (it -> second).getAuthors();				//keep track of which authors vector is being looked at
								
		//inside the map iteration loop, loop secondly through the Book object's vector of authors
		for(vector<string>::iterator itVec = temp.begin(); itVec != temp.end(); itVec++)
			if(*(itVec) == author)							//if the parameter author is found in the vector
				booksAuthor.insert(it -> second);				//add the Book containing that author to the set
	}		
	return booksAuthor;									//return the set of Books
}

//returns a set of Books that were published before a given year
set<Book> BookDatabase::publishedBefore(int year)
{
	set<Book> booksBefore;									//declare a set of Books to be returned
	for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++)	//iterate through map
		if((it -> second).getYear() < year)						//if Book object's year @ iterator is < year parameter
			booksBefore.insert(it -> second);					//add the Book to the set
	return booksBefore;									//return the set of Books
}

//returns a set of Books that were published by the publisher parameter requested
set<Book> BookDatabase::searchByPublisher(const string& publisher)
{
	set<Book> booksPublisher;								//declare a set of Books to be returned
	for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++)	//iterate through map
		if((it -> second).getPublisher() == publisher)					//if Book object's published year @ iterator is < parameter
			booksPublisher.insert(it -> second);					//add the Book to the set
	return booksPublisher;									//return the set of Books
}

//adds a new Book to a Database if it is not there already
void BookDatabase::addBook(Book& book)
{
	pair<map<string, Book>::iterator, bool> result;						//declare a pair to check if insert was successful
	result = bookData.insert(pair<string, Book>(book.getTitle(), book));			//attempt to insert the parameter book into a bookDatabase
	if(result.second)									//if the insert was successful
		cout<<"Added "<<book.getTitle()<<" into database."<<endl<<endl;			//print a message that says "IT WORKED"
	else											//if the insert was not successful
		cout<<book.getTitle()<<" is already in database."<<endl<<endl;			//print a message that says "IT DIDN'T WORK"
}

//removes a Book from a Database if it is found
void BookDatabase::removeBook(const string& title)
{
	bool result;										//declare bool to determine print message
	for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++)	//iterate through map
		if((it -> second).getTitle() == title)						//if Book object's title @ iterator matches parameter
			result = bookData.erase(it -> first);					//set result equal to return value of erase 
	
	if(result)										//if return value for erase is 1
		cout<<"Removed book from database."<<endl<<endl;				//print a message that says "IT WORKED"
	else											//if return value for erase is 0
		cout<<"Book was not found in the database and not removed."<<endl<<endl;	//print a message that says "IT DIDN'T WORK"
}
