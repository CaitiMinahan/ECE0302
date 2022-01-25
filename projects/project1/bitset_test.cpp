#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

//Test case to determine VALID bitset of size 8 with all bits set to zero 
TEST_CASE( "Test bitset default construction", "[bitset size 8]" ) {
    Bitset b; //call the default constructor

    REQUIRE(b.size() == 8); //calls size method to establish valid size of bitset (8 bits long) 
    REQUIRE(b.good()); //calls good method to require the bitset of 8 to be valid (aka good)

    REQUIRE(b.asString() == "00000000"); //call asString method to return string of the appropriate size N
}

//Test case to determine VALID bitset of size N with all bits set to zero 
TEST_CASE( "Test VALID bitset construction", "[bitset size N]" ) {
    Bitset b(4); //call the constructor to create a bitset of size N

    REQUIRE(b.size() == 4);  //Establishes valid bitset size (N bits long)
    REQUIRE(b.good()); //calls good method to return boolean value for bitsit (should be valid here)
    
    REQUIRE(b.asString() == "0000"); //call asString method to return string of the appropriate size N
}

//Test case to determine INVALID bitset of size N=-1 
TEST_CASE( "Test INVALID bitset construction", "[bitset size -1]" ) {
    Bitset b(-1); //input an invalid size for bitset (where N=-1)

    REQUIRE(b.size() == -1);
    REQUIRE(!b.good()); //calls good() method to return boolean value for bitsit (should be invalid here)

    //REQUIRE(b.asString() == ""); //here the bitset should be an empty string since N=0
}

//Test case to determine VALID bitset with a string of 1's and 0's
TEST_CASE( "Test VALID bitset string construction", "[bitset size N initialized with set, reset, toggle, test and asString methods]" ) {
    Bitset b("1110111");
    REQUIRE(b.size() == 7); //test the size method 
    REQUIRE(b.asString() == "1110111"); //test the asString method 

    //test the set method
    b.set(3); 
    REQUIRE(b.asString() == "1111111"); //shows that set works but changing bit 3 to a 1

    //test the reset method 
    b.reset(1);
    REQUIRE(b.asString() == "1011111"); //shows that reset works but chaning bit 1 to a 0

    //test the toggle method
    b.toggle(1);
    b.toggle(3);
    REQUIRE(b.asString() == "1110111"); //shows that toggle works but flipping bits 1 and 3

    //test the test method 
    REQUIRE(b.test(1) == true);
    REQUIRE(b.test(3) == false);

    REQUIRE(b.good()); //calls good method to require the bitset to only contain 1's and 0's
}

//Test case to determine INVALID bitset with a string of NOT 1's and 0's
TEST_CASE( "Test INVALID bitset string construction", "[bitset size N initialized with string of 1's and 0's]" ) {
    Bitset b("123456789"); //put values here that are NOT binary values 

    REQUIRE(!b.good()); //calls good method to return boolean value for bitsit (should be invalid here)
}