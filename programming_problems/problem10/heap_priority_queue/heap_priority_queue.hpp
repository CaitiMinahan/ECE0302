
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.hpp"
#include "dynamic_array_list.hpp"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //use composition 
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    //use insert method for a max heap 
    //need to compare entry with items in the list 
    //make sure it is in descending order (from root to leaves)
    
    //keep traversing through the list until we found the proper spot to insert 
    
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    //reuse with composition
    lst.remove(0); //remove root
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //use composition to reuse the getEntry() method from dynamic_array_list
    return lst.getEntry(0); //get the item from the top, so at position 0
}


#endif // _HEAP_PRIORITY_QUEUE_H_
