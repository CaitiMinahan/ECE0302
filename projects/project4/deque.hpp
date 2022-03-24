#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{

  public: 
  // default constructor
  Deque();
  
  // copy constructor
  Deque(const Deque& x);
    
  // destructor
  ~Deque();
  
  // copy assignment
  Deque& operator=(const Deque& x);

/** Returns true if the deque is empty, else false
   */
  bool isEmpty() const noexcept;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  void pushFront(const T & item);

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popFront();

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  T front() const; //like a peek method

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  void pushBack(const T & item);

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popBack();

  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  T back() const; //like peek from the back  

  private: 
  //a deque is a linked list, so let's use composition here
  //we will reuse linked_list methods with composition like so: 
  LinkedList<T> d; //private deque 

  //helper function for the constructors (constructors make the copy of deque in a singly linked list): 
  // get a copy of the item at position using 0-based indexing
  T getEntry(std::size_t position) const;

};

#include "deque.tpp"

#endif
