#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Tests insert, remove, isEmpty, clear, and getLength methods", "[ArrayList]" ) {
  ArrayList<int> list; 

  //before testing your methods, fill the list: 
  //say the list consists of integers: 1, 2, 3
  REQUIRE(list.insert(1, 1)); //insert a 1 to the 1st position in the list  
  REQUIRE(list.getLength()==1); //length of 1 
  REQUIRE(!list.isEmpty()); //require it to be non-empty 
  REQUIRE(list.insert(2, 2)); //insert a 2 to the 2nd position in the list  
  REQUIRE(list.getLength()==2); //length of 2
  REQUIRE(!list.isEmpty()); //require it to be non-empty
  REQUIRE(list.insert(3,3)); //insert a 3 ro the 3rd position in the list
  REQUIRE(list.getLength()==3); //length of 3
  REQUIRE(!list.isEmpty()); //require it to be non-empty 
  REQUIRE(list.remove(2)); //remove the 2 from the 2nd position
  REQUIRE(list.getLength()==2); //length should be 2 now 
  list.clear(); //clear the list 
  REQUIRE(list.getLength()==0); //get the length, should be empty--or size=0--now 
  REQUIRE(list.isEmpty()); //require it to be empty now 

  //do the insert and remove from different positions:
  //assume the list: 0 3 5 7  
  REQUIRE(list.insert(1, 0)); //insert a zero to the 1st position in the list  
  REQUIRE(list.getLength()==1); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(2, 3)); //insert 3 into 2nd position
  REQUIRE(list.getLength()==2); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(3, 5)); //insert a 5 into 3rd position
  REQUIRE(list.getLength()==3); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(4, 7)); //insert a 7 into 5th position
  REQUIRE(list.getLength()==4); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.remove(3)); //remove element from the 3rd position 
  REQUIRE(list.getLength()==3); //get the length, should be back to original now 
  list.clear(); //clear the list 
  REQUIRE(list.isEmpty()); //require it to be empty now 
  REQUIRE(list.getLength()==0); 
}

TEST_CASE( "Tests copy assignment", "[ArrayList]" ) {
  ArrayList<int> list; //create your object 
  //assume list: 4 0 4 
  REQUIRE(list.insert(1, 4)); 
  REQUIRE(list.getLength()==1);
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(2, 0)); 
  REQUIRE(list.getLength()==2);
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(3, 4)); 
  REQUIRE(list.getLength()==3);
  REQUIRE(!list.isEmpty());   
  REQUIRE(list.remove(2)); //remove item from the 4th position
  REQUIRE(list.getLength()==2); //length should now be back to 4
  REQUIRE(!list.isEmpty()); //test is empty 
  ArrayList<int> list2; 
//require the exact same statements as above: 
  REQUIRE(list2.insert(1, 4)); 
  REQUIRE(list2.getLength()==1);
  REQUIRE(!list2.isEmpty()); 
  REQUIRE(list2.insert(2, 0)); 
  REQUIRE(list2.getLength()==2);
  REQUIRE(!list2.isEmpty()); 
  REQUIRE(list2.insert(3, 4)); 
  REQUIRE(list2.getLength()==3);
  REQUIRE(!list2.isEmpty());   
  REQUIRE(list2.remove(2)); //remove item from the 4th position
  REQUIRE(list2.getLength()==2); //length should now be back to 4
  REQUIRE(!list2.isEmpty()); //test is empty   //declare new object 
  list2 = list; //set this new object equal to the first one 
 }
 
TEST_CASE( "Tests copy constructor", "[ArrayList]" ) { 
  ArrayList<int> list; //create your object  
  //assume list: 1 2 3 4 
  REQUIRE(list.insert(1, 0)); //insert a zero to the 1st position in the list  
  REQUIRE(list.getLength()==1); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(2, 2)); //insert 3 into 2nd position
  REQUIRE(list.getLength()==2); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(3, 3)); //insert a 5 into 3rd position
  REQUIRE(list.getLength()==3); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(4, 4)); //insert a 7 into 5th position
  REQUIRE(list.getLength()==4); 
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.remove(1)); //remove element from the 3rd position 
  REQUIRE(list.getLength()==3); //get the length, should be back to original now 
  list.clear(); //clear the list 
  REQUIRE(list.isEmpty()); //require it to be empty now 
  REQUIRE(list.getLength()==0); 

  //declare another object like this: 
  ArrayList<int> list2 = list; //create your object   
  //that's it, all the above statements should be included with instantiation of this new object 
}
TEST_CASE( "Tests setEntry and getEntry methods", "[ArrayList]" ) { 
  ArrayList<int> list; //create your object  
  //assume list: 4 0 4 
  REQUIRE(list.insert(1, 4)); 
  REQUIRE(list.getLength()==1);
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(2, 0)); 
  REQUIRE(list.getLength()==2);
  REQUIRE(!list.isEmpty()); 
  REQUIRE(list.insert(3, 4)); 
  REQUIRE(list.getLength()==3);
  REQUIRE(!list.isEmpty());   
  list.setEntry(2,4); //list should now be 4 4 4
  REQUIRE(list.getEntry(2)==4); //get that item 
  //REQUIRE(list.getEntry(1)==4); 
}

