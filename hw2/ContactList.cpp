#include "ContactList.h"
#include <iostream>
using namespace std;

//function that creates an empty Contact List
ContactList::ContactList(): list(){}


//constructor that uses an array of Contacts and the size of the array in order to intialize a ContactList
ContactList::ContactList(Contact* contacts, int numContacts): list(contacts, contacts + numContacts){}


//search for a Contact by last name and if found, return a reference to the Contact
Contact& ContactList::searchLast(string last)
{
	for(int i = 0; i < list.size(); i++)			//loop through the ContactList
	{
		if(list[i].getLast() == last)			//check if Contact's last name matches the parameter
			return list[i];				//store the Contact
	}
	cout<<"---ERROR. No contact with the provided last name.---"<<endl<<endl;
	return c;						//if no person found with last name, return sentinel (default Contact)
}


//search for a Contact by phone number and if found, return a reference to the Contact 
Contact& ContactList::searchPhoneNum(string num)
{
	for(int i = 0; i < list.size(); i++)			//loop through the ContactList
	{
		if(list[i].getPhoneNum() == num)		//check if Contact's phone number matches the parameter
			return list[i];				//store the Contact
	}
	cout<<"---ERROR. No contact with the provided phone number.---"<<endl<<endl;		
	return c;						//if no person found with the phone number, return sentinel (default Contact)
}


//return a ContactList of all Contacts whose last names all begin with a requested letter
vector<Contact> ContactList::allLastNameLetter(char letter)
{
	vector<Contact> letterPeople;				//new empty ContactList stores Contacts whose last name start with given letter	

	for(int i = 0; i < list.size(); i++)			//loopthrough the ContactList being searched
	{
		if(list[i].getLast().find(letter) == 0)		//if in the list someone's last name starts with given character
			letterPeople.push_back(list[i]);	//add the person to the new ContactList vector
	}
	return letterPeople;					//return the new vector of everyone whose last name starts with character
}


//return a ContactList of all Contacts who reside in the provided city, or an empty vector if nobody found
vector<Contact> ContactList::allCity(string city)
{
	vector<Contact> cityPeople;				//new empty ContactList stores Contacts in given city
	for(int i = 0; i < list.size(); i++)			//loop through the ContactList being searched 
	{
		if(list[i].getCity() == city)			//if in the list someone's city matches parameter
			cityPeople.push_back(list[i]);		//add the person to the new ContactList vector
	}

	return cityPeople;					//return the new vector of everyone in given city
}	


//add a Contact to a ContactList 
void ContactList::addContact(Contact c)
{
	for(int i = 0; i < list.size(); i++)			//loop through the ContactList
	{
		if(list[i] == c)				//if Contact already exists	
		{
			cout<<"Error. Contact already exists."<<endl<<endl;	//display error (admittedly I could throw exception...)
			return;							//leave function
		}
	}
	list.push_back(c);					//otherwise, add contact to ContactList
}


//return the size of the ContactList
int ContactList::listSize()const
{
	return list.size();					//retrieve the size of the ContactList
}


//erase a Contact from the ContactList with a provided last Name
void ContactList::removeContactLastName(string last)
{
	int position;						//store index of someone about to be removed
	for(int i = 0; i < list.size(); i++)			//loop through the list of Contacts
	{
		if(list[i].getLast() == last)			//if a Contact's last name matches
			position = i;				//store the Contact's index in position
	}
	list.erase(list.begin() + position);			//erase the Contact based on ContactList index
}


//return a Contact at a given index in the ContactList
Contact& ContactList::operator[](int index)
{
	string invalid = "Error. Attempted to search vector out of bounds.";		//error checking
	if(index < 0 || index >= list.size())			//if attempting to search out of bound
		throw invalid;					//throw error message

	return list[index];					
}


//printing function to print out a ContactList
//*NOTE: Professor, this printing function works if I remove const from the parameter 'ContactList& rhs', but I don't know the reason 
ostream& operator<<(ostream& os, ContactList& rhs)
{
	for(int i = 0; i < rhs.listSize(); i++)			//loop through the vector
		os<<rhs.list[i]<<endl;				//print each Contact using the Contact << operator

	return os;
}

