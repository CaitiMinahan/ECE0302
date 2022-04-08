#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost
  //a min heap goes in ascending order from root to leaves (smallest at root and largest at leaves)

  //first test if the heap is empty:
  if(empty()) throw std::logic_error("empty queue, nothing to remove"); 

  //if queue is not empty, we will do the remove procedure for a min heap and return the state

  //special condition if the queue only has one element in it: 
  else if(queue.size()==1){
    //then we will return the state as being the only item in the queue 
    State<T> st = queue[0]; //assign state to the only item in the queue
    queue.pop_back(); //use pop_back to remove from queue
    return st; //return you state, which is what you just removed
  }

  //otherwise, if there are multiple elements in the queue:
  else{ 
    State<T> st = queue[0]; //create your initial state at position 0 in the queue

    //define parent and children: 
    int root = 0; 
    int left = 1; 
    int right = 2;

    //remove root: 
    queue[root] = queue[queue.size()-1]; //replace with "last node" (most recently linked node
    queue.pop_back(); 

    //exchange root node with smallest child (if smaller)
    while(left<queue.size() && left>0){ //make sure the tree has maintained structure
      //exchange requires comparison which we will use getFzCost for 
      if(queue[right].getFCost()<queue[left].getFCost() && queue[right].getFCost()<queue[root].getFCost()){
        //swap root with smallest child: 
        State<T> sm = queue[root]; //remember state for swapping
        queue[root] = queue[right]; 
        queue[right] = sm; 
        root = right; 
      }
      if(queue[left].getFCost()<queue[root].getFCost()){
        State<T> ss = queue[root]; 
        queue[root] = queue[left];
        queue[left] = ss; 
        root = left; 
      }
      else break; //break statement means the removal still maintains the min heap structure, no need to compare further 
      
      //increment children:
      right = (root+1)<<1;
      left = root-1;  

      //repeat exchange of parent with smaller child as needed (until we have min heap structure)
      //this means we will let the while loop run until we have reached this condition: 
      if(right>queue.size()) break; //break when we do not maintain heap structure

    }
    // needs return state
    return st; //return first element we popped 
  }
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //implement this the same way we implemented push in the heap lecture.

  State<T> st(p,cost, heur); //push a state with value p, cost and heur

  //first test if the heap is empty:
  if(empty()){
    queue.push_back(st); //push the state
    return;
  }
  //otherwise, if we have stuff in the heap: 
  else{
    //add the element to the next empty spot, which can be done using push_back
    queue.push_back(st); 

    int n = queue.size()-1; 
    int parent = n>>1; 

    //exchange element with parent node if it is smaller than the parent 
    while(parent!=0 && queue[parent].getFCost() > queue[n].getFCost()){
      //swap elements to maintain min heap structure: 
      State<T> sm = queue[parent]; 
      queue[parent] = queue[n]; 
      queue[n] = sm;

      n = parent; 
      parent = (parent-1)/2; //for the bitwise operation
    }
  }
  //repeat exchange as needed 
  return; 
}

template <typename T>
bool frontier_queue<T>::empty() {

  //test if queue is empty: 
  if(queue.size()==0) return true; 
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //search through the length of the queue and return true if value is found 
  //use getValue() 
  for(int i=0; i<queue.size(); i++){
    if(queue[i].getValue()==p) return true;
  }
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //search through the length of the queue and compare path costs
  //use getPathCost() 
  for(int i=0; i<queue.size(); i++){
    if(queue[i].getValue()==p && queue[i].getPathCost() > cost){
      queue[i].updatePathCost(cost); 
    }
  }
  return; //to continue search and updating path costs as needed 
}


