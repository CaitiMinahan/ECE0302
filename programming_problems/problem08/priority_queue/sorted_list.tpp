#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  //have conditions of where to insert an item at the ordered position
  //NOTE: we must have our list be in ASCENDING order: 

  //traverse list, insert accordingly 
  int pos = 0; //pos represents location in the list where we insert the higher valued item
  for(int i=0; i<plist.getLength(); i++){
    if(plist.getEntry(i)<item) pos++; //skip through list until we can insert the higher valued item
  }
  //insert item once we are done incrementing:
  plist.insert(pos, item);

  //print out the list:
  // for(int i=0; i<plist.getLength(); i++){
  //   std::cout << plist.getEntry(i) << std::endl; 
  // }

}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  //traverse list, insert accordingly 
  int pos = 0; //pos represents location in the list where we insert the higher valued item
  for(int i=0; i<plist.getLength(); i++){
    if(plist.getEntry(i)<item) pos++; //skip through list until we can insert the higher valued item
  }
  //insert item once we are done incrementing:
  plist.remove(pos);

  //print out the list:
  // for(int i=0; i<plist.getLength(); i++){
  //   std::cout << plist.getEntry(i) << std::endl; 
  // }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // get the position of the first occurance of item or negated position
  // where it would be inserted.
  //return 0;
  for(long int i=0; i<plist.getLength(); i++){
    if(plist.getEntry(i)==newValue){
      return i; 
    }
    //std::cout<< -i << std::endl; 
    else if(i==plist.getLength()-1){
      return -1*(i+1); 
    }
    else if((newValue>plist.getEntry(i)) || (newValue<plist.getEntry(i+1)) ){
      return -1*(i+1); 
    }
    //return -i; //if item is not in the list, return the negated index
  }
 //throw std::range_error("item not in list"); 
 return -1*(plist.getLength()); 
}
