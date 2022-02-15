#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include <vector>

#include <stack> //include the stack header 

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) { //convert from postfix to prefix 
  //do input validation for that argument is purely symbolic (no numbers)!
  //if(argument does not contain symbols from the alphabet){error}
  //verify postfix is a valid postfix expression: 
  if(isPost(postfix)){ //if postfix string is valid, 
  //let's say we have potsfix expression: ab+
  //use pop_back() to take last element and push it to the postfix string (push_back())
  //we can use back() as a reference to the last element of either string 
    std::stack<string> s; 
    
    for(int i=0; i<postfix.size(); i++){
    //if the symbol is an operator, then pop two operands from the stack
    if(isoperator(postfix[i])){
      string operand1 = s.top(); 
      s.pop(); //obstain value from top of stack -- pop it 
      string operand2 = s.top(); 
      s.pop(); 

      //concatenate the operands and the operator: 
      prefix = postfix[i] + operand2 + operand1; //should look like: operator|operand2|operand1
      
      //push string temp to the stack: 
      s.push(prefix);
    }
    //if the symbol is an operand, then push it to the stack 
    else{
      //push the operand to the stack: 
      s.push(string(1, postfix[i])); //loop back up to the next index of postfix string 
    }
    //repeat until the end of postfix expression 
    }
  }
}