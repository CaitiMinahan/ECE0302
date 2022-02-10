#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  ADTlist = new T[101]; //create your list with maxsize length 
  size = 1; //start at 1 for 1-based indexing 
  maxsize = 101; 
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] ADTlist; //delete the array 
  //size = 0; 
  clear(); //will reset everything in the list
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){ //copy constructor 
  ADTlist = new T[rhs.maxsize]; //create list 
  size = rhs.size; //adjust the num of items in the list 
  maxsize = rhs.maxsize; //adjust the maxsize length 
  for(std::size_t i=1; i<size; i++){ //copy contents into list 
    ADTlist[i] = rhs.ADTlist[i]; 
  }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  delete [] ADTlist; //clear array before copying it 
  ADTlist = new T[rhs.maxsize]; //create your list 
  size = rhs.size; //adjust the num of items in the list 
  maxsize = rhs.maxsize; //adjust the maxsize length 
  for(int i=1; i<size; i++){ //1-based indexing
    ADTlist[i] = rhs.ADTlist[i]; //copy contents into list 
  }
  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  //return false; 
  // if(size==1){ 
  //   return true; 
  // }
  // return false;
  return(size==1);  
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  //return 0;
  //return size; 
  return size-1; //will return current position in the list 
                 //need to subtract 1 because the positions are 1 less than the nth element (i.e., the 2nd element is at position 1 in the array)
 // return size; 
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  //return false;
  if(size==1){ //add the first item in the bag, position here is 1
    ADTlist[1]=item; //use 1-based indexing 
    size++; 
    return true; 
  }
  //test if we are at the max size: 
  if(size==maxsize){
    T* Largerarray = new T[maxsize+100]; //create a temp array that is larger in size (for more memory allocation)
    for(std::size_t i=1; i<maxsize; i++){ 
      Largerarray[i] = ADTlist[i]; //copy into temp array 
    }
  //shift everything down:
  for(int i=size-1; i>=position; i--){ //parameters here shift down the items that are affected by the insertion; aka the elements proceeding the position of this insertion
    ADTlist[i+1] = ADTlist[i]; //shifting down by one 
  }
  //now let's insert the item: 
  ADTlist[position]=item; //place item in the list at that position 
  size++; 
  return true; 
  }
  //test if we don't need to allocate more memory; have enough space:
  if(size<maxsize){
    for(int i=size-1; i>=position; i--){  //shift everything down that was affected by the insertion:
      ADTlist[i+1] = ADTlist[i]; //shifting down by one 
    }
    //now let's insert the item: 
    ADTlist[position]=item; 
    size++; 
    return true;
    }
  return false;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  //return false;
  //if list is empty, we cannot remove: 
  if(size==1){
    return false; 
  }
  //make sure we don't go out of bounds of the array: 
  if(position<1 || position > size+1 || position>maxsize){
    return false; 
  }
  //otherwise, we can remove an item from the array 
  //first shift everything back: 
    for(int i = position; i<size; i++){
      ADTlist[i] = ADTlist[i+1]; //shift elements in array after removal to be back to where they originally were
    }
    size--; //now we have one less item in the array
    return true; //denote a SUCCESSFUL REMOVE from the list 
}

template <typename T>
void ArrayList<T>::clear() {
  size = 1; //reset the size
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const { //get a copy of the item at the position
  // for(int i=1; i<getLength(); i++){
  // }

  //make sure we are within bounds of the array in order to correctly access memory 
  //if we don't make sure the memory is there to access, we will get a segmentation fault
  if(position>=1 && position <= size){
    return ADTlist[position]; //return copy of the item at that position in the list 
  }
  return T(); //return the item at the position
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  //set the value at a position given this newValue 
  //make sure you insert within bounds: 
  if(position>=1 && (position<=size+1)&&size<maxsize){
    for(int i=size; i>=position; i--){  //shift everything down that was affected by the insertion:
      ADTlist[i+1] = ADTlist[i]; //shifting down by one 
      ADTlist[position]=newValue; //insert your new value
      //size++; //adjust your number of items
    }
  }
}