#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <vector>
#include "Contact.h"

class ContactList{
public:
	
	ContactList();									//constructor for an empty Contact List

	ContactList(Contact* contacts, int numContacts);				//constructor to initialize a Contact list with a given array of Contacts and the array's size

	Contact& searchLast(string last);						//search for a Contact by last Name and return a reference to the Contact

	Contact& searchPhoneNum(string num);						//search for a Contact by phoneNum and return a reference to the Contact

	vector<Contact> allLastNameLetter(char letter);					//search for and return a vector of all Contacts whose last names begin with requested letter

	vector<Contact> allCity(string city);						//search for and return a vector of all Contacts who reside in city provided

	void addContact(Contact c);							//add a Contact to a ContactList vector

	int listSize()const;									//return the size of the ContactList

	void removeContactLastName(string last);					//erase a contact from the ContactList with the given last name

	Contact& operator[](int index);							//returns a Contact at a certain index in the ContactList 

	friend ostream& operator<<(ostream& os, ContactList& rhs);		//prints a ContactList

private:

	Contact c;	

	vector<Contact> list;								//a vector of Contact objects
};
#endif
