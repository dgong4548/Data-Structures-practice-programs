#ifndef LEXICON_H
#define LEXICON_H

#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Lexicon{
public:
	Lexicon();									//constructor creates an empty Lexicon

	Lexicon(const string& fileName);						//opens the associated file and stores all the words in the file into a Lexicon

	bool containsWord(const string& word);						//returns true if 'word' is in the Lexicon, and false otherwise 

	list<string> startWith(char ch);						//returns a list of words that start with the particular character, ch

	list<string> startWith(const string& prefix);					//returns a list of words that start with specified prefix

	list<string> endWith(char ch);							//returns a list of words that end with the particular character, ch

	list<string> endWith(const string& suffix);					//returns a list of words that end with the specified suffix

	void addWord(const string& str);						//adds 'str' to the Lexicon if it does not exist in it already

	void updateWord(const string& target, const string& replacement);		//changes the spelling of 'target' to become 'replacement'

	friend bool operator==(const Lexicon& d1, const Lexicon& d2);			//returns true iff d1 and d2 contain the same words

	friend ostream& operator<<(ostream& os, const Lexicon& d)			//printing operator to print out all words in a Lexicon
	{
		list<string>::const_iterator IT;
		for(IT = d.words.begin(); IT != d.words.end(); IT++)
			cout<<(*IT)<<endl;
		return os;
	}

private:

	list <string> words;

};

#endif
