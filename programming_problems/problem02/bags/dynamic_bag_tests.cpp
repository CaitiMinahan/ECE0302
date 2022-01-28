#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b; //declare instance b which is a bag of integers 

  //assume bag is initially empty
  REQUIRE(b.getCurrentSize()==0); 
  //successfully add a two to the bag 
  REQUIRE(b.add(2)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(b.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(b.getCurrentSize()==1); 
  //test how many twos are in the bag 
  REQUIRE(b.getFrequencyOf(2)==1); 
  //require that the bag contains the zero we just added 
  REQUIRE(b.contains(2)==1);
  //successfully remove a two from the bag 
  REQUIRE(b.remove(2)==1);
  //now you have no more items since you removed the one
  REQUIRE(b.getCurrentSize()==0); 
  //require it to be empty since we have no items in there 
  REQUIRE(b.isEmpty()==1);
  //make sure the two still isn't in the bag
  REQUIRE(b.contains(2)==0); 

  //successfully add a one to the bag 
  REQUIRE(b.add(1)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(b.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(b.getCurrentSize()==1); 
  //test how many zeros are in the bag 
  REQUIRE(b.getFrequencyOf(1)==1); 
  //now, let's clear the array and fill it with zeros 
  b.clear(); //doesn't like the REQUIRE in it 
  //it should not contain a 1 since we just cleared it  
  REQUIRE(b.contains(1)==0); 
  //rather it should contain a zero 
  REQUIRE(b.contains(0)==1); 

}
//test the copy constructor 
TEST_CASE("Copy constructor", "[DynamicBag]"){
  //create two bag instances and then require all of their traits to be the same after copying on to the other 
  DynamicBag<int> bag1; 

  //assume bag is initially empty
  REQUIRE(bag1.getCurrentSize()==0); 
  //successfully add a two to the bag 
  REQUIRE(bag1.add(2)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(bag1.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(bag1.getCurrentSize()==1); 
  //test how many twos are in the bag 
  REQUIRE(bag1.getFrequencyOf(2)==1); 
  //require that the bag contains the zero we just added 
  REQUIRE(bag1.contains(2)==1);
  //successfully remove a two from the bag 
  REQUIRE(bag1.remove(2)==1);
  //now you have no more items since you removed the one
  REQUIRE(bag1.getCurrentSize()==0); 
  //require it to be empty since we have no items in there 
  REQUIRE(bag1.isEmpty()==1);
  //make sure the two still isn't in the bag
  REQUIRE(bag1.contains(2)==0); 

  DynamicBag<int> bag2 = bag1; 

  //assume bag is initially empty
  REQUIRE(bag2.getCurrentSize()==0); 
  //successfully add a two to the bag 
  REQUIRE(bag2.add(2)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(bag2.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(bag2.getCurrentSize()==1); 
  //test how many twos are in the bag 
  REQUIRE(bag2.getFrequencyOf(2)==1); 
  //require that the bag contains the zero we just added 
  REQUIRE(bag2.contains(2)==1);
  //successfully remove a two from the bag 
  REQUIRE(bag2.remove(2)==1);
  //now you have no more items since you removed the one
  REQUIRE(bag2.getCurrentSize()==0); 
  //require it to be empty since we have no items in there 
  REQUIRE(bag2.isEmpty()==1);
  //make sure the two still isn't in the bag
  REQUIRE(bag2.contains(2)==0); 

}
//test the copy assognment operator 
TEST_CASE("Copy assignment", "[DynamicBag]"){
  DynamicBag<int> bag1; 

  //create two bag instances and then require all of their traits to be the same after copying on to the other 
  //assume bag is initially empty
  REQUIRE(bag1.getCurrentSize()==0); 
  //successfully add a two to the bag 
  REQUIRE(bag1.add(2)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(bag1.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(bag1.getCurrentSize()==1); 
  //test how many twos are in the bag 
  REQUIRE(bag1.getFrequencyOf(2)==1); 
  //require that the bag contains the zero we just added 
  REQUIRE(bag1.contains(2)==1);
  //successfully remove a two from the bag 
  REQUIRE(bag1.remove(2)==1);
  //now you have no more items since you removed the one
  REQUIRE(bag1.getCurrentSize()==0); 
  //require it to be empty since we have no items in there 
  REQUIRE(bag1.isEmpty()==1);
  //make sure the two still isn't in the bag
  REQUIRE(bag1.contains(2)==0); 

  //now assign bag2 to bag 1 and then require all of their traits to be the same:
  DynamicBag<int> bag2;  
  bag2 = bag1; //should i say require here???

  //assume bag is initially empty
  REQUIRE(bag2.getCurrentSize()==0); 
  //successfully add a two to the bag 
  REQUIRE(bag2.add(2)==1);
  //bag cannot be empty since you just added an item 
  REQUIRE(bag2.isEmpty()==0);
  //we added one item, so the size must be 1
  REQUIRE(bag2.getCurrentSize()==1); 
  //test how many twos are in the bag 
  REQUIRE(bag2.getFrequencyOf(2)==1); 
  //require that the bag contains the zero we just added 
  REQUIRE(bag2.contains(2)==1);
  //successfully remove a two from the bag 
  REQUIRE(bag2.remove(2)==1);
  //now you have no more items since you removed the one
  REQUIRE(bag2.getCurrentSize()==0); 
  //require it to be empty since we have no items in there 
  REQUIRE(bag2.isEmpty()==1);
  //make sure the two still isn't in the bag
  REQUIRE(bag2.contains(2)==0); 
}