#include "bitset.hpp"
#include <iostream>

// TODO
//Default construction of a valid bitset
Bitset::Bitset(){
    //construction of valid bitset of size 8, with all bits set to 0  
  N = 8; //set the width to 8 bits
  bitset = new char [N]; //create new array of chars for bitset -> this way we won't have to convert from another data type 
  for(int i=0; i<N; i++){ //set all of the bits set to 0 using a for loop
      reset(i);}
  }

//Construction of a valid bitset of size N
Bitset::Bitset(intmax_t size){
    bitset = new char [size]; 
    N = size;
    for(int i=0; i<N; i++){ //set all of the bits set to 0 using a for loop
      reset(i);}
    //define scenarios for when bitset is valid or invalid:
    if(N>0){
        isValid = true; //valid when N>0
    }
    else{
        isValid = false; //invalid when N<=0
    }
}

//Construction of a valid bitset with a string of 1's and 0's
Bitset::Bitset(const std::string & binary_value){
    bitset = new char [N]; 
    N = binary_value.size(); //access the size of the bitset
    
    //iterate through the entire bitset and test if each character is either a 1 or 0:
    for(int i=0; i<N; i++){
        if(binary_value[i]=='1' || binary_value[i]=='0'){ //match each term of the bitset to either 1 or 0
            isValid = true;//valid when bitset contains only 1's and 0's
            bitset[i] = binary_value[i]; //fill the array with the argument for the binary value you are passing 
        }
        else{ 
            isValid = false;
            break; //breaks for loop at nth bit when false so that it stops counting 
        } 
    } 
}

//Default deconstructor of Bitset
Bitset::~Bitset(){
    delete[] bitset; //deallocate bitset array
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
       bitset[n] = '1'; //set the nth bit to 1
       isValid = true; }
    else{
        isValid = false;}

}

//Method to reset the nth bit to the value 0 (mutator)
void Bitset::reset(intmax_t n){
    if(n>0 && n<N){ //test if n is in [0, N-1]:
       bitset[n] = '0'; //set the nth bit to 0
       isValid = true; }
    else{
        isValid = false;}
}

//Method to toggle the nth bit (mutator)
void Bitset::toggle(intmax_t n){
    if(n>0 && n<N){ //test if n is in [0, N-1]
       isValid = true; 
       if(bitset[n]=='1'){
         bitset[n] = '0';} //set the nth bit to 0
        else{
         bitset[n] = '1'; } //set the nth bit to 1
       }
    else{
        isValid = false;}
}

//Check if the nth bit is set to 1, return T for 1 otherwise return F for 0 (accessor)
bool Bitset::test(intmax_t n){
    //first, test to see if 
    if(n>0 && n<N){ //test if n is in [0, N-1]
       isValid = true; 
       if(n==1){
           return true;} //return bool value of true if nth bit is set to 1
        else{ 
            return false;} //return bool value of false if nth bit is set to 0
        }
    else{
        isValid = false;
        return false;}
}

//Get the bitset and convert it to a string and return the string (accessor)
std::string Bitset::asString() const{ //Is it okay for me to remove the std:: part? 
    std::string str = ""; //declare a temporary empty string 
    for(int i=0; i<N; i++){
        str += bitset[i]; //add onto the string, each bit of the biset 
    }
    return str; //return the string of chars of 0's and 1's 
}