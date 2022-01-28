#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
//create a bag array with max size 
maxsize = 100;
bag = new T [maxsize];

//define how many items you want to be in the bag: 
numOfItems = 0; //zero because we haven't added anything yet
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
  //take your first bag and copy its contents into a second bag named x: 
  //remember not to copy over the possible blank spots into bag x 

  //first declare your first and second bags: 
  bag = new T[maxsize]; //not sure if it will know what the maxsize is, but try this for now ?????
  x = new T[bag.getCurrentSize()]; //only want x to have enough space to the items we care about; no blanks 

  //use a for loop to iterate through entire first bag and copy over contents individually: 
  for(std::size_t i = 0; i<bag.getCurrentSize(); i++){
      bag[i] = x[i]; 
  }

  //just like in the default constructor, you must define what the number of items in your new bag x: 
  numOfItems = x.getCurrentSize(); 

  //do i need to define what the max size of x is?? not sure if i did that above or not ???

}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] bag; //deallocate and delete your bag array 
}
  
template<typename T> //PICK UP HERE -- JUST STARTED 
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  //since the copy constructor and copy assignment do the same thing, let's use the same code as above: 
  //first declare your first and second bags: 
  bag = new T[maxsize]; //not sure if it will know what the maxsize is, but try this for now ?????
  x = new T[bag.getCurrentSize()]; //only want x to have enough space to the items we care about; no blanks 

  //use a for loop to iterate through entire first bag and copy over contents individually: 
  for(std::size_t i = 0; i<bag.getCurrentSize(); i++){
      bag[i] = x[i]; 
  }

  //just like in the default constructor, you must define what the number of items in your new bag x: 
  numOfItems = x.getCurrentSize(); 
  
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  return false;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const 
{
  return numOfItems; //returns the size aka the number of items in the bag 
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
