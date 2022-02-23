#include "sorted_linked_list.hpp"
#include <stdexcept>

//implement helper function for getCurrentNode: 
// template <typename T>
// Node<T>* SortedLinkedList<T>::getCurrentNode(std::size_t position)const{
//   return LinkedList<T>::getCurrentNode(std::size_t position); 
// }
template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
  //return size; 
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  //have conditions of where to insert an item at the ordered position
  //NOTE: we must have our list be in ASCENDING order: 

  //define a size variable: 
  int size = getLength(); 
  if(size==0){
    //call the LinkedList insert() method 
    //it will let you insert an item at a specific position 
    LinkedList<T>::insert(0, item); 
    return; 
  }
  else{
    //search the entire list 
    //if the item in the list at position (i) is greater than the value of the item you are trying to insert, 
    //place item before (i)
    for(int i=0; i<size; i++){
      if(LinkedList<T>::getEntry(i)>=item){
        LinkedList<T>::insert(i, item); //place item before getEntry(i) since it is less 
        return;
      }
    }
    if(LinkedList<T>::getEntry(size-1)<item){
      LinkedList<T>::insert(size, item); //place item at the end of the list 
      return; //ends the function 
    }
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  //removes the first instance of an item in the list 
  if(isEmpty()) throw std::range_error("empty list in remove");

  //search through entire list and see if you find the item: 
  for(int i=0; i<getLength(); i++){
    if(LinkedList<T>::getEntry(i)==item){
      LinkedList<T>::remove(i); //remove at the instance
    }
    else{
      throw std::range_error("item not in list, nothing to remove");
    }
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list, cannot remove"); 
  if(position<0 || position>=getLength()) throw std::range_error("out of range, cannot remove");
  LinkedList<T>::remove(position); 
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list, no entries found"); 
  if(position<0 || position>=getLength()) throw std::range_error("out of range, cannot get entry");
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  //return 0;
  // get the position of the first occurance of item or negated position
  // where it would be inserted.
  for(long int i=0; i<getLength(); i++){
    if(LinkedList<T>::getEntry(i)==newValue){
      return i; 
    }
  }
  throw std::range_error("item not in list"); 
  return -1; 
}
