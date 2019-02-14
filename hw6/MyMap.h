#ifndef MYMAP_H
#define MYMAP_H

#include "Entry.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class MyMap{

public:
	
	void insert(const string& key, int value);
	
	bool containsKey(const string& key);

	bool containsValue(const int& value);

	void erase(const string& key);

	int getValueOf(const string& key);

	int& operator[](const string& key);

	int size();

	bool empty();

	//an overloaded printing operator for a MyMap object (for a map)
	friend ostream& operator <<(ostream& os, const MyMap& m)
	{
		//loop through the vector
		for(vector<list<Entry> >::const_iterator it = m.table.begin(); it != m.table.end(); it++)	
		{
			list<Entry> temp = *(it);				//remember which list is being looked at

			//loop through the list
			for(list<Entry>::const_iterator it2 = temp.begin(); it2 != temp.end(); it2++)
			{ 
				Entry e = *(it2);				//remember which Entry is being looked at
			
				os<<e.getKey()<<" - "<<e.getValue()<<endl;	//output key & value
			}
		}
		return os;
	}
	
private:

	vector<list<Entry> > table;			//a hash table underlying structure for a map

	int hash(const string& key);			//a hash function to convert a key into an integer
};

#endif
