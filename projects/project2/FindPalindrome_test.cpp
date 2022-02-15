#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include <iostream>

//using namespace std; 

// There should be at least one test per FindPalindrome method

//test add for invalid word input to wordVect
TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}
//Testing number of possible sentence palindromes for N words in the wordVect:
TEST_CASE( "Tests add(string), number(), toVector() and clear() methods", "[FindPalindrome]" ){
	//remember, the number of palindromes for N unique words is N! 
	INFO("This adds strings 'a' 'AA' and 'AaA' to make sure we get N! palindromes");
	FindPalindrome b; 
	//std::cout << "b"; 
	REQUIRE(b.add("a")); 
	REQUIRE(b.add("AA")); 
	REQUIRE(b.add("AaA")); 

	//find the number of sentence palindromes by calling the number() method: 
	//here, the number of sentence palindromes = N! = 3!
	REQUIRE(b.number()==6); 

	//now, return the PlainVect which contains all sentence palindromes: 
	std::vector<std::vector<std::string>> p; //vector of string vectors to be returned from the toVector() method
	p = b.toVector(); 
	
	//ensure the # palindromes (palinCount) = N! = number(): 
	REQUIRE(p.size()==6); //the size of the palinVect is the # of sentence palindromes = number() = N! = 3! = 6

	//now let's continue to test the number() method by testing the clear() method: 
	b.clear(); 
	REQUIRE(b.number()==0); 
	REQUIRE(p.size()==0); 
}
//test recursive and isApalindrome methods for valid inputs: 
// TEST_CASE( "Tests add(string) method", "[FindPalindrome]" ){ 
// 	INFO("This will create a valid palindrome with valid strings")
// }

// //test cutTest1
// TEST_CASE( "Tests cut test 1", "[FindPalindrome]" ){ 
// 	//to do this, let's first create a valid palindrome and run cut test 1 on it 
// 	INFO("Use valid strings from before")
// 	//then, create an invalid palindrome and run cut test 1 on it and make sure it fails
// 	INFO("Use invalid word here by having a character repeat more than an odd # of times")
// }

// //test cutTest2 
// TEST_CASE( "Tests cut test 2", "[FindPalindrome]" ){
// 	//to do this, let's first create a valid palindrome and run cut test 2 on it 
// 	INFO("Use valid strings from before")
// 	//then, create an invalid palindrome and run cut test 2 on it and make sure it fails
// 	INFO("Use invalid word here by having the halves of the palindrome not be equal")
//  }

//NOTE: cut tests 1 and 2 call upon the recursiveFindPalindromes which also calls upon isPalindrome so these let us test all methods in less steps