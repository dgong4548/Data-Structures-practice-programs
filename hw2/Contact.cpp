#include "Contact.h"
#include <iostream>
#include <string>
using namespace std;

//this constructor initializes a new Contact object with all provided data 
Contact::Contact(string first, string last, string num, string address, string city, string state): first(first), last(last), phoneNum(num), address(address), city(city), state(state){}

//this constructor initilizes a new Contact object with only the first name, last name, and phone number provided
Contact::Contact(string first, string last, string num): first(first), last(last), phoneNum(num){}

//this default constructor initializes a new Contact object when no parameters are provided
Contact::Contact(): first("John"), last("Doe"), phoneNum("1234567890"), address("0000 Main Street"), city("Brooklyn"), state("New York"){}

//accessor for first name
string Contact::getFirst(){
	return first;
}

//accessor for last name
string Contact::getLast(){
	return last;
}

//accessor for phone number
string Contact::getPhoneNum(){
	return phoneNum;
}

//accessor for address
string Contact::getAddress(){
	return address;
}

//accessor for city
string Contact::getCity(){
	return city;
}

//accessor for state
string Contact::getState(){
	return state;
}

//function updates and changes all of a Contact's information
Contact& Contact::updateInfo(string first, string last, string num, string address, string city, string state)
{
	this->first=first;
	this->last=last;
	this->phoneNum=num;
	this->address=address;
	this->city=city;
	this->state=state;
	return *this;
} 

//overloaded == operator
bool operator==(Contact& person1, Contact& person2)
{
	if((person1.first == person2.first) && (person1.last == person2.last))	//if both Contacts have same first & last name
		return true;							//report true, they are the same
	else									//otherwise, they are different people
		return false;
}

//overloaded < operator
bool operator<(Contact& person1, Contact& person2)
{
	if(person1.last < person2.last)						//if person1's last name comes first
		return true;						
	else if(person1.last == person2.last)					//if person1 and person2 last names are same
	{									//then compare their first names
		if(person1.first < person2.first)				//if person1's first name comes first 
			return true;
		else								//else, if person2's first name comes first
			return false;
	}
	else									//else, if person2's last name comes first
		return false;
}

//overloaded != operator
bool operator!=(Contact& person1, Contact& person2)
{
	if((person1.first == person2.first) && (person1.last == person2.last))	//if both Contacts have the same name
		return false;							//report false, they are in fact equal
	else																
		return true;
}

//overloaded > operator
bool operator>(Contact& person1, Contact& person2)
{
	if(person1.last > person2.last)						//if person1's last name comes after person2's
		return true;							//report true
	else if(person1.last == person2.last)					//if both last names are the same
	{									//then compare their first names
		if(person1.first > person2.last)				//if person1's first name comes after person2's
			return true;						//report true
		else						
			return false;						//otherwise, false
	}
	else									//if person2's last name comes after person1's
		return false;
}

//overloaded << stream operator
ostream& operator<<(ostream& os, Contact& person)
{
	os<<"<"<<person.first<<"> <"<<person.last<<">	"<<"Phone number: <"<<person.phoneNum<<">"<<endl<<
		"<"<<person.address<<">"<<endl<<
		"<"<<person.city<<"> <"<<person.state<<">"<<endl;
	return os;
}
