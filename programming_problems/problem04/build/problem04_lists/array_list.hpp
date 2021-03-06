#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "abstract_list.hpp"
#include <iostream>

template<typename T>
class ArrayList: public AbstractList<T>
{
public:

  // default constructor
  ArrayList();

  // destructor
  ~ArrayList();

  // copy constructor
  ArrayList(const ArrayList & rhs);

  // copy assignment
  ArrayList & operator=(const ArrayList & rhs);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;
  
  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T& newValue);
  
  //define max size of bag as a public static constant variable:
  //static const std::size_t maxsize = 100; //this will prevent us from being able to increase the size of the bag 

private:
  // TODO
  T *ADTlist; //for your ADT array 
  std::size_t size, maxsize; //for your array size 
};

#include "array_list.tpp"

#endif
