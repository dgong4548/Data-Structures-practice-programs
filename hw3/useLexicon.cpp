//CISC 3130
//Professor Mermelstein
//Homework #3
//Danny Gong

#include "Lexicon.h"

int main()
{
		//testing the constructor for creating a Lexicon by adding words into it from an EXISTING file
	cout<<"-----ATTEMPTING TO CREATE A LEXICON FROM AN EXISTING FILE...-----"<<endl;
	Lexicon lex1("listOfWords1.txt");							//create a Lexicon called lex1
	Lexicon lex2("listOfWords2.txt");							//create a Lexicon called lex2


		//testing the constructor for creating a Lexicon by adding words into it from a file that DOES NOT EXIST
	try{
		cout<<"-----ATTEMPTING TO CREATE A LEXICON FROM A NON-EXISTANT FILE...-----"<<endl;
		Lexicon lex2("listOfWords3.txt");						//expected error catch
	}
	catch(const string& error){
		cout<<error<<endl;
	}


		//testing the function to print a Lexicon's contents (in no particular order)
	cout<<"-----HERE ARE THE WORDS CONTAINED IN LEX1-----"<<endl;
	cout<<lex1<<endl;									//print out the words in lex1


		//testing the function to determine if two lists contain equivalent data (not necessarily in same order)
	cout<<"-----COMPARING LEX1 AND LEX2 TO SEE IF BOTH LEXICONS CONTAIN THE SAME WORDS-----"<<endl;
	if((lex1 == lex2) == true)								//both Lexicons unchanged, expected outcome
		cout<<"The two Lexicons contain the exact same words AND amount of words."<<endl<<endl;		
	else											
		cout<<"The two Lexicons do not contain the exact same words."<<endl<<endl;
			

		//testing the function to add a word to a Lexicon
	cout<<"-----ATTEMPTING TO ADD WORD 'alaska' TO LEX1-----"<<endl;
	lex1.addWord("alaska");									//add the word 'alaska' to word list of lex1

	cout<<"-----COMPARING LEX1 AND LEX2 TO SEE IF BOTH LEXICONS CONTAIN THE SAME WORDS-----"<<endl;		//test == with changed Lexicon
	if((lex1 == lex2) == true)
		cout<<"The two Lexicons contain the exact same words AND amount of words."<<endl<<endl;
	else											//now Lex1 has one more word, expected outcome
		cout<<"The two Lexicons do not contain the exact same words."<<endl<<endl;


		//testing the function to update a word in a Lexicon
	cout<<"-----ATTEMPTING TO UPDATE LEX1 BY REPLACING 'abduct' WITH 'dinosaur'-----"<<endl;
	lex1.updateWord("abduct", "dinosaur");							//replace the word 'abduct' with the word 'dinosaur' in lex1

	
		//testing the function that searches a Lexicon for a word and returns true if found within (false otherwise)
	cout<<"-----ATTEMPTING TO SEARCH LEX1 FOR THE WORD 'abandonedly'...-----"<<endl;
	if(lex1.containsWord("abandonedly") == true)						//lex1 actually contains the word 'abandonedly', expected outcome
		cout<<"Yes. Lexicon lex1 contains the word 'abandonedly'."<<endl<<endl;
	else
		cout<<"No. Lexicon lex1 does not contain the word 'abandonedly'."<<endl<<endl;

		//testing the function that returns a list of words in a Lexicon that begin with a specified character
	cout<<"-----ATTEMPTING TO SEARCH LEX1 FOR ALL WORDS THAT BEGIN WITH 2 ...-----"<<endl;
	list<string> lexBeginWith = lex1.startWith('2');					//create a list of strings to store words from lex1 that begin with '2'
	cout<<"Here are all the words in lex1 that begin with 2:"<<endl<<endl;
	
	list<string>::iterator beginIT = lexBeginWith.begin();					//create an iterator for list of words that begin with '2'
	while(beginIT != lexBeginWith.end())
	{
		cout<<(*beginIT)<<endl;								//print out all such words
		beginIT++;
	}
	cout<<endl;

		//testing the function that returns a list of words in a Lexicon that begin with a specified prefix	
	cout<<"-----ATTEMPTING TO SEARCH LEX1 FOR ALL WORDS THAT START WITH THE PREFIX 'abd'-----"<<endl;
	list<string> lexPrefix = lex1.startWith("abd");						//create a list of strings to store words from lex1 that start with 'abd'
	cout<<"Here are all the words in lex1 that begin with 'abd':"<<endl<<endl;
	
	list<string>::iterator prefixIT = lexPrefix.begin();					//create an iterator for list of words that begin with 'abd'
	while(prefixIT != lexPrefix.end())
	{
		cout<<(*prefixIT)<<endl;							//print out all such words
		prefixIT++;
	}
	cout<<endl;

		//testing the function that returns a list of words in a Lexicon that end with a specified character
	cout<<"-----ATTEMPTING TO SEARCH LEX1 FOR ALL WORDS THAT END WITH 's'-----"<<endl;
	list<string> lexEndWith = lex1.endWith('s');						//create a list of strings to store words from lex1 that end in 's'
	cout<<"Here are all the words in lex1 that end with 's':"<<endl<<endl;
	
	list<string>::iterator endIT = lexEndWith.begin();					//create an iterator for list of words that end with 's'
	while(endIT != lexEndWith.end())
	{
		cout<<(*endIT)<<endl;								//print out all such words
		endIT++;
	}
	cout<<endl;

		//testing the function that returns a list in a Lexicon that end with a specified suffix
	cout<<"-----ATTEMPTING TO SEARCH LEX1 FOR ALL WORDS THAT END WITH 'ing'-----"<<endl;
	list<string> lexSuffix = lex1.endWith("ing");						//create a list of strings to store words from list1 that end in 'ing'
	cout<<"Here are all the words in lex1 that end with 'ing':"<<endl<<endl;

	list<string>::iterator suffixIT = lexSuffix.begin();					//create an iterator for list of words that end with 'ing'
	while(suffixIT != lexSuffix.end())
	{
		cout<<(*suffixIT)<<endl;							//print out all such words
		suffixIT++;
	}
	cout<<endl;	
}
