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
  //remember not to copy over the possible blank spots from first bag into bag x 

  //declare your first and second bags: 
  bag = new T[maxsize]; //not sure if it will know what the maxsize is, but try this for now ?????
  x = new T[bag.getCurrentSize()]; //only want x to have enough space to the items we care about; no blanks 

  //use a for loop to iterate through entire first bag and copy over contents individually into x: 
  for(std::size_t i = 0; i<bag.getCurrentSize(); i++){
      bag[i] = x[i]; 
  }

  //just like in the default constructor, you must define what the number of items in your new bag x: 
  numOfItems = x.getCurrentSize(); 

  //do i need to define what the max size of x is?? not sure if i did that above or not ???
  //i want the maxsize of bag x to be equal to bag.getCurrentSize()
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] bag; //deallocate and delete your bag array 
  //don't have to delete bag x because we only want to work with that further ???
}
  
template<typename T> 
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  //since the copy constructor and copy assignment do the same thing, let's use the same code as above: 

  //clear the array before copying it again
  //i wonder if the clear() method does the same thing here ?????
  bag = new T[maxsize]; //?????
  bag.clear();  //?????

  x = new T[bag.getCurrentSize()]; //define bag x with desired size 

  //use a for loop to iterate through entire first bag and copy over contents individually: 
  for(std::size_t i = 0; i<bag.getCurrentSize(); i++){
      bag[i] = x[i]; 
  }

  //just like in the default constructor, you must define what the number of items in your new bag x: 
  numOfItems = x.getCurrentSize(); 
  
  return *this; //returns reference to the object, where the object here is bag x (i.e., DynamicBag<T>& x)
                //we are able to say "return *this" since the return type is a REFERENCE to an object of type T
}

template<typename T>
bool DynamicBag<T>::add(const T& item) //test if adding an item to the bag was successful or not 
{
  //successful add would be if you tried to add an item, and the size of the bag was increased by 1
  //usually when we add to an array, we just tack it onto the END of the array 

  //what if the bag is already completely full? We need to ALLOCATE MORE MEMORY to add to it: 
  if(numOfItems = maxsize){ 
    Largerbag = new T[maxsize+maxsize]; //make new temporary array and adding more room to add items 
                                      //we do this to have a placeholder while we put our original items into a bigger bag 
    //use the temporary bag to put original bag's items into a larger bag: 
    for(std::size_t i=0; i<bag.getCurrentSize(); i++){
      Largerbag[i] = bag[i]; //copy contents of original bag into larger bag named Largerbag
    }
  delete[] bag; //delete the original bag, we don't need that small thing anymore: 
  bag = Largerbag; //rename Largerbag to just bag using assignment: 

  //now, let's physically ADD the item to the end of the bag array: 
  bag.getCurrentSize() = item; //make the item be in the LAST SPOT of the bag array 
  numOfItems++; //incremenet the number of items in the bag by ONE 
  return true; //denote a SUCCESSFUL ADD to the bag 
  }

  //an unsuccessful add would be if you tried to add an item, and the size WASN'T increased by 1
  if(numOfItems++){ //if we added an item, 
    bag.getCurrentSize() != item; //and we DIDN'T make the item be in the LAST SPOT of the bag array 
    return false; //then the add was unsuccessful 
                  //I only want the new item to be added to the END of the array 
  }
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{ //a successful remove would be the numOfItems being decremented by 1 
  if(numOfItems--){ //if an item is removed, the number of items is decreased by one 
    //NOTE: if you randomly remove an item, you make sure there are no empty gaps in the array 
    for(std::size_t i=0; i<bag.getCurrentSize(); i++){
      bag[i] = bag[i+1]; //shift elements in array after removal 
                         //found from stack overflow 
    }
    return true; //denote a SUCCESSFUL REMOVE from the bag 
  }
  //an unsuccessful remove would be if the bag is empty and has nothing to remove:
  if(bag.getCurrentSize()==0){
    return false; 
  }
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{ //test if there are zero items in the bag: 
  if(numOfItems==0{
    return true; 
  }
  else{ return false; } //bag can't be empty if there is more than 0 items in bag 
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const 
{
  return numOfItems; //returns the size aka the number of items in the bag 
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{ //test if item is found somewhere in the array 
  for(std::size_t i=0; i<bag.getCurrentSize(); i++){ //search through the entire array 
    if(bag[i]==item){
      return true; //means we've found the item contained in the bag 
    }
    else{
      return false; //item is not contained in bag 
    }
  }
}

template<typename T>
void DynamicBag<T>::clear(){
  //we can clear the bag by setting all of the elements equal to zero 
  for(std::size_t i=0; i<bag.getCurrentSize(); i++){
    bag[i] = 0;
  }
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{ //define a frequency variable to be returned 
  std::size_t freq; 

  //search through entire array and check frequency of item: 
  for(std::size_t i=0; i<bag.getCurrentSize(); i++){
    if(bag[i]==item){
      freq++; //if we found the item, increment frequency by one 
    }
    else{ freq = 0;}
  }
  return freq; //whatever it ends up being, returned frequency of the item 
};
