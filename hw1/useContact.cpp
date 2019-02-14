//CISC 3130 TY9 - Professor Mermelstein
//Homework #1
//Danny Gong

#include <iostream>
#include <string>
#include "Contact.h"
using namespace std;

/* The following program is created to test each class function created in the header/implementation file for the Contact class */

int main()
{
	//test for Contact constructor where only the first name, last name, and phone number are entered by a user 
	Contact Person1("James", "Madison", "7189952254");

	//test accessor functions to retrieve the information provided by the user for the first contact  
	cout<<"-----Person 1-----"<<endl;
	cout<<"Contact's first and last name: <"<<Person1.getFirst()<<"> <"<<Person1.getLast()<<">"<<endl<<
		"Contact's phone number: <"<<Person1.getPhoneNum()<<">"<<endl<<endl;
	
	//test for Contact constructor where every member variable is provided by a user
	Contact Person2("Danny", "Gong", "7185679386", "5617 6 Ave", "Brooklyn", "New York");
	
	//test for function that prints all of a Contact's details
	cout<<"-----Person2-----"<<endl;
	cout<<Person2<<endl; 

	//test for Contact constructor where no details are provided by user
	Contact Person3;

	//expect to print out all of the "defaulted" information implemented for Constructor
	cout<<"-----Person 3-----"<<endl;
	cout<<Person3<<endl;

	//use the updateInfo function to change the previously defaulted contact information
	Person3.updateInfo("George", "Washington", "9109805966", "123 Sesame Street", "San Diego", "California");
	cout<<"-----Person 3 [Updated]-----"<<endl;
	cout<<Person3<<endl;		

	//test comparison operators(==, !=, <, >)
	Contact Person4("James", "Madison", "7189952254", "4425 Jabroni Avenue", "Miami", "Florida");
	cout<<"-----Person 4-----"<<endl;
	cout<<Person4<<endl;

	cout<<"Now comparing Person1 and Person4..."<<endl;
	if(Person1 == Person4)
		cout<<"The two contacts are the same."<<endl<<endl;			//expected outcome
	else
		cout<<"The two contacts are different."<<endl<<endl;
	
	cout<<"Now comparing Person1 and Person2..."<<endl;
	if(Person1 != Person2)
		cout<<"The two contacts are different."<<endl<<endl;			//expected outcome
	else
		cout<<"The two contacts are the same."<<endl<<endl;	

	cout<<"Now comparing Person1 and Person3..."<<endl;
	if(Person1 > Person3)
		cout<<"Person1 ("<<Person1.getFirst()<<" "<<Person1.getLast()<<") comes after Person3 ("<<
			Person3.getFirst()<<" "<<Person3.getLast()<<") in the Contact List."<<endl<<endl;
	else if(Person1 == Person3)
		cout<<"Person1 and Person3 are the same."<<endl<<endl;
	else
		cout<<"Person3 ("<<Person3.getFirst()<<" "<<Person3.getLast()<<") comes after Person1 ("<<
			Person1.getFirst()<<" "<<Person1.getLast()<<") in the Contact List."<<endl<<endl;	//expected outcome

	return 0;
}
