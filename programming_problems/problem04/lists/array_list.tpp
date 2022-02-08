#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  ADTlist = new T[1]; //create your list 
  size = 0; //
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] ADTlist; 
  size = 0; 
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){ //copy constructor 
  ADTlist = new T[rhs.size]; //create list 
  for(std::size_t i=1; i<rhs.getLength(); i++){ //copy contents into list 
    ADT[i] = rhs.ADTlist[i]; 
  }
  size = rhs.getLength(); //adjust the length of the list 
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  delete [] ADTlist; //clear array before copying it 
  ADTlist = new T[rhs.size]; //create your list 
  for(int i=1; i<rhs.getLength(); i++){ //1-based indexing
    ADT[i] = rhs.ADTlist[i]; //copy contents into list 
  }
  size = rhs.getLength(); //adjust the size 
  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  //return false; 
  if(size==0){ 
    return true; 
  }
  return false; 
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  //return 0;
  return size; 
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  //return false;
  if(size==0){ //add the first item in the bag, position here is 1
    ADTlist[1]=item; //use 1-based indexing 
    return true; 
  }
  //test if we are at the max size: 
  if(size==maxsize){
    T* Largerarray = new T[maxsize+100]; 
    for(std::size_t i=1; i<size; i++){ 
      Largerarry[i] = ADTlist[i]; //copy into temp array 
    }
  delete[] ADTlist; 
  ADTlist = Largerarray; 
  //shift everything down:
  for(int i=1; i>=position; i++){
    ADTlist[i+1] = ADTlist[i]; //shifting 
  }
  //now let's insert the item: 
  ADTlist[position]=item; 
  size++; 
  return true; 
  }
  return false; //denote a successful insert to the list 
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  //return false;
  int item_position;
    //NOTE: if you randomly remove an item, you make sure there are no empty gaps in the array 
    //YOU HAVE TO SEARCH FOR THE ITEM STILL
    for(int i = 1; i<size; i++){
      if(ADTlist[i] = item) item_position = i;
      break;
    }
    for(int i = item_position; i < size; i++){
      ADTlist[i] = ADTlist[i+1]; //shift elements in array after removal 

    }
    size--; 
    return true; //denote a SUCCESSFUL REMOVE from the list 

  //an unsuccessful remove would be if the list is empty and has nothing to remove:
  if(size==0){ return false; }
}

template <typename T>
void ArrayList<T>::clear() {
  size = 0; 
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  for(int i=1; i<getLength(); i++){

  }
  
  return T();
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
