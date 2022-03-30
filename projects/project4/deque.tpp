#include "deque.hpp"

//define your helper function up here: 
template <typename T>
T Deque<T>::getEntry(std::size_t position) const{
  return d.getEntry(position); 
}
template <typename T>
Deque<T>::Deque(){
    //our member variable "d" will use the default constructor from the linked list
}
template <typename T>
Deque<T>::Deque(const Deque& x){
    //makes copy of the deque in a singly-linked list 
    d = x.d; //uses the linked list constructor implementation 
}
template <typename T>
Deque<T>::~Deque(){
    while(!isEmpty()){
        popFront(); //remove the items
    }
}
template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& x){
    //makes copy of the deque in a singly-linked list 
    d = x.d; 

    //return reference 
    return *this;
}
template<typename T>
bool Deque<T>::isEmpty() const noexcept{
    return d.isEmpty(); //reuses the isEmpty() method from linked list 
}
template<typename T>
void Deque<T>::pushFront(const T & item){
    //insert item at position zero of the list 
    d.insert(0, item);  
    //if position is out of range, throw a range error:
    // if(!d.insert(0,item)){
    //     throw std::range_error("attempt to push front when position is NOT equal to zero"); } //I don't know if this is correct
}
template<typename T>
void Deque<T>::popFront(){
    //call the remove function from linked list, but remove at position 0
    d.remove(0); 
    //if position is out of range, throw a range error:
    // if(!d.remove(0)){
    //     throw std::range_error("attempt to pop front when position is NOT equal to zero"); } //I don't know if this is correct
}
template<typename T>
T Deque<T>::front() const{
    //call the getEntry method to return a copy of the item in the front of the queue 
   return d.getEntry(0); 
}
template<typename T>
void Deque<T>::pushBack(const T & item){
    //if the deque is empty, we will insert the first item like so:
    if(d.getLength()==0){
        //insert at position zero, or call the push front method:
        d.insert(0, item); 
    }
    else{ //toherwise, if the list in NOT empty, we will insert item at position N of the list 
        d.insert(d.getLength(), item);  
    }
    //if position is out of range, throw a range error:
    // if(!d.insert(d.getLength(),item)){
    //     throw std::range_error("attempt to push back when position is NOT equal to length of deque"); } //I don't know if this is correct
}
template<typename T>
void Deque<T>::popBack(){
    //if the list is empty, we will get a range error
    if(d.isEmpty()){
        throw std::range_error("attempt to pop item from an empty deck");
    }
    //otherwsie, if the deque is not empty, call the remove function from linked list, but remove at position N
    else{ 
        d.remove(d.getLength()-1); }
    //if position is out of range, throw a range error:
    // if(!d.remove(d.getLength()-1)){
    //     throw std::range_error("attempt to pop back when position is NOT equal to N"); } //I don't know if this is correct
}
template<typename T>
T Deque<T>::back() const{
    //call the getEntry method to return a copy of the item in the back of the queue 
   return d.getEntry(d.getLength()-1); 
}
