#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linked_list.hpp"

template class LinkedList<int>;
TEST_CASE( "Tests insert, remove, isEmpty, clear, and getLength methods", "[LinkedList]" ) { 
    LinkedList<int> L; //object for headptr

  //before testing your methods, fill the list: 
  //say the list consists of integers: 1, 2, 3
  REQUIRE(L.insert(1, 1)); //insert a 1 to the 1st position in the list  
  REQUIRE(L.getLength()==1); //length of 1 
  REQUIRE(!L.isEmpty()); //require it to be non-empty 
  REQUIRE(L.insert(2, 2)); //insert a 2 to the 2nd position in the list  
  REQUIRE(L.getLength()==2); //length of 2
  REQUIRE(!L.isEmpty()); //require it to be non-empty
  REQUIRE(L.insert(3,3)); //insert a 3 ro the 3rd position in the list
  REQUIRE(L.getLength()==3); //length of 3
  REQUIRE(!L.isEmpty()); //require it to be non-empty 
  REQUIRE(L.remove(2)); //remove the 2 from the 2nd position
  REQUIRE(L.getLength()==2); //length should be 2 now 
  L.clear(); //clear the list 
  REQUIRE(L.getLength()==0); //get the length, should be empty--or size=0--now 
  REQUIRE(L.isEmpty()); //require it to be empty now 
}
TEST_CASE( "Tests copy assignment", "[LinkedList]" ) { 
  LinkedList<int> L; //create your object 
  //assume list: 4 0 4 
  REQUIRE(L.insert(1, 4)); 
  REQUIRE(L.getLength()==1);
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(2, 0)); 
  REQUIRE(L.getLength()==2);
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(3, 4)); 
  REQUIRE(L.getLength()==3);
  REQUIRE(!L.isEmpty());   
  REQUIRE(L.remove(2)); //remove item from the 4th position
  REQUIRE(L.getLength()==2); //length should now be back to 4
  REQUIRE(!L.isEmpty()); //test is empty 
  LinkedList<int> L2; 
//require the exact same statements as above: 
  REQUIRE(L2.insert(1, 4)); 
  REQUIRE(L2.getLength()==1);
  REQUIRE(!L2.isEmpty()); 
  REQUIRE(L2.insert(2, 0)); 
  REQUIRE(L2.getLength()==2);
  REQUIRE(!L2.isEmpty()); 
  REQUIRE(L2.insert(3, 4)); 
  REQUIRE(L2.getLength()==3);
  REQUIRE(!L2.isEmpty());   
  REQUIRE(L2.remove(2)); //remove item from the 4th position
  REQUIRE(L2.getLength()==2); //length should now be back to 4
  REQUIRE(!L2.isEmpty()); //test is empty   //declare new object 
  L2 = L; //set this new object equal to the first one 
}
TEST_CASE( "Tests copy constructor", "[LinkedList]" ) { 
  LinkedList<int> L; //create your object  
  //assume list: 1 2 3 4 
  REQUIRE(L.insert(1, 0)); //insert a zero to the 1st position in the list  
  REQUIRE(L.getLength()==1); 
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(2, 2)); //insert 3 into 2nd position
  REQUIRE(L.getLength()==2); 
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(3, 3)); //insert a 5 into 3rd position
  REQUIRE(L.getLength()==3); 
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(4, 4)); //insert a 7 into 5th position
  REQUIRE(L.getLength()==4); 
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.remove(1)); //remove element from the 3rd position 
  REQUIRE(L.getLength()==3); //get the length, should be back to original now 
  L.clear(); //clear the list 
  REQUIRE(L.isEmpty()); //require it to be empty now 
  REQUIRE(L.getLength()==0); 

  //declare another object like this: 
  LinkedList<int> L2 = L; //create your object   
  //that's it, all the above statements should be included with instantiation of this new object 
}
TEST_CASE( "Tests setEntry and getEntry methods", "[LinkedList]" ) { 
  LinkedList<int> L; //create your object  
  //assume list: 4 0 4 
  REQUIRE(L.insert(1, 4)); 
  REQUIRE(L.getLength()==1);
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(2, 0)); 
  REQUIRE(L.getLength()==2);
  REQUIRE(!L.isEmpty()); 
  REQUIRE(L.insert(3, 4)); 
  REQUIRE(L.getLength()==3);
  REQUIRE(!L.isEmpty());   
  L.setEntry(2,4); //list should now be 4 4 4
  REQUIRE(L.getEntry(2)==4); //get that item 
}