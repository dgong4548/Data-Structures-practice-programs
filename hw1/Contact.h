#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact
{
public:
	Contact(string first, string last, string num, string address, string city, string state);

	Contact(string first, string last, string num);

	Contact();

	string getFirst();

	string getLast();

	string getPhoneNum();

	string getAddress();

	string getCity();

	string getState();

	Contact& updateInfo(string first, string last, string num, string address, string city, string state);

	friend bool operator==(Contact& person1, Contact& person2);

	friend bool operator<(Contact& person1, Contact& person2);

	friend bool operator!=(Contact& person1, Contact& person2);

	friend bool operator>(Contact& person1, Contact& person2);

	friend ostream& operator<<(ostream& os, Contact& person);

private:
	string first;
		
	string last;

	string phoneNum;

	string address;

	string city;

	string state;
};
#endif
