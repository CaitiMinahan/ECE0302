#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <algorithm>
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
{	//take the two vectors, loop through the size of currentStringVector and add words from currentStringVector to candidateStringVector 
	//individually until currentStringVector is empty:

	//temporary variables:  
	std::string candidateString;
	std::string candidatestring_lower; 
	
	if(!cutTest2(candidateStringVector, currentStringVector)){
		return; 
	}
	for(int i=0; i<currentStringVector.size(); i++){
		candidateStringVector.push_back(currentStringVector.at(i)); 
		currentStringVector.erase(currentStringVector.begin()+i); //erases element at index i
		recursiveFindPalindromes(candidateStringVector, currentStringVector); 

		currentStringVector.insert(currentStringVector.begin()+i, candidateStringVector.back()); 
		candidateStringVector.pop_back(); 
	}
	//base case: when the candidate vector is empty -- use c++ notation for vectors (creds: geeksforgeeks)
	if(currentStringVector.empty()){ //once we have added all of the words from currentString to candidateString 		 
		for(int i=0; i<candidateStringVector.size(); i++){ 
			candidateString = candidateStringVector[i]; //copy values from the candidateStringVector into new string
			convertToLowerCase(candidateString); //convert everything in new string to be lowercase  
			candidatestring_lower += candidateString; //concatenate onto the lowercase version 
		}
		if(isPalindrome(candidatestring_lower)){
			PalinCount++; 
			PalinVect.push_back(candidateStringVector); 
		}
	return; 
	}
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
	//std::cout << "caitiminahan"; 
	size = 0; 
	PalinCount = 0; 	
}

FindPalindrome::~FindPalindrome(){ //don't need to write anything b/c we aren't dealing with arrays or pointers
	//include the clear() method just to be safe: 
	clear(); 
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
	//also clear both vectors: 
	WordVect.clear(); 
	PalinVect.clear(); 
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{	//at most one character may appear an odd number of times
	//follow this process: 
	// 1) create array to hold the entire ABCs (size=26 ints)
	// 2) initialize freq of each letter to 0 (before counting through stringVector)
	// 3) check if the stringVector is empty 
	// 4) concatenate entire stringVector (new var)
	// 5) loop through concatenated var and count freq of chars and update ABC array 
	// 6) test if letter freq is odd (using mod) and if freq of odd > 1, then string is not a palindrome 
	// 7) check if length of strinVect is odd, if so center appears odd, other chars appear even 
	// 	  only inc freq char var when there is an odd num of char in stringVect 

	std::string stringVect; //declare new string var for concatenation: 
	for(int i=0; i<stringVector.size(); i++){ 
		stringVect += stringVector[i]; //concatenate
	}
	cout << "b5"; 
	//convert string to all lowercase:
	std::string stringvect; 
	stringvect = stringVect;
	convertToLowerCase(stringvect); 
	
	//use count function: 
	for(int i=0; i<stringvect.size(); i++){
		if(std::count(stringvect.begin(), stringvect.end(), stringvect[i])%2!=0){ //if odd
			char freq = stringvect[i]; //found the character that appears an odd # times 
			stringvect.erase(remove(stringvect.begin(), stringvect.end(), freq), stringvect.end()); //erase that character
			cout << "b11"; //this is where it's failing 
			break; 
		}
	}
	cout << "b6"; 
	for(int i=0; i<stringvect.size(); i++){
		if(std::count(stringvect.begin(), stringvect.end(), stringvect[i])%2!=0){ //if odd
			return false; //return false because this cannot happen again 
			cout << "b10"; 
		}
	}
	cout << "b7"; 
	return true; 
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{	//follows these steps: 
	// 1) create two arrays to hold ABC for each half (upper and lower), initiate to zero
	// 2) make sure vectors given are not empty 
	// 3) convert and concatenate into two new vars 
	// 4) set the upper and lower halves of the vectors (compare sizes of new vars)
	// 5) loop through halves and count freqs in each half and compare (should be the same feq in both)
	//	  if the freqs are not the same, return false 
	std::string strVector1; 
	std::string strVector2; 
	std::string strVect1;
	std::string strVect2;  
	for(int i=0; i<stringVector1.size(); i++){ 
		strVector1 += stringVector1[i]; //concatenate
	}
	for(int i=0; i<stringVector2.size(); i++){ 
		strVector2 += stringVector2[i]; //concatenate
	}
	strVect1 = strVector1; 
	strVect2 = strVector2; 
	convertToLowerCase(strVect1); 
	convertToLowerCase(strVect2);

	//compare sizes of vectors and set the upper and lower halves: 
	std::string upperhalf; 
	std::string lowerhalf; 
	if(strVect1.size()<strVect2.size()){
		lowerhalf = strVect1; //set the lower half 
		upperhalf = strVect2; //set the upper half
	}
	else{ 
		lowerhalf = strVect2; //set the lower half 
		upperhalf = strVect1; //set the upper half
	}
	int count; //keeps track if the character exists
	for(int j=0; j<lowerhalf.size(); j++){ //for every single letter in the smaller half
		for(int i=0; i<upperhalf.size(); i++){ //search through the larger half and make sure it exists
			if(lowerhalf[j]==upperhalf[i]){ //compare the halves
				//make sure it's somewhere in the upperhalf
				count++; 
			}
		}
		if(count==0){ //if it never appears
			return false; 
		}
		count = 0; //reset count for other characters
	}
	return true; 
}

//add the isValid method, tests if the word we are adding is a valid entry 
//return true if we have a valid entry 
//will be useful in the add methods below
bool FindPalindrome::isValid(string & value){ 
	//ensure everything in this method makes sure that the given word entry will be valid to add 
	//in order for the word entry to be valid: 
	//	1) string must only be chars 
	//	2) we need to convert the word to all lowercase letters 
	//perform these methods and then return true for a valid word entry 
	
	//make sure entry is all lowercase letters by calling that method: TEST THIS IN THE TEST CASE FILE TOO 
	std::string entry = value; 
	convertToLowerCase(entry); //we don't want the entry to be a const string b/c we are changing it here 

	//test if entry is a string of only characters:
	for(int i=0; i<value.length(); i++){
		if(entry[i]<'a' || entry[i]>'z'){ //if any of the letters of the entry cannot be found in the ABCs
			return false; //then we can't add this word to our WordVect
		} 
	//return true;
	}
	return true; 
}

bool FindPalindrome::add(const string & value)
{	//before we add our word entry, let's make sure it is a valid entry: 
	
	//reset these before adding to the vector 
	PalinVect.clear(); //if cut test passes, clear vect of strings 
	//size = 0; 
	PalinCount = 0; 

	//make a new variable for value since we need to call the isValid method: 
	std::string entry = value; 
	convertToLowerCase(entry); 
	std::vector<std::string> AddWordVect; //temporary vector for the recursive function 
	//cout << "b"; 
	if(!isValid(entry)){
		cout << "b1"; //this is where it's failing
		return false; //do not add an invalid input 
	}
	//otherwise, if the i/p is valid, add lowercase i/p to the temp vector
	for(int i=0; i<WordVect.size(); i++){
		AddWordVect.push_back(WordVect[i]); //add valid string i/p to the temporary vector 
		convertToLowerCase(AddWordVect[i]); //convert everything in vector to lowercase 
	}
	cout << "b2"; 
	//cout << "b"; 
	//make sure string doesn't already exist in the vector:
	for(int i=0; i<WordVect.size(); i++){
		if(entry==AddWordVect[i]){
			cout << "b3"; 
			cout << AddWordVect[i]; 
			return false; //cannot add if the value already exists in the word vector 
		}
	}		
	cout << "b4"; 	
	//otherwise, we are good to add our value to the wordvect: 
	WordVect.push_back(value); //adds original version of the string i/p to your wordVect

	//run cut test 1: 
	if(cutTest1(WordVect)){
		//call the recrusive findPalin method 
		//clear the palindrome vector: 
		PalinVect.clear(); 	
		PalinCount = 0; 
		std::vector<std::string> emptyTemp; 	
		recursiveFindPalindromes(emptyTemp, WordVect);
		cout << "b9"; //failing at cut test1
	}
	cout << "b0"; //doesn't print out b0 so it isn't returning true 
	return true; 
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	//a successful add would be the size is incremented:
	//add the new string to the end of the string vector 
	
	//reset these before adding to the vector 
	//PalinVect.clear(); //if cut test passes, clear vect of strings 
	//size = 0; 

	//make sure the vector string you are adding is a valid palindrome: 
	//concatenate and convert he vector string you're about to add: 
	std::string strVector; 
	for(int i=0; i<stringVector.size(); i++){ 
		strVector += stringVector[i]; //concatenate
	}
	std::string strvector; 
	strvector = strVector; 
	convertToLowerCase(strvector); //lowercase version of strVector

	if(!isValid(strvector)){
		return false; 
	}
	std::vector<string> AddVect; //temporary vector for the recursive function 
	std::string temp; 
	if(isValid(strvector)){
		for(int i=0; i<stringVector.size(); i++){ 
			temp = stringVector[i]; 
			convertToLowerCase(temp); 
			AddVect.push_back(temp); 
	  	}
	}
	//make sure this vector doesn't already exist: 
	for(int i=0; i<AddVect.size(); i++){
		for(int j=i+1; j<AddVect.size(); j++){
			if(AddVect[i]==AddVect[j]){
				return false; 
			} 
		}
	}
	if(isValid(strvector)){
		for(int i=0; i<WordVect.size(); i++){ 
			temp = WordVect[i]; 
			convertToLowerCase(temp); 
			AddVect.push_back(temp); 
	  	}
	}
	//make sure this vector doesn't already exist: 
	for(int i=stringVector.size(); i<AddVect.size(); i++){
		for(int j=0; j<stringVector.size(); j++){
			if(AddVect[i]==AddVect[j]){
				return false; 
			} 
		}
	}
	
	PalinVect.clear();
	PalinCount = 0; 

	//delcare temporary vector for recursive method: 
	//run cut test 1: 
	if(cutTest1(WordVect)){
		//PalinVect.clear(); 
		std::vector<string> temp; 
		//call the recrusive findPalin method 		
		recursiveFindPalindromes(temp, WordVect);
	}

	//PalinVect.push_back(stringVector);

	return true; 
}

vector< vector<string> > FindPalindrome::toVector() const
{	//returns the vector which collects all of the palindromes found from methods above 
	// vector<vector<string>> returnThingie;
	// return returnThingie;
	return PalinVect; 
}

