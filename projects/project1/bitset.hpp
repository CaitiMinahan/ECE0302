#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

  //Default construction of a valid bitset
  Bitset();

  //Construction of a valid bitset of size N
  Bitset(intmax_t size);

  //Construction of a valid bitset with a string of 1's and 0's
  Bitset(const std::string & value);

  // TODO COMMENT
  ~Bitset();

  //shows that this is a not copy constructible 
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // TODO COMMENT
  intmax_t size() const;

  // TODO COMMENT
  bool good() const;

  // TODO COMMENT
  void set(intmax_t index);

  // TODO COMMENT
  void reset(intmax_t index);

  // TODO COMMENT
  void toggle(intmax_t index);

  // TODO COMMENT
  bool test(intmax_t index);

  // TODO COMMENT
  std::string asString() const;

private:
  //variable to state validity of a biset
  bool isValid;
};

#endif
