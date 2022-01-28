#ifndef LIMITED_SIZE_BAG_HPP
#define LIMITED_SIZE_BAG_HPP

#include "abstract_bag.hpp"

template <typename T>
class LimitedSizeBag: public AbstractBag<T>
{
public:
  // default constructor
  LimitedSizeBag();
  
  // copy constructor
  LimitedSizeBag(const LimitedSizeBag& x);
    
  // destructor
  ~LimitedSizeBag();
  
  // copy assignment
  LimitedSizeBag& operator=(LimitedSizeBag& x);

  // add an item to the bag
  bool add(const T & item); //here, we are limited to how many items we can add
                            //we should first test to see if the bag is completely full or not 
                            //if it's at max capacity, we can't increase the size of the bag, so the add will be unsuccessful 
  
  // remove an item
  bool remove(const T & item);

  // check is the bag is empty
  bool isEmpty() const;

  // get number of items in the bag
  std::size_t getCurrentSize() const;

  // clear the bag contents
  void clear();

  // count how many time item occurs in bag
  std::size_t getFrequencyOf(const T & item) const;

  // check if item is in the bag
  bool contains(const T& item) const;

  //define max size of bag as a public static constant variable:
  static const std::size_t maxsize = 100; //this will prevent us from being able to increase the size of the bag 

private:
  T * bag; //define your bag array 
  int numOfItems; //define the number of items in the bag 
};

#include "limited_size_bag.tpp"

#endif
