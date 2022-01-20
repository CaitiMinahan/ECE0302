#include "bitset.hpp"
#include <iostream>

// TODO
//Default construction of a valid bitset
Bitset::Bitset(){
    //construction of valid bitset of size 8, with all bits set to 0  
  N = 8; //set the width to 8 bits
  
  for(int i=0; i<N; i++){ //set all of the bits set to 0 using a for loop
      reset(i);}
  }

//Construction of a valid bitset of size N
Bitset::Bitset(intmax_t N){
    for(int i=0; i<N; i++){ //set all of the bits set to 0 using a for loop
      reset(i);}
    //define scenarios for when bitset is valid or invalid:
    if(N>0){
        isValid == true; //valid when N>0
    }
    else{
        isValid == false; //invalid when N<=0
    }
}

//Construction of a valid bitset with a string of 1's and 0's
Bitset::Bitset(const std::string & binary_value){
    N = binary_value.size(); //access the size of the bitset
    
    //iterate through the entire bitset and test if each character is either a 1 or 0:
    for(int i=0; i<N; i++){
        if(binary_value[i]=='1' || binary_value[i]=='0'){ //match each term of the bitset to either 1 or 0
            isValid == true;//valid when bitset contains only 1's and 0's
        }
        else{ 
            isValid == false;
        } 
    } 
}

//Method returns the size of the bitset (accessor)
intmax_t Bitset::size() const{ 
    //accessor function with return statement
    return N;
}

//Method to determine if bitset is valid (accessor)
bool Bitset::good() const{
    //accessor function with return statement
    return isValid;
}

//Method to set the nth to the value 1 (mutator)
void Bitset::set(intmax_t n){
    if(n>0 && n<N){ //test if n is in [0, N-1]:
        isValid == true; }
    else{
        isValid == false;}

    //set the nth bit to value 1
    //binary_value[n] == '1'; 
}

//Method to reset the nth bit to the value 0 (mutator)
void Bitset::reset(intmax_t n){
    n = 0;
}

//Method to toggle the nth bit (mutator)
void Bitset::toggle(intmax_t n){
    //n = 
}

//Check if the nth bit is set to 1, return T for 1 otherwise return F for 0 (accessor)
bool Bitset::test(intmax_t n){
    return isValid;
}

//Get the bitset and convert it to a string and return the string (accessor)
string Bitset::asString() const{ //Is it okay for me to remove the std:: part? 
    //accessor function with return statement
}