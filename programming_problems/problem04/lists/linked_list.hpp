#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"
#include<iostream>

template <typename T>
class LinkedList: public AbstractList<T>
{
public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  LinkedList(const LinkedList& x);
    
  // destructor
  ~LinkedList();
  
  // copy assignment
  LinkedList& operator=(const LinkedList& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:
  //for linked lists, we need to keep track of 3 things: 
  // 1) the headptr
  // 2) the current ptr (where we are inserting/removing an item)
  // 3) the next ptr (what proceeds the current ptr)

  //since we already have a private variable for the next ptr, declare two more methods for the headptr and the currentptr
  Node<T>* headptr; // Pointer to beginning of the linked list

  //also remember that unlike arrays, linked lists cannot just access the ith element of the list on command
  //in order to access a certain poisition within the list, we must first traverse the list and indicate which node we are pointing to 
  //therefore, we must define a method which returns the node we are trying to access: 
  Node<T>* getCurrentNode(std::size_t position) const; //this gets the node at a certain position in the list 
  std::size_t size; //for your linked list size 

  //remember that the linkedlist inherits from the Node class, so that means 
  //we have methods for setting and getting the nextptrs, so we don't need to declare anything for it in here
};

#include "linked_list.tpp"

#endif
