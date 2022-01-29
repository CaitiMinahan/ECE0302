#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  //create a bag array with arbitrary size 
  bag = new T[1];
  
  //define how many items you want to be in the bag: 
  numOfItems = 0; //zero because we haven't added anything yet
}
  

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){
  //take your first bag and copy its contents into a second bag named x: 
  //remember not to copy over the possible blank spots from first bag into bag x 

  //declare your bag x: 
  bag = new T[x.numOfItems];
  
  //use a for loop to iterate through entire first bag and copy over contents individually into x: 
  for(std::size_t i = 0; i<x.getCurrentSize(); i++){
      bag[i] = x.bag[i]; 
  }
  numOfItems = x.getCurrentSize(); //just like in the default constructor, you must define what the number of items in your new bag x: 
}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){
  delete [] bag; //deallocate and delete your bag array
  //make sure you reset your pointers too 
  numOfItems = 0;
}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  //clear the array before copying it again
  delete [] bag; 
  //again, make a bag x from the original bag:
  bag = new T[x.numOfItems];

  //use a for loop to iterate through entire first bag and copy over contents individually: 
  for(int i = 0; i<x.getCurrentSize(); i++){
      bag[i] = x.bag[i]; 
  }

  //just like in the default constructor, you must define what the number of items in your new bag x: 
  numOfItems = x.getCurrentSize(); //just like in the default constructor, you must define what the number of items in your new bag x: 

  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(numOfItems == 0) bag[0] = item;

  //add condition to test if we are at max size 
  if(numOfItems == maxsize){
    return false; //cannot add anymore items b/c it's full 
  }
  else{ 
    bag[numOfItems] = item; //make the item be in the LAST SPOT of the bag array 
    numOfItems++; //incremenet the number of items in the bag by ONE 
    return true; //denote a SUCCESSFUL ADD to the bag 
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  int item_place;
    //NOTE: if you randomly remove an item, you make sure there are no empty gaps in the array 
    //YOU HAVE TO SEARCH FOR THE ITEM STILL
    for(int i = 0; i < numOfItems; i++){
      if(bag[i] = item) item_place = i;
      break;
    }
    for(int i = item_place; i < numOfItems; i++){
      bag[i] = bag[i+1]; //shift elements in array after removal 

    }
    numOfItems--; 
    return true; //denote a SUCCESSFUL REMOVE from the bag 

  //an unsuccessful remove would be if the bag is empty and has nothing to remove:
  if(numOfItems==0){ return false; }
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if(numOfItems==0){
    return true; 
  }
  return false; //bag can't be empty if there is more than 0 items in bag 
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return numOfItems; //returns the size aka the number of items in the bag 
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  if(getFrequencyOf(item)>0){
    return true;
  }
  return false; 
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  //there should also be no items in the bag now:
  numOfItems = 0; 
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq=0; 

  //search through entire array and check frequency of item: 
  for(std::size_t i=0; i<numOfItems; i++){
    if(bag[i]==item){
      freq++; //if we found the item, increment frequency by one 
    }
  }
  return freq; //whatever it ends up being, returned frequency of the item 
};
