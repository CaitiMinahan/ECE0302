//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr), currentSize(0)
{
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear(); 
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	//return true;
	return currentSize==0; 
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	//return 0;
	return currentSize; 
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	//return true;
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)
	Node<ItemType>* nextNodePtr = new Node<ItemType>(newItem, headPtr); // alternate code

	headPtr = nextNodePtr; // New node is now first node, which is the top of the stack
	currentSize++;
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	//throw catch if the stack is empty 
    if(isEmpty()){
		throw std::logic_error("list is empty, nothing to peek");
	}
	//headPtr->getNext(); //access the item at the top of the stack 
	//ItemType returnItem;
	//returnItem.getItem(); 
	return headPtr->getItem();
} 

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	//make sure stack isn't empty so we can pop:
	if(!isEmpty()){
		//create temp node 
		Node<ItemType>* tempNodePtr = headPtr; //extract the original headPtr
		//reposition the headptr
      	headPtr = headPtr->getNext(); 
		//set headptr to nullptr to delete it
		tempNodePtr->setNext(nullptr); 
    	delete tempNodePtr; //use delete keyword
    	tempNodePtr = nullptr;
	currentSize--; //decrease size of the stack
	return true; 
	}
	return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	if (headPtr != nullptr) { 
		Node<ItemType>* tempNodePtr = headPtr; //extract the original headPtr
		Node<ItemType>* nextNodePtr = headPtr->getNext(); 
		
		

		while(nextNodePtr!=nullptr){
			delete tempNodePtr; 
			tempNodePtr = nextNodePtr; 
			nextNodePtr = nextNodePtr->getNext(); 
		}

		
		currentSize = 0; 
		headPtr = nullptr; 
	}
}  // end clear

