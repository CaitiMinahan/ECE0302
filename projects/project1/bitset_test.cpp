#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

//Test case to determine valid bitset of size 8 with all bits set to zero 
TEST_CASE( "Test bitset default construction", "[bitset size 8]" ) {
    
    Bitset b; //call the default constructor

    REQUIRE(b.size() == 8); //calls size method to establish valid size of bitset (8 bits long) 
    REQUIRE(b.good()); //calls good method to require the bitset of 8 to be valid (aka good)
}

//Test case to determine valid bitset of size N with all bits set to zero 
TEST_CASE( "Test bitset construction", "[bitset size N]" ) {
    //Note: this test should fail if N<=0
   //intmax_t N; //am I allowed to do this???
    Bitset b(4); //call the constructor to create a bitset of size N | Question: do I need to name b's different 

    REQUIRE(b.size()>0);  //am I allowed to do this??? make sure N>0 | Establishes valid bitset size (N bits long)
   // REQUIRE(b.size() == 4); //calls size method to establish valid size of bitset (N bits long)
    REQUIRE(b.good()); //calls good method to require the bitset of N to be valid (aka good)
}

//Test case to determine valid bitset with a string of 1's and 0's
TEST_CASE( "Test bitset string construction", "[bitset size N initialized with string of 1's and 0's]" ) {
    //Note: this should fail if there are any characters other than 1 and 0
    Bitset b("1110111");

    REQUIRE(b.size()>0);  //am I allowed to do this??? make sure N>0
    REQUIRE(b.good()); //calls good method to require the bitset to only contain 1's and 0's
}