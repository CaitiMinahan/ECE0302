#include "linked_list.hpp"
#include <iostream>

//define your private method for returning the currentptr
template<typename T> 
Node<T>* LinkedList<T>::getCurrentNode(std::size_t position) const{
  //create your currentptr variable: 
  Node<T>* currentPtr; 
  //start at the beginning of the list and traverse by means of a for loop: 
  currentPtr = headptr; 
  for(std::size_t i=1; i<position; i++){ 
    //make sure we are within bounds so that we don't get a seg fault: 
    //break condition: creds stackedoverflow 
    if(position<0 || position>size){
      break; //means this loop will break if we try to traverse out of bounds 
    }
    currentPtr = currentPtr->getNext(); //makes the currentPtr continue to point to the next item in the list 
  }
  //return your currentPtr: 
  return currentPtr; 
}

template <typename T>
LinkedList<T>::LinkedList()
{
  //set your headptr and size of list: 
  headptr = nullptr; //initializing headptr to null allows us to start with an empty list 
  size = 0;   
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear(); //clear the list 
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) //copy constructor
{
  Node<T>* newPtr = x.headptr; 
  size = x.size; //set the size of the list

  //now copy contents into the new list:
  //this means we need to copy all the nodes using 1-based indexing
  if(newPtr==nullptr){ //if the list is empty 
    headptr = nullptr; //set the headptr as the nullptr, since list is empty
  } 
  else{ //otherwise, if there is stuff in our list,
    //create new node and set the headptr: 
    headptr = new Node<T>(); 
    headptr->setItem(newPtr->getItem()); //set the item for headptr
    newPtr = newPtr->getNext(); //have newPtr point to the next item in the list

    //preserve the location of the headptr in another node: 
    Node<T>* headptr_holder = headptr; //call the new headptr something else, since we just reset what it is 

    while(newPtr!=nullptr){ //make sure our new node isn't pointing to nullptr
    //now define the value in the next ptr (newPtr) and preserve that value in another node 
    T value = newPtr->getItem(); //gets the item in the node it's pointing to 
    Node<T>* value_holder = new Node<T>(value); //creates the node to hold this value 
    headptr_holder->setNext(value_holder); //setNext as headptr -- make next point to former first node
                                           //makes sure the node in between headptr and the newPtr has the correct value

    //now, shift both pointers in the correct position in the list using getNext(): 
    newPtr = newPtr->getNext(); 
    headptr_holder = headptr_holder->getNext(); 
    }
    //Note: 
    //getItem() --> returns the value held at a node 
    //setItem() --> sets the item to be contained within node
    //getNext() --> returns the node it is now shifted to 
    //setNext() --> points to node proceeding its current position
  }
  
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //do the same thing as in the copy constructor and then return *this
  //set the headptr like in the default constructor: see if this causes an issue later ??? 
  Node<T>* newPtr = x.headptr; 
  size = x.size; //set the size of the list

  //now copy contents into the new list:
  //this means we need to copy all the nodes using 1-based indexing
  if(newPtr==nullptr){ //if the list is empty 
    headptr = nullptr; //set the headptr as the nullptr, since list is empty
  } 
  else{ //otherwise, if there is stuff in our list,
    //create new node and set the headptr: 
    headptr = new Node<T>(); 
    headptr->setItem(newPtr->getItem()); //set the item for headptr
    newPtr = newPtr->getNext(); //have newPtr point to the next item in the list

    //preserve the location of the headptr in another node: 
    Node<T>* headptr_holder = headptr; //call the new headptr something else, since we just reset what it is 

    while(newPtr!=nullptr){ //make sure our new node isn't pointing to nullptr
    //now define the value in the next ptr (newPtr) and preserve that value in another node 
    T value = newPtr->getItem(); //gets the item in the node it's pointing to 
    Node<T>* value_holder = new Node<T>(value); //creates the node to hold this value 
    headptr_holder->setNext(value_holder); //setNext as headptr -- make next point to former first node
                                           //makes sure the node in between headptr and the newPtr has the correct value

    //now, shift both pointers in the correct position in the list using getNext(): 
    newPtr = newPtr->getNext(); 
    headptr_holder = headptr_holder->getNext(); 
    }
  }
  return *this;
}

// swap two lists 
template<typename T>
void LinkedList<T>::swap(LinkedList& x, LinkedList& y){
  //call the copy constructor and create a temp list: 
  LinkedList<T> temp(x); //copy x into the temp list 
  x = y; 
  y = temp;
}

template <typename T>
bool LinkedList<T>::isEmpty() const 
{
  //return true;
  return (size==0); 
}

template <typename T>
std::size_t LinkedList<T>::getLength() const 
{
  //return 0;
  return size; 
  //return size-1;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //return true;
  //define some conditions to ensure a successful add: 

  //make sure we are within bounds of the list: 
  if(position>=0 && (position<=size+1)){
    //condition for inserting at the beginning: 
    // 1) create new node to be added to the beginning 
    //   a) set item 
    //   b) setNext as headptr - make next point to the former first node 
    // 2) set the new node equal to the headptr now 
    //   a) make head point to this new first node 
    // 3) increment item count 
    Node<T>* newPtr = new Node<T>(item); //creates the new node to be added which contains 'item'
    if(position==0){
      newPtr->setNext(headptr); //setNext as headptr -- make next point to former first node
      headptr = newPtr; 
    }
    //condition for inserting anywhere: 
    // 1) traverse the list to node (i-1) to get the pointer to node i 
    //   a) prevNodePtr->getNext() - this is the pointer at node(i-1)
    // 2) create new node using the pointer to node (i) as next 
    //   a) newNodePtr = new Node(item, iNodePtr)
    // 3) set node (i-1) to point to the new node 
    //   a) prevNodePtr->setNext(newNodePtr)
    else{
      //get node at (i-1): 
      Node<T>* prevNodePtr = getCurrentNode(position-1); //use the private accessor method to get that node 
      //prevNodePtr = prevNodePtr->getNext(); 

      //use your newPtr to point to node (i) aka where we will be doing the insertion: 
      newPtr->setNext(prevNodePtr->getNext()); //make new node point to the node that comes after prevNodePtr
      prevNodePtr->setNext(newPtr); 
    }
  //increment item count: 
  size++; 
  }
  return true; //denote successful insertion 
  // //make sure we can't insert in an invalid place: 
  // if(position<0 || position>size){
  //   return false; 
  //   }
  }

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //return true;
  //Goal: remove the node at the specified position i
  // 1) traverse the list to find and save the pointer to node (i-1) -- aka prevNodePtr
  // 2) traverse to node i and save the pointer to node (i+1) 
  // 3) delete node i (deallocate) 
  // 4) set node (i-1) to point to the node originally at (i+1) -- aka prevNodePtr->setNext()

  //make sure to keep these updated: 
  //1) update the size of our list
  //2) update the headptr if the index==0
  //3) update the tail ptr if the index i is at the end of the list 
  Node<T>* newPtr = nullptr; //creates the new node 
  if(position>=0 && (position<=size+1)){
    if(position==0){
      newPtr = headptr; 
      headptr = headptr->getNext(); //shift the headptr since we deleted the spot before it
    }
    else{ 
      Node<T>* prevNodePtr = getCurrentNode(position-1); //save node (i-1)
      //set where you want to make the removal: 
      newPtr = prevNodePtr->getNext(); //removing at index (i)
      //Node<T>* postNodePtr = getCurrentNode(position+1); //save node (i+1)
      //set node (i-1) to point to the node originally at (i+1): 
      prevNodePtr->setNext(newPtr->getNext()); 
    }
    //delete node i: 
    //first set the node to null:
    newPtr->setNext(nullptr); 
    delete newPtr; 
    newPtr = nullptr; 
    //then deallocate:
    //delete newPtr; 
    size--;
  }  
  return true; //denote successful remove

  if(position<0 || position>size){
    return false; 
    }
}

template <typename T>
void LinkedList<T>::clear()
{
  //reset the list to be empty 
  size = 0; 
  headptr = nullptr; 
  //see if this causes issues later ???
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //get a copy of the item at the position  
  if(position>=0 && position < size){
    Node<T>* newPtr = getCurrentNode(position); //save node (i)
    return newPtr->getItem() ; //return copy of the item at that position in the list 
  }
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position>=1 && position <= size+1){
    Node<T>* newPtr = new Node<T>(newValue); 
    if(position==0){
      newPtr->setNext(headptr); 
      headptr = newPtr; //set the headptr 
    }
    else{ 
      Node<T>* prevNodePtr = getCurrentNode(position-1); //save node (i-1)
      //insert the newptr: 
      newPtr->setNext(prevNodePtr->getNext()); //make new node point to the node that comes after prevNodePtr
      prevNodePtr->setNext(newPtr); 
    }
  //incremenet item count:
  //size++; 
  }
}
