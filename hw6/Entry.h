#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
using namespace std;

class Entry{
public:		
		
	Entry(const string& key, int value=0);
	
	string getKey();

	int& getValue();

	void setValue(int v);

private:

	int value;

	string key;
};

#endif
