#include "Book.h"
#include "BookDatabase.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
		//creating several arrays/vectors of strings to create some Book objects
        vector<string> authors1;
        authors1.push_back("William Topp");
        authors1.push_back("William Ford");

        vector<string> authors2;
        authors2.push_back("Dave Pilkey");
        authors2.push_back("R.L. Stein");
        authors2.push_back("William Ford");

        string authors3[2] = {"Flub Dub", "Greek Man"};

	vector<string> authors4;
	authors4.push_back("Springer");
	authors4.push_back("Gerald");

	string authors5[1] = {"McConnel"};

	string authors6[1] = {"Solo"};

		//testing Book constructor by creating varying Book objects
	cout<<"-----CREATING SEVERAL BOOK OBJECTS-----"<<endl<<endl;
        Book book1("Data Structures With C++ Using STL", "Prentice Hall", 2002, &authors1.front(), authors1.size());
        Book book2("Goosebump Underpants", "Wiley and Sons", 1977, &authors2.front(), authors2.size());
        Book book3("They Took Er Jerbs", "What Publisher?", 2005, authors3, 2);
	Book book4("Libro Quatro", "Quienes Publishas", 2012, &authors4.front(), 2);
	Book book5("Computer Graphics", "Wiley and Sons", 2012, authors5, 1);
	Book book6("They Took Er Jerbs", "That Publisher", 2005, authors6, 1);

	
		//testing the BookDatabase function addBook to add all the previously created Books into a BookDatabase
        BookDatabase database;
        cout<<"-----ATTEMPTING TO ADD CREATED BOOKS INTO A DATABASE-----"<<endl<<endl;
        database.addBook(book1);
        database.addBook(book2);
        database.addBook(book3);
        database.addBook(book4);
        database.addBook(book5);
        database.addBook(book6);										//won't be added


		//testing the BookDatabase overloaded << operator
        cout<<"-----HERE ARE ALL THE BOOKS THAT WERE ADDED INTO THE DATABASE-----"<<endl<<endl;
        cout<<database;

	
		//testing the overloaded < operator for Book objects
        cout<<"-----CHECKING WHICH BOOK IS LEXICOGRAPHICALLY BEFORE THE OTHER BETWEEN BOOK1 AND BOOK2-----"<<endl<<endl;
        if(book1 < book2)
                cout<<"\""<<book1.getTitle()<<"\" comes before \""<<book2.getTitle()<<"\"."<<endl<<endl;	//expected outcome
        else
                cout<<book2.getTitle()<<" comes before "<<book1.getTitle()<<"."<<endl<<endl;


		//testing the overloaded == operator for Book objects (equivalent case)
        cout<<"-----CHECKING IF BOOK3 AND BOOK6 ARE EQUIVALENT-----"<<endl<<endl;
        if(book3 == book6)
                cout<<"Both books are titled \""<<book3.getTitle()<<"\" and therefore are equal."<<endl<<endl;	//expected outcome
        else
                cout<<"The two books do not have the same title and therefore are not equal."<<endl<<endl;

		//testing the overloaded == operator for Book objects (non-equivalent case)
	cout<<"-----CHECKING IF BOOK1 AND BOOK5 ARE EQUIVALENT-----"<<endl<<endl;
	if(book1 == book5)
                cout<<"Both books are titled \""<<book1.getTitle()<<"\" and therefore are equal."<<endl<<endl;
        else
                cout<<"The two books do not have the same title and therefore are not equal."<<endl<<endl;	//expected outcome


		//testing the BookDatabase function searchByTitle (success)
	cout<<"-----LOOKING FOR A BOOK WITH THE TITLE 'LIBRO QUATRO' IN THE DATABASE-----"<<endl<<endl;
	cout<<database.searchByTitle("Libro Quatro");
	
		//testing the BookDatabase function searchByTitle (no success)
	cout<<"-----LOOKING FOR A BOOK WITH THE TITLE 'QUATRO LIBRO' IN THE DATABASE-----"<<endl<<endl;
	try{ 
		cout<<database.searchByTitle("Quatro Libro");
	}
	catch(const string& error){										//expected error catch
		cerr<<error<<endl<<endl;
	}

	
		//testing the BookDatabase function searchByAuthor (success)
	cout<<"-----LOOKING FOR BOOK(S) WRITTEN BY WILLIAM FORD-----"<<endl<<endl;
        set<Book> booksReturn = database.searchByAuthor("William Ford");
        if(!booksReturn.empty())										//expected outcome
                for(set<Book>::iterator itAuthor = booksReturn.begin(); itAuthor != booksReturn.end(); itAuthor++)
                        cout<<*(itAuthor);
        else
                cout<<"No books written by requested author."<<endl;

		//testing the BookDatabase function searchByAuthor (no success)
	cout<<"-----LOOKING FOR BOOK(S) WRITTEN BY MIKE HAWK-----"<<endl<<endl;
	set<Book> booksReturn2 = database.searchByAuthor("Mike Hawk");
	if(!booksReturn2.empty())
                for(set<Book>::iterator itAuthor2 = booksReturn2.begin(); itAuthor2 != booksReturn2.end(); itAuthor2++)
                        cout<<*(itAuthor2);
        else
                cout<<"No books written by requested author."<<endl<<endl;					//expected outcome

	
		//testing the BookDatabase function publishedBefore 
	cout<<"-----LOOKING FOR BOOK(S) WRITTEN BEFORE 2012-----"<<endl<<endl;
	set<Book> booksBefore = database.publishedBefore(2012);
	for(set<Book>::iterator itb4 = booksBefore.begin(); itb4 != booksBefore.end(); itb4++)
		cout<<*(itb4); 


		//testing the BookDatabase function searchByPublisher (success)
	cout<<"-----LOOKING FOR BOOK(S) PUBLISHED BY WILEY AND SONS-----"<<endl<<endl;
	set<Book> booksPub = database.searchByPublisher("Wiley and Sons");
	if(!booksPub.empty())											//expected outcome
		for(set<Book>::iterator itPub = booksPub.begin(); itPub != booksPub.end(); itPub++)
			cout<<*(itPub);
	else
		cout<<"No books written by requested publisher."<<endl<<endl;

		//testing the BookDatabase function searchByPublisher (no success)
	cout<<"-----LOOKING FOR BOOK(S) PUBLISHED BY LOCAL PUBLISHER-----"<<endl<<endl;
	set<Book> booksPub2 = database.searchByPublisher("Local Publisher");
	if(!booksPub2.empty())
		for(set<Book>::iterator itPub2 = booksPub2.begin(); itPub2 != booksPub2.end(); itPub2++)
			cout<<*(itPub2);
	else													//expected outcome
		cout<<"No books written by requested publisher."<<endl<<endl;


		//testing the BookDatabase function to remove some Books from the BookDatabase
	cout<<"-----ATTEMPTING TO REMOVE 'DATA STRUCTURES WITH C++ USING STL' FROM THE DATABASE-----"<<endl<<endl;
	database.removeBook("Data Structures With C++ Using STL"); 
	
	cout<<"-----ATTEMPTING TO REMOVE 'COMPUTER GRAPHICS' FROM THE DATABASE-----"<<endl<<endl;
	database.removeBook("Computer Graphics");								

	cout<<"-----ATTEMPTING TO REMOVE 'UNNAMED BOOK' FROM THE DATABASE-----"<<endl<<endl;
	database.removeBook("Unnamed Book");									//this book doens't exist

		//confirm that a Book was indeed removed from above code by searching for it by title
	cout<<"-----LOOKING FOR A BOOK WITH THE TITLE 'COMPUTER GRAPHICS' IN THE DATABASE-----"<<endl<<endl;
	try{
                cout<<database.searchByTitle("Computer Graphics");
        }
        catch(const string& error){                                                                             //expected error catch
                cerr<<error<<endl<<endl;
        }
}
