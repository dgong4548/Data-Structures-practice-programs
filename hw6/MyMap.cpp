#include "MyMap.h"
#include "Entry.h"

//inserts key-value pair into the map
void MyMap::insert(const string& key, int value)
{	
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through vector
        {
                list<Entry> temp = *it;								//remember which list is being looked at
                for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)		//loop through the list
                {
                        Entry s = *(it2);							//remember which Entry is being looked at
                        if(s.getKey() == key)							//if the Entry's key is the key being searched for
			{
                                s.setValue(value);						//set that found Entry's value to be parameter value
				return;						
			}	
                }
        }
        											//if no matching key was found in the map
	Entry s(key, value);									//create a new Entry with parameters
	list<Entry> temp2;									//create a new list of Entry objects

	temp2.push_back(s);									//add the Entry to the new list
	table.push_back(temp2);									//add the new list w/ the Entry into the vector
}

//returns true iff the map contains the key given as parameter
bool MyMap::containsKey(const string& key)
{
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through the vector
	{
		list<Entry> temp = *it;								//remember which list is being looked at
		for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)		//loop through the list
		{
			Entry s = *(it2);							//remember which Entry is being looked at
			if(s.getKey() == key)							//if the Entry's key is the key being searched for
				return true;							//true; the key is inside the map
		}
	}
	return false;										//return false if no matching key found in map
}

//returns true iff the map contains the value given as parameter
bool MyMap::containsValue(const int& value)	
{
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through the vector
        {
               	list<Entry> temp = *(it);							//remember which list is being looked at
               	for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)		//loop through the list
		{	
			Entry s = *(it2);							//remember which Entry is being looked at
                	if(s.getValue() == value)						//if the Entry's value is the value being searched for
                               return true;							//true; the value is inside the map
		}
        }
	return false;										//return false if no matching value found in map
}

//if key is in the map, remove the pair that contains it as the key
void MyMap::erase(const string& key)
{
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through the vector
        {
                list<Entry> temp = *it;								//remember which list is being looked at
                for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)		//loop through the list
                {
                        Entry s = *(it2);							//remember which Entry is being looked at
                        if(s.getKey() == key)							//if the Entry's key is the map...
                        {
				vector<list<Entry> >::iterator it3 = it;			//remember the position of this key in the vector of lists
				table.erase(it3);						//call vector's erase function on that position
			}
                }
        }
}

//
int MyMap::getValueOf(const string& key)
{ 
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through the vector
        {
                list<Entry> temp = *it;								//remember which list is being looked at
                for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)		//loop through the list
                {
                        Entry s = *(it2);							//remember which Entry is being looked at
                        if(s.getKey() == key)							//if the Entry's key matches the key parameter
                                return s.getValue();						//return that Entry's associated value
                }
        }

        string error = "Error. Cannot find key in the map.";					//if key couldn't be found
        throw error;										//throw exception
}

//
int& MyMap::operator[](const string& key)
{
	for(vector<list<Entry> >::iterator it = table.begin(); it != table.end(); it++)		//loop through
        {
                list<Entry> temp = *it;
                for(list<Entry>::iterator it2 = temp.begin(); it2 != temp.end(); it2++)
                {
                        Entry s = *(it2);
                        if(s.getKey() == key)
			{
				//int* test;
				//test = new int;
				//*test = s.getValue();
				//return *test;
				
                                return s.getValue();
			}
                }
        }

        Entry test(key);
	list<Entry> temp;
	temp.push_back(test);
	table.push_back(temp);
	
	return test.getValue();
} 

//returns the size of the map
int MyMap::size()										
{
	return table.size();									//return vector's size function
}

//returns whether or not the map is empty
bool MyMap::empty()
{
	return table.empty();									//return vector's empty function
}

//a hash function for this map implemented using a hash table
int MyMap::hash(const string& key)
{
	int sum = 0;										//declare a sum counter variable
	for(string::const_iterator it = key.begin(); it != key.end(); it++)			//iterate through a string's characters
		sum += (int)(*it);								//convert characters into ints; sum them into the counter

	return sum % table.size();								//return the remainder of sum / num of lists of Entries
}
