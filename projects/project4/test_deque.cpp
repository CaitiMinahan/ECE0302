#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

// TODO
TEST_CASE( "Tests isEmpty, pushFront, popFront and front methods", "[deque]" ) {
    //deque of integer values: 
    Deque<int> D; 
    REQUIRE(D.isEmpty()); //start with an empty stack
    //add items to the front of the deque    
    D.pushFront(1); //should be the first item in the deque
    D.pushFront(0); 
    D.pushFront(1); 
    D.pushFront(0); 
    REQUIRE(!D.isEmpty()); //make sure items have been added 
    //peek the first item in the deque and then 
    //pop items from the front of the deque 
    REQUIRE(D.front()==0); 
    D.popFront(); 
    REQUIRE(!D.isEmpty());
    REQUIRE(D.front()==1); 
    D.popFront(); 
    REQUIRE(!D.isEmpty());
    REQUIRE(D.front()==0); 
    D.popFront();
    REQUIRE(!D.isEmpty()); 
    REQUIRE(D.front()==1); 
    D.popFront(); 
    //now, the deque should be empty 
    REQUIRE(D.isEmpty());
}
TEST_CASE( "Tests isEmpty, pushBack, popBack and back methods", "[deque]" ) {
    //deque of integer values: 
    Deque<int> D; 
    REQUIRE(D.isEmpty()); //start with an empty stack
    //add items to the back of the deque    
    D.pushBack(1); //should be the first item in the deque
    D.pushBack(2); 
    D.pushBack(3); 
    D.pushBack(4); 
    REQUIRE(!D.isEmpty()); //make sure items have been added 
    //peek the first item in the deque and then 
    //pop items from the back of the deque 
    REQUIRE(D.back()==4); 
    D.popBack(); 
    REQUIRE(!D.isEmpty());
    REQUIRE(D.back()==3); 
    D.popBack(); 
    REQUIRE(!D.isEmpty());
    REQUIRE(D.back()==2); 
    D.popBack(); 
    REQUIRE(!D.isEmpty());
    REQUIRE(D.front()==1); 
    D.popBack(); 
    //now, the deque should be empty 
    REQUIRE(D.isEmpty());
}
TEST_CASE( "Tests copy constructor", "[deque]" ) {
    //deque of int values: 
    Deque<int> D1; 
    REQUIRE(D1.isEmpty()); //start with an empty stack
    //add items to the front of the deque    
    D1.pushFront(1); //should be the first item in the deque
    D1.pushFront(2); 
    D1.pushFront(3); 
    //at this point, queue should look like this: 321
    D1.pushBack(1);
    D1.pushBack(2);
    D1.pushBack(3); 
    //at this point, queue should look like this; 321123
    REQUIRE(!D1.isEmpty()); //make sure items have been added 

    //peek the first item in the deque and then 
    //pop items from the front of the deque 

    //make sure both deques are initially: 321123
    REQUIRE(D1.front()==3); 
    REQUIRE(D1.back()==3);
    D1.popFront(); 
    D1.popBack(); 
    //queue: 2112
    REQUIRE(D1.front()==2); 
    REQUIRE(D1.back()==2);
    D1.popFront(); 
    D1.popBack(); 
    //queue: 11
    REQUIRE(D1.front()==1); 
    REQUIRE(D1.back()==1);
    D1.popFront(); 
    D1.popBack(); 
    //now, the deque should be empty 
    REQUIRE(D1.isEmpty());

    Deque<int> D2 = D1; 
}

TEST_CASE( "Tests copy assignment", "[deque]" ) {
    //deque of int values: 
    Deque<int> D1; 
    REQUIRE(D1.isEmpty()); //start with an empty stack
    //add items to the front of the deque    
    D1.pushFront(1); //should be the first item in the deque
    D1.pushFront(2); 
    D1.pushFront(3); 
    //at this point, queue should look like this: 321
    D1.pushBack(1);
    D1.pushBack(2);
    D1.pushBack(3); 
    //at this point, queue should look like this; 321123
    REQUIRE(!D1.isEmpty()); //make sure items have been added 

    //peek the first item in the deque and then 
    //pop items from the front of the deque 

    //make sure both deques are initially: 321123
    REQUIRE(D1.front()==3); 
    REQUIRE(D1.back()==3);
    D1.popFront(); 
    D1.popBack(); 
    //queue: 2112
    REQUIRE(D1.front()==2); 
    REQUIRE(D1.back()==2);
    D1.popFront(); 
    D1.popBack(); 
    //queue: 11
    REQUIRE(D1.front()==1); 
    REQUIRE(D1.back()==1);
    D1.popFront(); 
    D1.popBack(); 
    //now, the deque should be empty 
    REQUIRE(D1.isEmpty());

    //make our second instance to test if both deques match 
    Deque<int> D2; 
    REQUIRE(D2.isEmpty()); //start with an empty stack
    //add items to the front of the deque    
    D2.pushFront(1); //should be the first item in the deque
    D2.pushFront(2); 
    D2.pushFront(3); 
    //at this point, queue should look like this: 321
    D2.pushBack(1);
    D2.pushBack(2);
    D2.pushBack(3); 
    //at this point, queue should look like this; 321123
    REQUIRE(!D2.isEmpty()); //make sure items have been added 

    //peek the first item in the deque and then 
    //pop items from the front of the deque 

    //make sure both deques are initially: 321123
    REQUIRE(D2.front()==3); 
    REQUIRE(D2.back()==3);
    D2.popFront(); 
    D2.popBack(); 
    //queue: 2112
    REQUIRE(D2.front()==2); 
    REQUIRE(D2.back()==2);
    D2.popFront(); 
    D2.popBack(); 
    //queue: 11
    REQUIRE(D2.front()==1); 
    REQUIRE(D2.back()==1);
    D2.popFront(); 
    D2.popBack(); 
    //now, the deque should be empty 
    REQUIRE(D2.isEmpty());

    //set D2=D1 to test the =operator:
    D2=D1; 
}