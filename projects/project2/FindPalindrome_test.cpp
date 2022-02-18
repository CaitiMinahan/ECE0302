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
	//INFO("This adds strings 'a' 'AA' and 'AaA' to make sure we get N! palindromes");
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
	p.clear(); 
	b.clear(); 
	REQUIRE(b.number()==0); 
	REQUIRE(p.size()==0); 
}

TEST_CASE("Tests the add string and add vector functionality, [FindPalindrome]"){
	FindPalindrome b; 
	//std::cout << "b"; 
	REQUIRE(b.add("a")); 
	REQUIRE(b.add("AA")); 
	REQUIRE(b.add("AaA")); 

	//add invalid words: 
	REQUIRE(!b.add("What's up")); 
	REQUIRE(!b.add("sk8rboy")); 
	
	//try to add duplicates:
	REQUIRE(!b.add("a"));
	REQUIRE(!b.add("AA")); 
	REQUIRE(!b.add("AaA")); 

	FindPalindrome b1; 
	//std::cout << "b"; 
	REQUIRE(b1.add("b")); 
	REQUIRE(b1.add("BB")); 
	REQUIRE(b1.add("BbB")); 

	//add invalid words: 
	REQUIRE(!b1.add("doesn't")); 
	REQUIRE(!b1.add("60minutes")); 
	
	//try to add duplicates:
	REQUIRE(!b1.add("b"));
	REQUIRE(!b1.add("BB")); 
	REQUIRE(!b1.add("BbB")); 

	//now, add your word vects to your palinvect 
	FindPalindrome b2; 
	std::vector<std::string> p; //vector of string vectors to be returned from the toVector() method
	p.push_back("taco"); //add string vectors to the palinvect 
	p.push_back("cat"); 
	REQUIRE(b2.add(p)); 
}
TEST_CASE("Cut test 1 [FindPalindrome]"){
	//run cut test 1 with a valid string vector 
	FindPalindrome b2; 
	std::vector<std::string> p; //vector of string vectors to be returned from the toVector() method
	p.push_back("taco"); //add string vectors to the palinvect 
	p.push_back("cat"); 
	REQUIRE(b2.cutTest1(p)); 

	//run cut test 1 with an invalid string vector
	FindPalindrome b3; 
	p.push_back("caiti"); 
	p.push_back("minahan"); 
	REQUIRE(!b3.cutTest1(p)); 
}
TEST_CASE("Cut test 2 [FindPalindrome]"){
	//run cut test 2 with a valid string vector 
	FindPalindrome b2; 
	std::vector<std::string> p; //vector of string vectors to be returned from the toVector() method
	std::vector<std::string> p1; //vector of string vectors to be returned from the toVector() method
	p.push_back("taco"); //add string vectors to the palinvect 
	p1.push_back("cat"); 
	REQUIRE(b2.cutTest2(p, p1)); 

	//run cut test 2 with an invalid string vector
	FindPalindrome b3; 
	p.push_back("caiti7"); 
	p1.push_back("minahan!"); 
	REQUIRE(!b3.cutTest2(p1, p)); 
}