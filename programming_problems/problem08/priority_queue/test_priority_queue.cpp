#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  //start out with an initially empty queue 
  REQUIRE(pq.isEmpty()); 
  //add items to the queue 
  //require it to not be empty
  pq.add(5); 
  REQUIRE(!pq.isEmpty()); 
  pq.add(0); 
  REQUIRE(!pq.isEmpty()); 
  pq.add(8); 
  REQUIRE(!pq.isEmpty()); 
  pq.add(4); 
  REQUIRE(!pq.isEmpty()); 
  pq.add(7); 
  REQUIRE(!pq.isEmpty()); 
  //at this point, list should look like this: 04578
  REQUIRE(pq.peek()==8); 
  //remove items 
  //peek as you remove the items 
  pq.remove(); 
  REQUIRE(pq.peek()==7); 
  pq.remove(); 
  REQUIRE(pq.peek()==5); 
  pq.remove(); 
  REQUIRE(pq.peek()==4); 
  pq.remove(); 
  REQUIRE(pq.peek()==0); 
  pq.remove();
  //end with an empty queue (require to be empty)
  REQUIRE(pq.isEmpty()); 
}
TEST_CASE("Testing Sorted List", "[sorted list]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;

  SortedListType s;

  //test sorted list by inserting nodes and testing their values with getEntry() 

  //start with an initially empty list: 
  REQUIRE(s.isEmpty()); 
  //insert items: 
  s.insert(0); 
  REQUIRE(!s.isEmpty()); 
  s.insert(3); 
  REQUIRE(!s.isEmpty()); 
  s.insert(2); 
  REQUIRE(!s.isEmpty()); 
  s.insert(4); 
  REQUIRE(!s.isEmpty()); 
  s.insert(1); 
  REQUIRE(!s.isEmpty()); 
  //at this point, the list should be: 01234
  //test values using getEntry()
  REQUIRE(s.getEntry(0)==0);
  REQUIRE(s.getEntry(1)==1);
  REQUIRE(s.getEntry(2)==2);
  REQUIRE(s.getEntry(3)==3);
  REQUIRE(s.getEntry(4)==4);
}