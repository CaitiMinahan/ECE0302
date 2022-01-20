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

    REQUIRE(b.good()); //calls good method to require the bitset to only contain 1's and 0's
}

//Test case to determine INVALID bitset with a string of NOT 1's and 0's
TEST_CASE( "Test INVALID bitset string construction", "[bitset size N initialized with string of 1's and 0's]" ) {
    Bitset b("123456789"); //put values here that are NOT binary values 
    
    REQUIRE_FALSE(b.good()); //calls good method to return boolean value for bitsit (should be invalid here)
}

//Test case to determine VALID bitset with the nth element set to the value 1
TEST_CASE( "Test VALID bitset setting nth bit to 1", "[set nth bit to 1]" ) {
    Bitset b("1110111");
 
    REQUIRE(b.set(1)); //should set bit 1 to the value 1 
    REQUIRE(b.good()); 
}