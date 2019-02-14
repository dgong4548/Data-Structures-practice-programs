#include "MyMap.h"
#include <iostream>

using namespace std;

int main()
{	
	MyMap w;								//create a new empty MyMap object
	
	w.insert("trick", 50);							//insert various key/value pairings into the MyMap object's vector
	w.insert("test", 999);	
	w.insert("fail", 20);
	w.insert("zoo", 22);
	w.insert("funnier", 25);
	
	cout<<"HERE IS THE INITIAL MAP OF KEYS AND THEIR ASSOCIATED VALUES:"<<endl;
	cout<<"---------------"<<endl;
	cout<<w;								//print the MyMap's contents after insertion
	cout<<"---------------"<<endl<<endl;


	cout<<"The size of the map is: "<<w.size()<<"."<<endl<<endl;		//test MyMap's size function; will print out 5
		
		
	if(!w.empty())								//test MyMap's empty function
		cout<<"The map is not empty."<<endl<<endl;			//expected output
	else
		cout<<"The map is empty."<<endl<<endl;


	cout<<"CHECKING IF THE KEY 'ZOO' IS IN THE MAP..."<<endl;
	if(w.containsKey("zoo"))						//test MyMap's containsKey function
		cout<<"The word 'zoo' is indeed in the map."<<endl<<endl;	//expected output
	else
		cout<<"The word 'zoo' is not in the map."<<endl<<endl;	

	cout<<"CHECKING IF THE KEY 'BRAIN' IS IN THE MAP..."<<endl;
        if(w.containsKey("brain"))
                cout<<"The word 'brain' is indeed in the map."<<endl<<endl;
        else
                cout<<"The word 'brain' is not in the map."<<endl<<endl;	//expected output

	
	cout<<"CHECKING IF THE VALUE '22' IS IN THE MAP..."<<endl;
        if(w.containsValue(22))							//test MyMap's containsValue function
                cout<<"The value '22' is indeed in the map."<<endl<<endl;	//expected output
        else
                cout<<"The value '22' is not in the map."<<endl<<endl;

	cout<<"CHECKING IF THE VALUE '0' IS IN THE MAP..."<<endl;
        if(w.containsValue(0))
                cout<<"The value '0' is indeed in the map."<<endl<<endl;
        else
                cout<<"The value '0' is not in the map."<<endl<<endl;		//expected output

	
	cout<<"ATTEMPTING TO RETRIEVE THE VALUE ASSOCIATED WITH THE KEY 'funnier'"<<endl;
	int value = w.getValueOf("funnier");					//test MyMap's getValueOf function
	cout<<"The value of the key 'funnier' is: "<<value<<"."<<endl<<endl;	//value will be assigned 25

	cout<<"ATTEMPTING TO RETRIEVE THE VALUE ASSOCIATED WITH THE KEY 'funny'"<<endl;
	try{ 
		int value2 = w.getValueOf("funny"); 
	}
	catch(const string& error){
		cerr<<error<<endl<<endl; 					//'funny' is not a key int the map
	}


	w["zoo"] = 1234;							//test MyMap's [] function to change zoo's value
	cout<<w<<endl;								//print out to see change


	cout<<"NOW REMOVING THE KEYS 'trick', 'test', 'fail', AND 'zoo' FROM THE MAP"<<endl<<endl;
	w.erase("trick");							//test MyMap's erase function 4x
	w.erase("test");
	w.erase("fail");
	w.erase("zoo");
	
	cout<<"THIS IS WHAT THE MAP LOOKS LIKE AFTER REMOVALS"<<endl;
	cout<<"---------------"<<endl;
	cout<<w;								//will just print the Entry of funnier-25
	cout<<"---------------"<<endl<<endl;
}
