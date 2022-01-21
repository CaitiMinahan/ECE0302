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
}

//Test case to determine VALID bitset of size N with all bits set to zero 
TEST_CASE( "Test VALID bitset construction", "[bitset size N]" ) {
    Bitset b(4); //call the constructor to create a bitset of size N

    REQUIRE(b.size() == 4);  //Establishes valid bitset size (N bits long)
    REQUIRE(b.good()); //calls good method to return boolean value for bitsit (should be valid here)
}

//Test case to determine INVALID bitset of size N=0 with all bits set to zero 
TEST_CASE( "Test INVALID bitset construction", "[bitset size 0]" ) {
    Bitset b(0); //input an invalid size for bitset (her N=0)

    REQUIRE(b.size() == 0);
    REQUIRE_FALSE(b.good()); //calls good method to return boolean value for bitsit (should be invalid here)
}

//Test case to determine VALID bitset with a string of 1's and 0's
TEST_CASE( "Test VALID bitset string construction", "[bitset size N initialized with string of 1's and 0's]" ) {
    Bitset b("1110111");
    REQUIRE(b.size() == 7); //test the size method 
    REQUIRE(b.asString() == "1110111"); //test the asString method 

    //test the set method
    b.set(3); 
    REQUIRE(b.asString() == "1111111"); //shows that set works but changing bit 3 to a 1

    //test the reset method 
    b.reset(0);
    REQUIRE(b.asString() == "0111111"); //shows that reset works but chaning bit 0 to a 0

    //test the toggle method
    b.toggle(0);
    b.toggle(3);
    REQUIRE(b.asString() == "1110111"); //shows that toggle works but flipping bits 0 and 3

    REQUIRE(b.good()); //calls good method to require the bitset to only contain 1's and 0's
}

//Test case to determine INVALID bitset with a string of NOT 1's and 0's
TEST_CASE( "Test INVALID bitset string construction", "[bitset size N initialized with string of 1's and 0's]" ) {
    Bitset b("123456789"); //put values here that are NOT binary values 

    REQUIRE_FALSE(b.good()); //calls good method to return boolean value for bitsit (should be invalid here)
}