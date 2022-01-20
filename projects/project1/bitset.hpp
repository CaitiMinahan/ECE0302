#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>
using std::string;

class Bitset{
public:
  //Default construction of a valid bitset
  Bitset();

  //Construction of a valid bitset of size N
  Bitset(intmax_t size);

  //Construction of a valid bitset with a string of 1's and 0's
  Bitset(const std::string & value);

  //Default deconstructor of Bitset
  ~Bitset();

  //shows that this is a not copy constructible 
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //Method returns the size of the bitset (accessor)
  intmax_t size() const;

  //Method to determine if bitset is valid (accessor)
  bool good() const;

  //Method to set the nth to the value 1 (mutator)
  void set(intmax_t index);

  //Method to reset the nth bit to the value 0 (mutator)
  void reset(intmax_t index);

  //Method to toggle the nth bit (mutator)
  void toggle(intmax_t index);

  //Check if the nth bit is set to 1, return T for 1 otherwise return F for 0 (accessor)
  bool test(intmax_t index);

  //Get the bitset and convert it to a string and return the string (accessor)
  std::string asString() const;

private:
  //variable to state validity of a biset
  bool isValid; //this variable will return (true) if bitset is valid or (false) otherwise
                //General note: isValid == false when:
                //  1) size of bitset is either not 8 or <=0 
                //  2) bitset contains characters other than 1 or 0 
                //  3) when setting the nth bit of the bitset, the n is outside of [0, N-1}]

  intmax_t N, n; //private variables representing the size (N), and the nth bit (n)
};

#endif
