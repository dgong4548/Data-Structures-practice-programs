//CISC 3130
//Professor Mermelstein
//Homework #2
//Danny Gong

#include <iostream>
#include "Contact.h"
#include "ContactList.h"

using namespace std;

int main()
{
	Contact person1("First", "Last", "6464452280", "225 Vermont Ave", "Manhattan", "New York");		//create several contacts to add to a ContactList
	Contact person2("Primero", "Segundo", "7186632458", "330 Bedford Avenue", "Brooklyn", "New York");	
	Contact person3("Ben", "Jamin", "1234567890", "101 20th Street", "Queens", "New York");			
	Contact person4("Frank", "Lopez", "6462251382", "8423 Main Street", "Las Vegas", "Nevada");		
	Contact person5("Andrew", "Li", "9175481234", "5617 8th Avenue", "Brooklyn", "New York");

	Contact people[] = {person1, person2, person3, person4, person5};					//create an array of the contacts
	ContactList peopleList(people, 5);									//create a ContactList from the array of contacts
	
	
		//test the function to search for a Contact by last name
	cout<<"---Attempting to search ContactList for person with last name 'Jamin'---"<<endl<<endl;			
	Contact lastFound = peopleList.searchLast("Jamin");							//assign a found Contact from list into lastFound
	cout<< lastFound <<endl;										//print the found Contact

		//test the function to search for a Contact by last name (that does not exist)				
	cout<<"---Attempting to search ContactList for a person with last name 'Rhodes'---"<<endl<<endl;	
	Contact lastNotFound = peopleList.searchLast("Rhodes");							//someone with last name Rhodes does not exist (a default Contact returned)
	cout<<endl;
	
		//test the function to search for a Contact by phone number
	cout<<"---Attempting to search ContactList for person with phone number '7186632458'---"<<endl<<endl;	
	Contact numFound = peopleList.searchPhoneNum("7186632458");						//assign a found Contact from list into numFound
	cout<< numFound <<endl;											//print the found Contact

		//test the function to search for a Contact by phone number (that does not exist)
	cout<<"---Attempting to search ContactList for person with phone number '0000000000'---"<<endl<<endl;	
	Contact numNotFound = peopleList.searchPhoneNum("0000000000");						//someone with phone number 0000000000 does not exist (default Contact returned)
	cout<<endl;
	
		//test the function to search for and return a VECTOR containing all contacts whose last name begins with a certain letter
	cout<<"---Attempting to search ContactList for all persons whose last name starts with 'L'---"<<endl<<endl;	
	vector<Contact> peopleLastName = peopleList.allLastNameLetter('L');					//create a vector to store all persons with last name starting with 'L'
	for(int i=0; i<peopleLastName.size(); i++)								//use the Contact << operator to print out the vector
		cout<<peopleLastName[i]<<endl;									//(not a ContactList so not using the ContactList << operator)

		//test the function to search for and return an empty vector of contacts whose last name begin with a certain letter
	cout<<"---Attempting to search ContactList for all persons whose last name starts with 'Z'---"<<endl<<endl;
	vector<Contact> peopleLastNameZ = peopleList.allLastNameLetter('Z');
	if(peopleLastNameZ.size() == 0)
		cout<<"The vector containing all Contacts whose last name starts with 'Z' is empty."<<endl<<endl;
	
		//test the function to search for and return a VECTOR containing all contacts who live in a particular city
	cout<<"---Attempting to search ContactList for all persons who live in 'Brooklyn'---"<<endl<<endl;	
	vector<Contact> peopleCity = peopleList.allCity("Brooklyn");						//create a vector to store all persons who live in 'Brooklyn'
	for(int i=0; i<peopleCity.size(); i++)									//print all Contacts that live in Brooklyn
		cout<<peopleCity[i]<<endl;

		//test the function to search for and return an empty vector of contacts who live in a particular city
	cout<<"---Attempting to search ContactList for all persons who live in 'Chicago'---"<<endl<<endl;
	vector<Contact> peopleChicago = peopleList.allCity("Chicago");						//create a vector to store all persons who live in 'Chicago'
	if(peopleChicago.size() == 0)										//if the vector is empty (it should be)
		cout<<"The vector containing all Contacts who live in 'Chicago' is empty."<<endl<<endl;		//confirm empty vector

		//test the function to add a Contact to a ContactList	
	Contact person6("George", "Pastrami", "2124446582", "64 Palm Street", "Los Angeles", "California");	//creates a new Contact to add to list
	peopleList.addContact(person6);										//use the addContact function to add to ContactList
	cout<<person6.getFirst()<<" "<<person6.getLast()<<" has been added to the ContactList."<<endl<<endl;	//confirm that a new Contact was added successfully
	
		//test the function to add a Contact if a Contact already exists
	cout<<"---Attempting to add "<<person6.getFirst()<<" "<<person6.getLast()<<" into ContactList---"<<endl<<endl;
	peopleList.addContact(person6);										//will return error message saying Contact already exists

		//test the overloaded [] operator on ContactList
	cout<<"---Attempting to retrieve and print the '2nd' Contact in the ContactList---"<<endl<<endl;
	cout<<peopleList[1]<<endl;										//will print out Primero Segundo's information

		//test the overloaded [] operator on ContactList out of bound
	cout<<"---Attempting to retrieve and print the '10th' Contact in the ContactList---"<<endl<<endl;	
	try{
		cout<<peopleList[9]<<endl;
	}
	catch(const string& error){										//will catch string error that searching out of bounds
		cout<<error<<endl;
	}	

		//test the function to print out the size of a ContactList
	cout<<"---Attempting to retrieve the size of ContactList---"<<endl<<endl;				
	cout<<"There are "<<peopleList.listSize()<<" contacts in this ContactList"<<endl<<endl;			//print out the number of Contacts in ContactList

		//test the function to erase a Contact from a ContactList based on a last name
	cout<<"---Attempting to erase a Contact from the ContactList---"<<endl<<endl;
	peopleList.removeContactLastName("Lopez");								//remove Contact w/ last name Lopez from ContactList

		//print out an updated ContactList after a Contact was removed
	cout<<"---Now printing out ContactList after a Contact was removed---"<<endl<<endl;			
	cout<<peopleList<<endl;											//print out a ContactList using the ContactList << operator
		
	cout<<"Now there are "<<peopleList.listSize()<<" contacts in this ContactList"<<endl<<endl;		//confirm that a Contact has been removed
}
