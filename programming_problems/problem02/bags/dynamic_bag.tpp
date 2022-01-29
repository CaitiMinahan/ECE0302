#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  //create a bag array with arbitrary size 
  bag = new T[1];
  
  //define how many items you want to be in the bag: 
  numOfItems = 0; //zero because we haven't added anything yet
}
 
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
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
DynamicBag<T>::~DynamicBag(){
  delete [] bag; //deallocate and delete your bag array
  //make sure you reset your pointers too 
  numOfItems = 0;
}
  
template<typename T> 
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  //since the copy constructor and copy assignment do the same thing, let's use the same code as above: 

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
bool DynamicBag<T>::add(const T& item) //test if adding an item to the bag was successful or not 
{
  //successful add would be if you tried to add an item, and the size of the bag was increased by 1
  //usually when we add to an array, we just tack it onto the END of the array 

  if(numOfItems == 0) bag[0] = item;

  else{

  //what if the bag is already completely full? We need to ALLOCATE MORE MEMORY to add to it: 
  T* Largerbag = new T[numOfItems+1]; //make new temporary array and adding more room to add items 
                                      //we do this to have a placeholder while we put our original items into a bigger bag 
    //use the temporary bag to put original bag's items into a larger bag: 
    for(std::size_t i=0; i<numOfItems; i++){
      Largerbag[i] = bag[i]; //copy contents of original bag into larger bag named Largerbag
    }
  delete[] bag; //delete the original bag, we don't need that small thing anymore: 
  bag = Largerbag; //rename Largerbag to just bag using assignment: 

  //now, let's physically ADD the item to the end of the bag array: 
  bag[numOfItems] = item; //make the item be in the LAST SPOT of the bag array 
  
  }
  numOfItems++; //incremenet the number of items in the bag by ONE 
  return true; //denote a SUCCESSFUL ADD to the bag 

  //the above method will alwasys increase the array when we add an item, so it should always work and be true 
  //return false; 
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{ //a successful remove would be the numOfItems being decremented by 1 
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
bool DynamicBag<T>::isEmpty() const
{ //test if there are zero items in the bag: 
  if(numOfItems==0){
    return true; 
  }
  return false; //bag can't be empty if there is more than 0 items in bag 
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const 
{
  return numOfItems; //returns the size aka the number of items in the bag 
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{ //test if item is found somewhere in the array 
  if(getFrequencyOf(item)>0){
    return true;
  }
  return false; 
} 

template<typename T>
void DynamicBag<T>::clear(){
  //there should also be no items in the bag now:
  numOfItems = 0; 
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{ //define a frequency variable to be returned 
  std::size_t freq=0; 

  //search through entire array and check frequency of item: 
  for(std::size_t i=0; i<numOfItems; i++){
    if(bag[i]==item){
      freq++; //if we found the item, increment frequency by one 
    }
  }
  return freq; //whatever it ends up being, returned frequency of the item 
};
