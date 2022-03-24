#include "dynamic_array_list.hpp"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //if we make the array initially size 1, we are always at the max size when we go to insert
  //instead of using the capacity variable, we know we're always at the max size (for allocation purposes)
  data = new T[1]; //create your list with maxsize length of 1
  size = 0; //start at 0 for 0-based indexing 
 // capacity = size;
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  if(size == 0) data = new T[1];
  else data = new T[x.size];

  //set the size ptrs to the same element
  size = x.size;

  //copy every element from x into the new datum
  for(int i = 0; i < size; i++){
    data[i] = x.data[i];
  }
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  //clear();
  size = 0;  
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  if(size == 0) data = new T[1];
  else data = new T[x.size];

  //set the size ptrs to the same element
  size = x.size;

  //copy every element from x into the new datum
  for(int i = 0; i < size; i++){
    data[i] = x.data[i];
  }
  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T  return *this;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return(size==0); 
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size; 
  //return 0;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //since we set the array to be size to be 1, we will always be at the max size when inserting, 
  //therefore, we must always reallocate into a temp array and update the size 
  
  //if position is out of range, throw a range error:
  if(size<0 || position<0 || position>size){
    throw std::range_error("attempt to insert is out of bounds"); }
  
  T* largerArray = new T[size]; //temp array for copying and allocating more memory
    for(int i=0; i<size; i++){
      std::cout << i << "\n"; 
      std::cout << "insert - copying into temp" << std::endl; 
      largerArray[i] = data[i]; //copy data into larger array 
    }
  //delete the old array b/c it is too small 
  delete [] data; 
  data = nullptr; //delete the old list contained in data since we have copied into a new temp array

  //new array is always going to be 1 greater than the size of the old array : 
  size++; 
  data = new T[size]; //create OG array again with larger size 

  //copy data back into the OG data[] array:
    for(int i=0; i<size-1; i++){
      std::cout << "insert - copying back into data" << std::endl; 
      data[i] = largerArray[i]; //copy data into larger array 
    }
  data[position]=item; 

}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //for removing in an array list, we must do shifting when we remove at position [i]
  if(isEmpty()){ //cannot remove anything when the list is empty 
    throw std::range_error("list is empty, nothing to remove"); }
 
  //throw a range error when we go out of bounds:
  if(size<0 || position<0 || position>size){
    throw std::range_error("attempt to remove is out of bounds"); }

  //otherwise, place conditions for removing an item at position [i] in the array 
  //shift everything back: 
  for(size_t i=position; i<size; i++){ 
    std::cout << "remove" << std::endl; 
    data[i] = data[i+1]; //shifts elements after removal to be back where they originally were 
  }
  size--; //decrease size after removing the item 
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //remove all the items from the list to make sure the array doesn't have anything in it
  while(!isEmpty()){
    remove(0); 
    size--; 
  }
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //make sure are within bounds of the list to access the entry: 
  if(position>=0 && position<size && size>=0){
    return data[position]; //return a copy of the item at that position
  }
  return T();
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //make sure we are within bounds of the list to set the entry: 
  if(position>=0 && position<size){
    data[position]=newValue;
  }
}
