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
{
	// TODO need to implement this recursive function!
	//take the two vectors, loop through the size of currentStringVector and add words from currentStringVector to candidateStringVector 
	//individually until currentStringVector is empty:

	//base case: when the candidate vector is empty -- use c++ notation for vectors (creds: geeksforgeeks)
	if(currentStringVector.empty()==true){ //once we have added all of the words from currentString to candidateString 
		//then we must make variable -> candidatestring by concatenating our candidateStringVector
		 
		//temporary variables:  
		std::string candidateString;
		std::string candidatestring_lower; 
		for(int i=0; i<candidateStringVector.size(); i++){ 
			candidateString = candidateStringVector.at(i); 
			convertToLowerCase(candidateString); //don't forget to convert every word in the vector to lowercase: 
			candidatestring_lower += candidateString; //concatenate onto the lowercase version 
		}

	//now test candidateString to see if you have a palindrome or not:
	//test the lowercase version of your candidate string
		if(isPalindrome(candidatestring_lower)==true){ //If you do have a palindrome in candidateStringVect,
			PalinVect.push_back(candidateStringVector); //add original version of string to the palindrome vector 
			PalinCount++; //increase the current count of palindromes found
			return; //this is your end case!
		}
	}
	//exit the if loop above since this will be the next step case where currentStringVect ISN'T empty YET!: 
	//now do the loop shown in class 
	//	1) here we will remove an element from the currentStringVector and add it to candidateVector 
	//	2) Then, once we're done adding, we will check if candidateStringVect is a palindrome 
	//	3) Also, remember we want to return the ORIGINAL candidateStringVect, not the concatenated one
	for(int i=0; i<currentStringVector.size(); i++){
		//first remove the element from currentString: 
		currentStringVector.erase(find(currentStringVector.begin(), currentStringVector.end(), currentStringVector.at(i))); 
		//now add that element to the candidateStringVect: 
		candidateStringVector.push_back(currentStringVector.at(i)); 

		//call cut test 2: 
		if(!cutTest2(candidateStringVector, currentStringVector)) continue;
		recursiveFindPalindromes(candidateStringVector, currentStringVector); 
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
	//convert string to all lowercase:
	std::string stringvect; 
	stringvect = stringVect;
	convertToLowerCase(stringvect); 
	
	//use count function: 
	for(int i=0; i<stringvect.size(); i++){
		if(std::count(stringvect.begin(), stringvect.end(), stringvect[i])%2!=0){ //if odd
			char freq = stringvect[i]; //found the character that appears an odd # times 
			stringvect.erase(remove(stringvect.begin(), stringvect.end(), freq), stringvect.end()); //erase that character
			break; 
		}
	}
	for(int i=0; i<stringvect.size(); i++){
		if(std::count(stringvect.begin(), stringvect.end(), stringvect[i])%2!=0){ //if odd
			return false; //return false because this cannot happen again 
		}
	}
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
	//entry = value; 
	convertToLowerCase(entry); //we don't want the entry to be a const string b/c we are changing it here 

	//test if entry is a string of only characters:
	for(int i=0; i<entry.size(); i++){
		if(value[i]<'a' || value[i]>'z'){ //if any of the letters of the entry cannot be found in the ABCs
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
	cout << "b"; 
	if(isValid(entry)==false){
		return false; 
	}
	cout << "b"; 
	for(int i=0; i<WordVect.size(); i++){
		if(entry==AddWordVect[i]){
			return false; //cannot add if the value already exists in the word vector 
		}
	}	
	if(isValid(entry)==true){
		//a successful add would be the size of the word vector is incremented:
		//AddWordVect = WordVect.push_back(entry); //add the new string to the end of the word vector 
		for(int i=0; i<WordVect.size(); i++){
		AddWordVect.push_back(WordVect[i]); 
		convertToLowerCase(AddWordVect[i]); 
		}
	}
	cout << "b"; 	
	//otherwise, we are good to add our value to the wordvect: 
	WordVect.push_back(value); 

	//run cut test 1: 
	if(cutTest1(WordVect)==1){
		//call the recrusive findPalin method 
		//clear the palindrome vector: 
		PalinVect.clear(); 	
		std::vector<std::string> emptyTemp; 	
		recursiveFindPalindromes(emptyTemp, WordVect);
	}
	return true; 
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	//a successful add would be the size is incremented:
	//add the new string to the end of the string vector 
	
	//reset these before adding to the vector 
	PalinVect.clear(); //if cut test passes, clear vect of strings 
	//size = 0; 
	PalinCount = 0; 

	//make sure the vector string you are adding is a valid palindrome: 
	//concatenate and convert he vector string you're about to add: 
	std::string strVector; 
	for(int i=0; i<stringVector.size(); i++){ 
		strVector += stringVector[i]; //concatenate
	}
	std::string strvector; 
	strvector = strVector; 
	convertToLowerCase(strvector); 

	if(isValid(strvector)==false){
		return false; 
	}
	std::vector<string> AddVect; //temporary vector for the recursive function 
	if(isValid(strvector)==1){
		for(int i=0; i<WordVect.size(); i++){ 
			AddVect.push_back(WordVect[i]); 
			//convert all the elements to be lowercase: 
			convertToLowerCase(AddVect[i]); 
	  	}
	}
	//make sure this vector doesn't already exist: 
	for(int i=0; i<PalinVect.size(); i++){
		if(strVector == AddVect[i]){
			return false;
		}
	}

	PalinVect.push_back(stringVector); 
	
	//delcare temporary vector for recursive method: 
	std::vector<string> temp; 
	//run cut test 1: 
	if(cutTest1(WordVect)==1){
		PalinVect.clear(); 
		//call the recrusive findPalin method 		
		recursiveFindPalindromes(temp, WordVect);
	}
	return true; 
}

vector< vector<string> > FindPalindrome::toVector() const
{	//returns the vector which collects all of the palindromes found from methods above 
	// vector<vector<string>> returnThingie;
	// return returnThingie;
	return PalinVect; 
}

