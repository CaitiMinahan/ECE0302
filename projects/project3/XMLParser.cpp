// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

// TODO: Implement the constructor here
XMLParser::XMLParser()
{	/** Bag to store the XML element names*/
	
	elementNameBag = new Bag<std::string>;
	
	/** Stack to store XML tag names while parsing*/
	parseStack = new Stack<std::string>;
	
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear(); 
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{	//scan the input string 
	TokenStruct token; 	//store TokenStruct object 

	//1) test all markup

	//helper variables: 
	int count = 0; //keeps track of the number of characters inside a tag (text between < >)
	int i = 0; 
	int j = 0; 
	std::string temp = ""; 
	//***************************************************************************//
	//first, let's search through the entire string and determine the tag type:  //
	//***************************************************************************//
	for(i=0; i<inputString.size(); i+=j){ 
		// j = 0;  
		
		//if we find the open bracket to any tag: 
		if(inputString.at(i)=='<'){
			//********************************//
			//first, test for declaration tag //
			//********************************//
			if(inputString.at(i+1)=='?'){ //check for <? for the beginning of the tag 
				// cout << "declaration tag\n";
				j=i+2; //skip one more position to get the first character after the question mark in <?
				//make sure we are not at the end of the declaration tag 
				if(j<inputString.size()){
				while(inputString.at(j)!='?'&&inputString.at(j+1)!='>'){ //now, j is at the first char after the '?' but make sure we aren't at the end of the tag
					if(count>5000){ return false; } //we have exceeded the allowable amount of text assumed to be contained before the end of the tag (before ?>)
					
					//read in characters from tag and append to this temp string 
					temp += inputString.at(j);

				j++; //continue to search through the text within the tag 
				count++; //increase the number of characters allowed in the tag	
				}
				}
				j+=2; //skip over two more positions to see if we have another potential tag (so, skip over ?> ending to find another possible start to another tag)
				
				//once we've determined this tag to be a declaration tag, update tokenStruct and push it to the tokenizedVector:
				//temp should get updated here as declaration 
				token.tokenType=DECLARATION;  //assign token type 
				token.tokenString=temp; //assign name
				tokenizedInputVector.push_back(token); //push entire token to vector 
				temp.clear(); 
				// cout << temp << "\n"; 
			}  
			//*************************//
			//second, test for end tag //
			//*************************//
			else if(inputString.at(i+1)=='/'){ //test for / at the beginning of the tag
				// cout << "end tag\n";s
				count = 0; //reset the count 
				j=i+2; //skip one more position to get the first immediate character after the forward slash /
				if(j<inputString.size()){
				while(inputString.at(j)!='>'){ //j is now at the first character after </ but make sure we are not at the end of the tag
					if(count>5000){ cout << "u"; 
					return false; } //we have exceeded the allowable amount of text assumed to be contained before the end of the tag (before >)
					//input validation to check for illegal characters:
					if(inputString.at(j)=='\''||inputString.at(j)=='\\'||inputString.at(j)=='!'||inputString.at(j)=='"'||inputString.at(j)=='#'||inputString.at(j)=='$'||inputString.at(j)=='%'||inputString.at(j)=='&'||inputString.at(j)=='('||inputString.at(j)==')'||inputString.at(j)=='*'||inputString.at(j)=='+'||inputString.at(j)==','||inputString.at(j)=='/'||inputString.at(j)==';'||inputString.at(j)=='<'||inputString.at(j)=='='||inputString.at(j)=='>'||inputString.at(j)=='?'||inputString.at(j)=='@'||inputString.at(j)=='['||inputString.at(j)=='^'||inputString.at(j)=='`'||inputString.at(j)=='{'||inputString.at(j)=='|'||inputString.at(j)=='}'||inputString.at(j)=='~'||inputString.at(j)==' '){
						// cout << "z"; 
						return false; 
						//tag name cannot begin with any of these characters or numeric digits (text beginning after </ )
						if(inputString.at(j)=='-'||inputString.at(j)==','||inputString.at(j)=='.'||inputString.at(j)=='0'||inputString.at(j)=='1'||inputString.at(j)=='2'||inputString.at(j)=='3'|inputString.at(j)=='4'|inputString.at(j)=='5'|inputString.at(j)=='6'|inputString.at(j)=='7'|inputString.at(j)=='8'|inputString.at(j)=='9'){
							// cout << "b"; 
							return false;
						}
					}
					//read in characters from tag and append to this temp string 
					temp += inputString.at(j); 

				j++; //continue to search through the text within the tag
				count++; //increase the number of characters allowed in the tag	
				}
				}
			//j+=1; //skip over one more position to see if we have another potential tag (so, skip over > ending to find another possible start to another tag)
			
			//once we've determined this tag to be an end tag, update tokenStruct and push it to the tokenizedVector:
			//temp should get updated here as end 
			token.tokenType=END_TAG;  //assign token type 
			token.tokenString=temp; //assign name: read in chars and append to tokenString
			// cout << temp << "\n"; 
			tokenizedInputVector.push_back(token); //push entire token to vector 
			temp.clear(); 
			} 

			//*************************************************************//
			//third, if you haven't found a declaration, or an empty tag,  //
			//We must've found ourselves either an empty or start tag:	   //
			//*************************************************************//
			else{
				
				count = 0; 
				j=i+1; //skip one more position to get the first immediate character after the open bracket <
				
				if(j<inputString.size()){
				
				while(inputString.at(j)!=' '&&inputString.at(j)!='\n'&&inputString.at(j)!='\r'&&inputString.at(j)!='\t'&&inputString.at(j)!='>'){ //now, i is at the first character after < but make sure we are not at the end of the tag 
					
					if(count>5000){ cout << "g"; 
					return false; } //we have exceeded the alloweable amount of text assumed to be contained before the end of the tag (before />)
					//input validation to check for illegal characters:
					if(inputString.at(j)=='\''||inputString.at(j)=='\\'||inputString.at(j)=='!'||inputString.at(j)=='"'||inputString.at(j)=='#'||inputString.at(j)=='$'||inputString.at(j)=='%'||inputString.at(j)=='&'||inputString.at(j)=='('||inputString.at(j)==')'||inputString.at(j)=='*'||inputString.at(j)=='+'||inputString.at(j)==','||inputString.at(j)==';'||inputString.at(j)=='<'||inputString.at(j)=='='||inputString.at(j)=='>'||inputString.at(j)=='?'||inputString.at(j)=='@'||inputString.at(j)=='['||inputString.at(j)=='^'||inputString.at(j)=='`'||inputString.at(j)=='{'||inputString.at(j)=='|'||inputString.at(j)=='}'||inputString.at(j)=='~'||inputString.at(j)==' '){
						//cout << inputString.at(j); 
						// cout << "h";
						return false; 
						//tag name cannot begin with any of these characters or numeric digits (text beginning after < )
						if(inputString.at(j)=='-'||inputString.at(j)==','||inputString.at(j)=='.'||inputString.at(j)=='0'||inputString.at(j)=='1'||inputString.at(j)=='2'||inputString.at(j)=='3'|inputString.at(j)=='4'|inputString.at(j)=='5'|inputString.at(j)=='6'|inputString.at(j)=='7'|inputString.at(j)=='8'|inputString.at(j)=='9'){
							cout << "i"; 
							return false; 
						}
					}
					
					if(inputString.at(j)!='>'){ 
						temp += inputString.at(j); 
					
					//however, if we are caught at a /, we need to skip over one position to get to the end of the tag 
					if(inputString.at(j)=='/' && inputString.at(j+1)=='>'){
						//temp should get updated here as empty 
						// cout << "empty tag\n";
						token.tokenType=EMPTY_TAG;  //assign token type 
						temp.erase(temp.size());
						// cout << temp << "\n"; 
						token.tokenString=temp; //assign name: read in chars and append to tokenString
						tokenizedInputVector.push_back(token); //push entire token to vector 
						temp.clear();
						break;	
						}
						
					}//end of if statement which appends the tag string to temp
				j++; //continue to search through the text within the tag 
				count++; //increase the number of characters allowed in the tag 
				} //once the while loop is broken, we have found the ending bracket >   
				}
				//once we've determined this tag to be a start tag, update tokenStruct and push it to the tokenizedVector:
				//temp should get updated here as start 
				// cout << "start tag\n"; 
				// cout << temp << "\n"; 
				token.tokenType=START_TAG;  //assign token type 
				token.tokenString=temp; //assign name: read in chars and append to tokenString
				// exit(0); 
				tokenizedInputVector.push_back(token); //push entire token to vector 
				temp.clear(); 
				j++; 

			} 
			
		}//end of big ass if statement lmao
	//************************************************************************************************************************************//	 
	//by now, we should have determine all types of tags and names if we found any and should have added them appropriately to the vector //
	//************************************************************************************************************************************//	 
	
	//************************************************************//
	//2)next, test the content (everything that IS NOT a markup)  //
	//************************************************************//
	if(j<inputString.size()){
		while(inputString.at(j)!='<'&&inputString.at(j)!='>'){ //while we are not the text enclosed in the brackets < >
			temp += inputString.at(j); 
			j++; 
			} 
	}
	//temp should get updated here as content
	// cout << temp << "\n";  	  
	token.tokenType=CONTENT;  //assign token type 
	token.tokenString=temp; 
	tokenizedInputVector.push_back(token); //push entire token to vector
	temp.clear(); 
	
	// cout << inputString.at(i) << endl; 
	} //end of big ass for loop lmao 
	//************************************************************************************//
	//here we are done search through the length of the input string and are now ready to //
	//start adding the tag types and names to our element bag							  //
	//************************************************************************************//

	//removes the new line characters from tags: 
	if ( tokenizedInputVector.at(tokenizedInputVector.size()-1).tokenType == 4 ) { 
		//remove the token 
		tokenizedInputVector.pop_back(); //pop the new line character off 
	}

	//add tags to the element bag 
	for(int i=0; i<tokenizedInputVector.size(); i++){
		//if start, end, empty and declaration is not already in the bag 
		if(tokenizedInputVector.at(i).tokenType==1||tokenizedInputVector.at(i).tokenType==2||tokenizedInputVector.at(i).tokenType==3){
			if(elementNameBag->contains(tokenizedInputVector.at(i).tokenString)){
				elementNameBag->add(tokenizedInputVector.at(i).tokenString); //add token string to the bag if both of them are true 
				
			}
		}
	} 
	//cout<<"true"; 
	//return true for a successfull tokenizedInputString validation method:
	return true; 

	//return false;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	//remove whitespace from input 
	for(int i=0; i<input.size(); i++){
		if(input.at(i)==' '||input.at(i)=='\n'||input.at(i)=='\r'||input.at(i)=='\t'||input.at(i)=='\f'||input.at(i)=='\v'){
			input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end()); //link: https://www.techidelight.com/remove-whitespaces-string-cpp/
		}
	}
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{	//Use the stack variable parseStack along with tokenizedInputVector to check for
	//matching start and end tags while parsing
	//this is our second half of validating an XML file 

	//use the stack to make sure XML is balanced 

	//before we begin searching through the tokenizedinputstringvector, make sure we have proper XML syntax:
	//vector cannot begin with a end, empty or content tag
	if(tokenizedInputVector.at(0).tokenType==2||tokenizedInputVector.at(0).tokenType==3||tokenizedInputVector.at(0).tokenType==4){
		//vector cannot end with a start, empty or content tag
		if(tokenizedInputVector.back().tokenType==1||tokenizedInputVector.back().tokenType==3||tokenizedInputVector.back().tokenType==4){
			//vector cannot begin with an 'end' tag or end with a 'start' tag 
			if(tokenizedInputVector.at(0).tokenType==2&&tokenizedInputVector.back().tokenType==1){
				return false; //return false if any of the incorrect syntax is found with the tags 
			}
		}
	}
	//now we will search our tokenizedinputvector and push the appropriate tag names to the stack 
	//for loop where we search tokenizedinputvector 
	for(int i=0; i<tokenizedInputVector.size(); i++){
		//make comparisons for the tag types 
		if(tokenizedInputVector.at(i).tokenType==1){
			parseStack->push(tokenizedInputVector.at(i).tokenString); //add the string to the stack 
		}
		//after pushing, peek the top of the stack and compare the end tag to the start tag: 
		if(tokenizedInputVector.at(i).tokenType==2){
			//peek the top of the stack and see if it is equal to its corresponding start tag
			parseStack->peek();
			//if they don't match, return false 
			if(parseStack->peek()!=tokenizedInputVector.at(i).tokenString){
				return false; //the tags don't match, so we have an invalid XML 
			}
			else{ //if they match, pop it, and keep comparing
				elementNameBag->add(tokenizedInputVector.at(i).tokenString);
				parseStack->pop(); //pop that tag off of the stack to continue comparing
			}			
		}
		//if we find an empty tag, add it to the bag: 
		if(tokenizedInputVector.at(i).tokenType==3){
			elementNameBag->add(tokenizedInputVector.at(i).tokenString);
		}
		//continue searching, comparing and popping until stack is empty
	}
	//the stack must be empty to return true, if not return false 
	//test is stack is empty: 
	if(parseStack->isEmpty()==false){
		return false; //return false is the stack is NOT empty
	}
	return true; //otherwise, we return true if the stack is empty 
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	//clear the elementBag, stack variable, and the tokenizedVector: 
	elementNameBag->clear(); 
	parseStack->clear();
	tokenizedInputVector.clear(); 
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	//scan and parse methods must be true to have this method return true 
	if(elementNameBag->isEmpty()){
		return elementNameBag->contains(inputString); 
	}
	else{ 
		throw logic_error ("invalid XML"); 
	}
	//return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	int count = 0; 
	//search for the element name tag in the string and increase a count variable when found 
		for(int i=0; i<elementNameBag->size(); i++){
			if(elementNameBag->contains(inputString)){
			//return true if the element name tag is found in the string
				count++; 
			}
		}
	//return -1;
	return count; 
}