#include "Entry.h"

//creates an Entry with key set to the key parameter and value set to the value parameter
Entry::Entry(const string& key, int value): key(key), value(value) 
{
	
}

//getter for an Entry's key
string Entry::getKey()
{
	return key;
	 
}

//getter for an Entry's value
int& Entry::getValue()
{ 
	return value; 
}

//setter for an Entry's value
void Entry::setValue(int v)
{
	value = v;  
}

