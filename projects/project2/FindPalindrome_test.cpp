#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

//test add for invalid word input to wordVect
TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}
//test add for invalid input to PalinVect
TEST_CASE( "Test FindPalindrome add a non-allowable vector", "[FindPalindrome]" ){
	INFO("Hint: add a single non-allowable vector");
	// FindPalindrome b_current; //wordVect for currentString
	// REQUIRE(b_current.add("Caiti")); //add your first word to b
	// REQUIRE(b_current.add("Minahan"));
	// FindPalindrome b_candid; //empty string for candidateString
	// recursiveFindPalindromes(b_candid, b_current); //call recursive function on your vectors of strings
	FindPalindrome bVect; //palinVect
	REQUIRE(!bVect.add("CaitiMinahan")); 
}
//test cutTest1

//test cutTest2 

//test recursive and isApalindrome methods for valid inputs 
