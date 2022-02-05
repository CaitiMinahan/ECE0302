#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
	//take the two vectors, loop through the size of currentStringVector and add words from currentStringVector to candidateStringVector 
	//individually until currentStringVector is empty (loop through it S times:

	//base case: when the candidate vector is empty -- use c++ notation for vectors (creds: geeksforgeeks)
	if(currentStringVector.empty()){ //once we have added all of the words from currentString to candidateString 
		//then we must make variable -> candidatestring by concatenating our candidateStringVector
		 
		//do concatenation here: 
		std::string candidateString = ""; //declare string for new concatenated candidateString (creds: stackedoverflow)
		for(int i=0; i<size; i++){ //might want to use c++ notation of vect.size(); !!!
			//candidateString += candidateStringVector[i];
			candidateString = Utils::join.(candidateStringVector[i].begin(), candidateStringVector[i].end(), ""); //should concatenate the candidateStringVector into new string variable 
		}
	//don't forget to convert every word in the vector to lowercase: 
	convertToLowerCase(candidateString); 

	//now test candidateString to see if you have a palindrome or not:
		if(isPalindrome(candidateString)==1){ //If you do have a palindrome in candidateStringVect,
			PalinCount++; //increase the current count of palindromes found
			//when implemented, call add vectovect method to add your newfound palindrome to the vect of palindromes 
		}
	}
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{	//constructor should define the size and count of the vector string 
	size = 0; 
	PalinCount = 0; 	
}

FindPalindrome::~FindPalindrome(){ //don't need to write anything b/c we aren't dealing with arrays or pointers
}

int FindPalindrome::number() const
{	//here we need to return the PalinCount variable:
	return PalinCount; 
	//return 10;
}

void FindPalindrome::clear()
{
	//delete all words from the string vector and reset the size and PalinCount variables: 
	size = 0; 
	PalinCount = 0; 
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

//add the isValid method, tests if the word we are adding is a valid entry 
//return true if we have a valid entry 
//will be useful in the add methods below
bool FindPalindrome::isValid(string & value){ 
	//ensure everything in this method makes sure that the given word entry will be valid to add 
	//in order for the word entry to be valid: 
	//	1) string must only be chars 
	//	2) we need to convert the word to all lowercase letters 
	//	3) we cannot add a duplicate word in the vector
	//perform these methods and then return true for a valid word entry 

	//test if entry is a string of only characters: DO THIS IN THE TEST CASE FILE TOO
	for(int i=0; i<size; i++){
		if(value[i]<'a' || value[i]>'z'){ //if any of the letters of the entry cannot be found in the ABCs
			return false; //then we can't add this word to our WordVect
		} 
	}
	//make sure entry is all lowercase letters by calling that method: TEST THIS IN THE TEST CASE FILE TOO 
	convertToLowerCase(value); //we don't want the entry to be a const string b/c we are changing it here 

	//check if the word already exists in the WordVect: WE CANNOT HAVE DUPLICATES!!!
	for(int i=0; i<size; i++){
		if(WordVect[i]==value){ //if the current already exists in the WordVect
			return false; 
		}
	}
	return true; //now we have a valid entry 
}

bool FindPalindrome::add(const string & value)
{	//before we add our word entry, let's make sure it is a valid entry: 

	//make a new variable for value since we need to call the isValid method: 
	std::string entry = value; 
	if(isValid(entry)==true){
		//a successful add would be the size of the word vector is incremented:
		WordVect.push_back(entry); //add the new string to the end of the word vector 
		size++; 
	}
	//call the recrusive findPalin method ???
	//recursiveFindPalindromes(value); ???
	return true; 
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	//a successful add would be the size is incremented:
	//add the new string to the end of the string vector 
	
	// if(isValid(stringVector)==1){ //if we are sending in a valid word 
	// 	for(int i=0; i<size(vector<string>stringVector); i++){ //find c++ keyword for getting size of a vector !!!
	// 		add(stringVector[i]); 
	// 	}
	// }
	
	//call the recrusive findPalin method
	
	return true; 
}

vector< vector<string> > FindPalindrome::toVector() const
{
	//returns the vector which collects all of the palindromes found from methods above 
	//how do I add to the returnThingie variable each time I find a Plaindrome? 
	//should I include the variable returnThingie in my isPalindrome function?
	vector<vector<string>> returnThingie;
	return returnThingie;
}

