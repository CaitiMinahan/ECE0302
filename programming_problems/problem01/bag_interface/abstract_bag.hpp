#ifndef ABSTRACT_BAG_HPP
#define ABSTRACT_BAG_HPP

//Create template for AbstractBag class
template<typename T> class AbstractBag{

//Use methods from bag_simple.hpp to know what to define here
//Make all of the methods pure virtual since this is an abstract class
//No private variables because we need everything in the abstract class to be public in order to 
  //implement in the derived classes
public:
  virtual std::size_t getCurrentSize() const = 0; //gets quantity of total items in bag

  virtual bool isEmpty() const = 0; //determines whether the bag is empty or contains at least one item

  virtual bool add(const T& entry) = 0; //determines if an item has been added from bag

  virtual bool remove(const T& entry) = 0; //determines if an item has been removed from bag

  virtual void clear() = 0; //empties all contents of the bag

  virtual std::size_t getFrequencyOf(const T& entry) const = 0; //gets the quantity of a particular item in the bag 

  virtual bool contains(const T& entry) const = 0; //determines whether bag contains a certain item 

};
#endif