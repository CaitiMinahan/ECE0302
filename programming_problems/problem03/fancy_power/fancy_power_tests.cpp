#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancy_power.hpp"

//test for even positive powers
TEST_CASE("Test case for EVEN POSITIVE", "fancy power"){
  REQUIRE(fancy_power(4, 2)==16); 
  REQUIRE(true);
}
//test for odd positive powers
TEST_CASE("Test case ODD POSITIVE", "fancy power"){
  REQUIRE(fancy_power(5, 3)==243); 
  REQUIRE(true);
}
//test for even negative powers
/*TEST_CASE("Test casefor EVEN NEGATIVE", "fancy power"){
  REQUIRE(fancy_power(-1, 2)==(1/2)); 
  REQUIRE(true);
}
//test for odd negative powers
TEST_CASE("Test casefor ODD NEGATIVE", "fancy power"){
  REQUIRE(fancy_power(0, 3)==(1)); 
  REQUIRE(true);
}*/
//test for zero powers
TEST_CASE("Test case", "fancy power"){  
  REQUIRE(fancy_power(0, 1)==1); 
  REQUIRE(true);
}