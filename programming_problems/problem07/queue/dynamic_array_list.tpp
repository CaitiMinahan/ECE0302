#include "dynamic_array_list.hpp"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  data = new T[101]; //create your list with maxsize length 
  size = 1; //start at 1 for 1-based indexing 
  capacity = 101;
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  data = new T[x.capacity]; //create list 
  size = x.size; //adjust the num of items in the list 
  capacity = x.capacity; //adjust the maxsize length 
  for(std::size_t i=1; i<size; i++){ //copy contents into list 
    data[i] = x.data[i]; 
  }
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  delete [] data; //delete the array 
  clear(); //will reset everything in the list
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  delete [] data; //clear array before copying it 
  data = new T[x.capacity]; //create your list 
  size = x.size; //adjust the num of items in the list 
  capacity = x.capacity; //adjust the maxsize length 
  for(int i=1; i<size; i++){ //1-based indexing
    data[i] = x.data[i]; //copy contents into list 
  }
  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T  return *this;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return(size==1); 
  //return false;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size-1; 
  //return 0;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //for inserting in an array list, we must do shifting when we insert at position [i]
  //we will be using zero-based indexing

  //when we insert in an empty list (when size=0):
  if(size==0){
    //add the first item in the list to position zero 
    data[i]=item; 
    size++
  }
  //when we need to allocate more memory:
  if(size==capacity){
    T* largerArray = new T[capacity+100]; //temp array for copying and allocating more memory
    for(std::size_t i=0; i<capacity; i++){
      largerArray[i] = data[i]; //copy data into larger array 
    }
    //after we copy, we must shift everything down: 
    for(int i=size-1; i>=position; i--){ //loop over the elements in the list proceeding the inserted element 
      data[i+1] = data[i]; 
    }
    //now, we insert the item into the list at position [i]:
    data[position]=item; 
    size++; 
  }
  //when we insert but have not exceeded the capacity of the list: 
  if(size<capacity){
    for(int i=size-1; i>=position; i--){ //shift everything down after position of insertion 
      data[i+1] = data[i]; 
    }
    //now insert item at position [i]:
    data[position]=item; 
    size++; 
  }

  //if position is out of range, throw a range error:
  //if(position<0||position>size+1){
  else{
    throw std::range_error("attempt to insert is out of bounds"); }
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //for removing in an array list, we must do shifting when we remove at position [i]
  if(isEmpty()){ //cannot remove anything when the list is empty 
    throw std::range_error("item not in list, nothing to remove"); }
 
  //throw a range error when we go out of bounds:
if(position<0||position>size+1){
  throw std::range_error("attempt to remove is out of bounds"); }

//otherwise, place conditions for removing an item at position [i] in the array 
//shift everything back: 
for(int i=position; i<size; i++){ 
  data[i] = data[i+1]; //shifts elements after removal to be back where they originally were 
}
size--; //decrease size after removing the item 
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //reset the size to 0 to clear the list 
  size = 0; 
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //make sure are within bounds of the list to access the entry: 
  if(position>=0 && position<=size){
    return data[position]; //return a copy of the item at that position
  }
  return T();
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //make sure we are within bounds of the list to set the entry: 
  if(position>=0 && (position<=size+1) && size<capacity){
    for(int i=size; i>=position; i--){ //shift everything down affected by insertion 
      data[i+1]=data[i]; 
      data[position]=newValue; 
    }
  }
}
