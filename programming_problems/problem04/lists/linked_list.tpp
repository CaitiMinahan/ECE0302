#include "linked_list.hpp"
#include <iostream>

//define your private method for returning the currentptr
template<typename T> 
Node<T>* LinkedList<T>::getCurrentNode(std::size_t position) const{
  //create your currentptr variable: 
  Node<T>* currentPtr; 
  //start at the beginning of the list and traverse by means of a for loop: 
  currentPtr = headptr; 
  for(std::size_t i=1; i<position; i++){ 
    //make sure we are within bounds so that we don't get a seg fault: 
    //break condition: creds stackedoverflow 
    if(position<1 || position>size){
      break; //means this loop will break if we try to traverse out of bounds 
    }
    currentPtr = currentPtr->getNext(); //makes the currentPtr continue to point to the next item in the list 
  }
  //return your currentPtr: 
  return currentPtr; 
}

template <typename T>
LinkedList<T>::LinkedList()
{
  //set your headptr and size of list: 
  headptr = nullptr; //initializing headptr to null allows us to start with an empty list 
  size = 0;   
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //put nothing here for now, see if this causes an error ???
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) //copy constructor
{
  //set the headptr like in the default constructor: see if this causes an issue later ??? 
  Node<T>* headptr = x.headptr; 
  //set the size of the list: 
  size = x.size; 
  //now copy contents into the new list:
  //this means we need to copy all the nodes  
  for(std::size_t i=1; i<size; i++){ //use 1-based indexing 
    
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  return true;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return 0;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //TODO
  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
