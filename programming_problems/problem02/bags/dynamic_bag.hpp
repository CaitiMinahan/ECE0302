#ifndef _DYNAMIC_BAG_HPP_
#define _DYNAMIC_BAG_HPP_

#include "abstract_bag.hpp"

template <typename T>
class DynamicBag: public AbstractBag<T>
{
public:
  // default constructor
  DynamicBag(); //create the bag as an array of type T 
                //need to declare a max size here 
                //need a private variable for the max size of the array 
  
  // copy constructor
  DynamicBag(const DynamicBag& x); //copy constructor 
                                  //copies contents of first bag into a second bag named x
                                  //iterate through entire first bag and assign it equal to the second bag 
                                  //eliminate blank spaces from first bag by filling up x to the size of getCurrentSize()                                     
                                  //delete the original bag since you just have x now 
  // destructor
  ~DynamicBag(); //dynamically deallocate contents of your bag array 
  
  // copy assignment
  DynamicBag& operator=(DynamicBag& x);
                                    //copy assignment operator (should do the same thing as the copy constructor)
                                    //again, copy all of the contents of first bag into second bag named x 
  // add an item to the bag
  bool add(const T & item); //tests if an add was successful or not (bool)
                            //to add, the current size should increase by 1 (assume we add to x) then current size = max size 
                            //we need to increase the max size of the bag in order to fit a new item inside it 
  
  // remove an item
  bool remove(const T & item); //tests if a remove was successful or not (bool) 
                               //to remove, decrement the size of x by 1

  // check is the bag is empty
  bool isEmpty() const; //tests if the bag has zero items in it 
                        //you will need to call the getCurrentSize() and test if that is zero, if getCurrentSize() = 0, return true

  // get number of items in the bag
  std::size_t getCurrentSize() const; //return the private member variable for the number of items in the bag 
                                      //remember, we do not want to return the max size of the array, because it isn't accurate to the # items in the bag 

  // clear the bag contents
  void clear(); //to clear the contents of the array, let's iterate through the array and set all of the elements to zero 

  // count how many time item occurs in bag
  std::size_t getFrequencyOf(const T & item) const; //if item is found somewhere in the index, the freq is at least one
                                                    //iterate throughout the entire array, and if you find that item again, incremenet the freq variable

  // check if item is in the bag
  bool contains(const T& item) const; //iterate through the entire array and see if that item is in some index of the array 
                                      //if the item is found somewhere in the array, return true 

private:
  T * bag; //bag array variable 
  std::size_t maxsize, numOfItems; //max size of the bag and the number of items 
                           //need two variables b/c the bag isn't always full; may have empty spaces 
};

#include "dynamic_bag.tpp"

#endif
