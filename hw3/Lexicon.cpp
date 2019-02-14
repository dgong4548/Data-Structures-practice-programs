#include "Lexicon.h"
#include <vector> 

//constructor that allows a user to create an empty Lexicon
Lexicon::Lexicon(): words(){}

//constructor that opens a file called 'fileName', and stores all associated words in the file into a Lexicon
Lexicon::Lexicon(const string& fileName)
{
	string error = "Error. Attempted to read from a file that does not exist.\n";		//for throwing exception
	string line;										//store string read in from file

	ifstream infile;							
	infile.open(fileName.c_str());								//attempt to open the associated file
	if(infile.is_open())									//if successfully opened
	{
		cout<<"Successfully opened file "<<fileName<<endl;				//confirm that the file was opened
		while(getline(infile, line))							//proceed to read in words fromm file line by line
			words.push_back(line);							//for each read in string, add it to the list		

		cout<<"Successfully added words from "<<fileName<<" into Lexicon."<<endl<<endl;	//confirm that the words have been read in 
	}

	if(!infile.is_open())									//if unable to open the file
	{
		throw error;									//throw the exception string
		return;										//return without doing anything
	}

	infile.close();										//close
}	

//function that returns TRUE if 'word' is in the Lexicon, and FALSE otherwise
bool Lexicon::containsWord(const string& word)
{
	list<string>::iterator IT = words.begin();						//declare a string iterator to search through list
	while(IT != words.end())								//while the iterator is not at the end of the list
	{
		if(*IT == word)									//if the dereferenced string at the iterator matches the word parameter
			return true;								//return true 
		IT++;										//move the iterator forward through list (until end)
	}
	return false;										//if no match for a word in the Lexicon, return false
}

//function that returns a list of the words in a Lexicon that begin with a specified character
list<string> Lexicon::startWith(char ch)
{
	list<string> wordsStartWith;								//declare a new list 
	list<string>::iterator IT = words.begin();						//declare a string iterator to search for words that begin with character

	while(IT != words.end())								//iterate through list as long as within scope
	{
		if((*IT).find(ch) == 0)								//if the dereferenced string at the iterator starts with the requested character
			wordsStartWith.push_back(*IT);						//add it to the new list 
		IT++;
	}
	
	cout<<"Succesfully found all words that begin with '"<<ch<<"', returning list."<<endl<<endl;	
	return wordsStartWith;									//return the new list that contains the words that begin with character
}

//function that retusn a list of the words in a Lexicon that begin with a specified prefix
list<string> Lexicon::startWith(const string& prefix)
{
	list<string> wordsPrefix;								//declare a new list
	list<string>::iterator IT = words.begin();						//declare a string iterator to search for words that begin with specified prefix

	while(IT != words.end())								//iterate through list as long as within scope
	{
		if((*IT).find(prefix) == 0)							//if the dereferenced string at the iterator starts with the requested prefix
			wordsPrefix.push_back(*IT);						//add it to the new list
		IT++;
	}
	
	cout<<"Successfully found all words that begin with '"<<prefix<<"', returning list."<<endl<<endl;
	return wordsPrefix;									//return the new list that contains the words that begin with the prefix
} 

//function that returns a list of the words in a Lexicon that end with a specified character
list<string> Lexicon::endWith(char ch)
{
	list<string> wordsEndsWith;								//declare a new list
	list<string>::iterator IT = words.begin();						//declare a string iterator to search for words that end with character
	
	while(IT != words.end())								//iterate through list as long as within scope
	{
		int len = (*IT).length();							//variable len created to keep track of the index of last character in a string
		if((*IT).rfind(ch) == len - 1)							//if the dereferenced string at the iterator ends with the requested character
			wordsEndsWith.push_back(*IT);						//add it to the new list
		IT++;
	}

	cout<<"Successfully found all words that end with '"<<ch<<"', returning list."<<endl<<endl;
	return wordsEndsWith;									//return the new list that contains words that end with character
}

//function that returns a list of the words in a Lexicon that end with a specified suffix
list<string> Lexicon::endWith(const string& suffix)
{
	list<string> wordsSuffix;								//declare a new list
	list<string>::iterator IT = words.begin();						//declare a string iterator to search for words that end with specified suffix

	while(IT != words.end())								//iterate through list as long as within scope
	{
		if((*IT).length() >= suffix.length())						//make sure that original word is longer than the requested suffix being checked
		{
			if(0 == (*IT).compare((*IT).length() - suffix.length(), suffix.length(), suffix))	//compares the suffix and original words to make sure that the word does contain the suffix
				wordsSuffix.push_back(*IT);					//add it to the new list if the word contains the suffix
		}
		IT++;
	}
	cout<<"Successfully found all words that end with '"<<suffix<<"', returning list."<<endl<<endl;
	return wordsSuffix;									//return the new list that contains words that end with the requested suffix
}

//function that adds a word to a Lexicon (if it is not there already)
void Lexicon::addWord(const string& str)
{
	list<string>::iterator IT = words.begin();						//declare a string iterator to search through Lexicon's list of words
	while(IT != words.end())								//iterate through list as long as within scope
	{
		if((*IT) == str)								//if the dereferenced string at the iterator matches the requested word being added
		{
			cout<<"Error. Word already exists in this Lexicon."<<endl<<endl;	//output error in trying to add a word that already exists in a Lexicon
			return;
		}
		else
		{
			words.push_back(str);							//if the requested word is not already in a Lexicon, add it to the Lexicon
			cout<<"Successfully added '"<<str<<"' into this Lexicon."<<endl<<endl;	
			return;
		}
		IT++;					
	}
}

//function that updates a word in a Lexicon by changing target word's spelling to match replacement word's spelling
void Lexicon::updateWord(const string& target, const string& replacement)
{
	list<string>::iterator IT = words.begin();						//declare a string iterator to search through Lexicon's list of words
	while(IT != words.end())								//iterate through list as long as within scope
	{
		if((*IT) == target)								//if the dereferenced string at the iterator matches the requested target word
		{
			(*IT) = replacement;							//change the targeted string to become the replacement string
			cout<<"Successfully replaced '"<<target<<"' with '"<<replacement<<"' in this Lexicon."<<endl<<endl;
		}
		IT++;
	}
}

//function that returns true iff two Lexicon's contain the same words, not necessarily in the same order
bool operator==(const Lexicon& d1, const Lexicon& d2)
{
	if(d1.words.size() != d2.words.size())							//if the number of elements in both lists are already unequal
		return false;									//then the two lists are not equal by default

	vector <string> words1(d1.words.begin(), d1.words.end());				//creating vectors so that the list contents can be sorted
	vector <string> words2(d2.words.begin(), d2.words.end());				//via bubblesort
	
	//list<string>::const_iterator IT1 = d1.words.begin();				
	//list<string>::const_iterator IT2 = d2.words.begin();

	bool swapped = true;									//bool variables to maintain the bubblesort loop
	bool swapped2 = true;
	
	do											//sort the first Lexicon list of words accordingly										
	{	
		swapped = false;
		for(int i = 0; i < words1.size() - 1; i++)		
		{
			if(words1[i] > words1[i+1])
			{
				swap(words1[i], words1[i+1]);
				swapped = true;
			}
		}	
	} while(swapped);

	do											//sort the second Lexicon list of words accordingly
	{
		swapped2 = false;
		for(int i = 0; i < words2.size() - 1; i++)
		{
			if(words2[i] > words2[i+1])
			{
				swap(words2[i], words2[i+1]);
				swapped2 = true;
			}
		}
	} while(swapped2);

	for(int i = 0; i < words1.size(); i++)							//both Lexicon lists (and vectors) are the same size....
	{		
		if(words1[i] != words2[i])							//compare the indices of both vectors of words, if one of them mismatches
			return false;								//then both Lexicons are not equal
	}
	return true;										//both Lexicons are equal if after sorting, all the words in corresponding indices match up
}
