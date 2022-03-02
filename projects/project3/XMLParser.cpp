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
	int count; //keeps track of the number of characters inside a tag (text between < >)

	//first, let's search through the entire string and determine the tag type:
	for(int i=0; i<inputString.size(); i++){ 
		
		//test for declaration tag 
		if(inputString.at(i)=='<'&& inputString.at(i+1)=='?'){ //check for <? for the beginning of the tag 
			i+=2; //skip two more positions to get the first character after the question mark in <?
			//do not need to valid characters for a declaration tag 
			while(inputString.at(i)!='?'&&inputString.at(i+1)!='>'){ //now, i is at the first char after the '?' but make sure we aren't at the end of the tag
				if(count>5000){ return false; } //we have exceeded the allowable amount of text assumed to be contained before the end of the tag (before ?>)
			i++; //continue to search through the text within the tag 
			count++; //increase the number of characters allowed in the tag	
			}
			i+=2; //skip over two more positions to see if we have another potential tag (so, skip over ?> ending to find another possible start to another tag)
			
			//once we've determined this tag to be a declaration tag, update tokenStruct and push it to the tokenizedVector:
			token.tokenType=DECLARATION;  //assign token type 
			token.tokenString="DECLARATION"; //assign name: read in chars and append to tokenString
			tokenizedInputVector.push_back(token); //push entire token to vector 
		}
		//test for end tag 
		if(inputString.at(i)=='<'&&inputString.at(i+1)=='/'){ //test for </ at the beginning of the tag 
			i+=2; //skip two more positions to get the first character after the forward slash in </
			while(inputString.at(i)!='>'){ //i is now at the first character after </ but make sure we are not at the end of the tag
				if(count>5000){ return false; } //we have exceeded the allowable amount of text assumed to be contained before the end of the tag (before >)
				//input validation to check for illegal characters:
				if(inputString.at(i)=='\''||inputString.at(i)=='\\'||inputString.at(i)=='!'||inputString.at(i)=='"'||inputString.at(i)=='#'||inputString.at(i)=='$'||inputString.at(i)=='%'||inputString.at(i)=='&'||inputString.at(i)=='&'||inputString.at(i)=='('||inputString.at(i)==')'||inputString.at(i)=='*'||inputString.at(i)=='+'||inputString.at(i)==','||inputString.at(i)=='/'||inputString.at(i)==';'||inputString.at(i)=='<'||inputString.at(i)=='='||inputString.at(i)=='>'||inputString.at(i)=='?'||inputString.at(i)=='@'||inputString.at(i)=='['||inputString.at(i)=='^'||inputString.at(i)=='`'||inputString.at(i)=='{'||inputString.at(i)=='|'||inputString.at(i)=='}'||inputString.at(i)=='~'||inputString.at(i)==' '){
					return false; 
					//tag name cannot begin with any of these characters or numeric digits (text beginning after </ )
					if(inputString.at(i+2)=='-'||inputString.at(i+2)==','||inputString.at(i+2)=='.'||inputString.at(i+2)=='0'||inputString.at(i+2)=='1'||inputString.at(i+2)=='2'||inputString.at(i+2)=='3'||inputString.at(i+2)=='4'||inputString.at(i+2)=='5'||inputString.at(i+2)=='6'||inputString.at(i+2)=='7'||inputString.at(i+2)=='8'||inputString.at(i+2)=='9'){
						return false;
					}
				}
			i++; //continue to search through the text within the tag
			count++; //increase the number of characters allowed in the tag	
			}
			i+=1; //skip over one more position to see if we have another potential tag (so, skip over > ending to find another possible start to another tag)
		
			//once we've determined this tag to be a declaration tag, update tokenStruct and push it to the tokenizedVector:
			token.tokenType=END_TAG;  //assign token type 
			token.tokenString="END_TAG"; //assign name: read in chars and append to tokenString
			tokenizedInputVector.push_back(token); //push entire token to vector 		
		}
		//test for empty tag 
		if(inputString.at(i)=='<'){ //test for < at the beginning of the tag 
			i+=1; //skip one more position to get the first immediate character after the open bracket <
			//For empty-tags, the tag name is the text immediately after the ‘<’ up to the first white space or the ending angle bracket “/>”
			while((inputString.at(i)!='/'&&inputString.at(i+1)!='>')||inputString.at(i)!=' '){ //now, i is at the first character after < but make sure we are not at the end of the tag 
				if(count>5000){ return false; } //we have exceeded the alloweable amount of text assumed to be contained before the end of the tag (before />)
				//input validation to check for illegal characters:
				if(inputString.at(i)=='\''||inputString.at(i)=='\\'||inputString.at(i)=='!'||inputString.at(i)=='"'||inputString.at(i)=='#'||inputString.at(i)=='$'||inputString.at(i)=='%'||inputString.at(i)=='&'||inputString.at(i)=='&'||inputString.at(i)=='('||inputString.at(i)==')'||inputString.at(i)=='*'||inputString.at(i)=='+'||inputString.at(i)==','||inputString.at(i)=='/'||inputString.at(i)==';'||inputString.at(i)=='<'||inputString.at(i)=='='||inputString.at(i)=='>'||inputString.at(i)=='?'||inputString.at(i)=='@'||inputString.at(i)=='['||inputString.at(i)=='^'||inputString.at(i)=='`'||inputString.at(i)=='{'||inputString.at(i)=='|'||inputString.at(i)=='}'||inputString.at(i)=='~'||inputString.at(i)==' '){
					return false; 
					//tag name cannot begin with any of these characters or numeric digits (text beginning after < )
					if(inputString.at(i)+2=='-'||inputString.at(i)+2==','||inputString.at(i)+2=='.'||inputString.at(i)+2=='0'||inputString.at(i)+2=='1'||inputString.at(i)+2=='2'||inputString.at(i)+2=='3'){
						return false; 
					}
				}
			i++; //continue to search through the text within the tag 
			count++; //increase the number of characters allowed in the tag 
			}
			//if we are caught at a whitespace, we must find the ending bracket: 
			if(inputString.at(i)==' '||inputString.at(i)=='\n'||inputString.at(i)=='\r'||inputString.at(i)=='\t'){ //i is now at the first whitespace found 
				if(count>5000){ return false; } //make sure we are not outside the text before the end >
				while(inputString.at(i+1)!='>'){ //while we still have not reached the end bracket >
					//then keep searching
					i++;
					count++; 
				}
				//once the while look is broken, we have found the ending bracket > 
			//i is now at the end bracket, so we need to skip over one position to get past > 
			i+=1; //skip over one space 
			}
			//however, if we are caught at a />, we need to skip over two positions to get to the end of the tag: 
			if(inputString.at(i)=='/'&&inputString.at(i+1)=='>'){
			i+=2; //skip over two positions if /> is at the end
			}

			//once we've determined this tag to be a declaration tag, update tokenStruct and push it to the tokenizedVector:
			token.tokenType=EMPTY_TAG;  //assign token type 
			token.tokenString="EMPTY_TAG"; //assign name: read in chars and append to tokenString
			tokenizedInputVector.push_back(token); //push entire token to vector 		
		}
		//Otherwise, if you haven't found a declaration, end or empty tag, 
		//We must've found ourselves a start tag:
		if(inputString.at(i)=='<'){
			i+=1; //skip over one position to get the first character immediately after the open bracket <
			while(inputString.at(i)!=' '||inputString.at(i)!='>'){ //now, i is at the first character after < but make sure we are not at the end of the tag 
				if(count>5000){ return false; } //we have exceeded the alloweable amount of text assumed to be contained before the end of the tag (before />)
				//input validation to check for illegal characters:
				if(inputString.at(i)=='\''||inputString.at(i)=='\\'||inputString.at(i)=='!'||inputString.at(i)=='"'||inputString.at(i)=='#'||inputString.at(i)=='$'||inputString.at(i)=='%'||inputString.at(i)=='&'||inputString.at(i)=='&'||inputString.at(i)=='('||inputString.at(i)==')'||inputString.at(i)=='*'||inputString.at(i)=='+'||inputString.at(i)==','||inputString.at(i)=='/'||inputString.at(i)==';'||inputString.at(i)=='<'||inputString.at(i)=='='||inputString.at(i)=='>'||inputString.at(i)=='?'||inputString.at(i)=='@'||inputString.at(i)=='['||inputString.at(i)=='^'||inputString.at(i)=='`'||inputString.at(i)=='{'||inputString.at(i)=='|'||inputString.at(i)=='}'||inputString.at(i)=='~'||inputString.at(i)==' '){
					return false; 
					//tag name cannot begin with any of these characters or numeric digits (text beginning after < )
					if(inputString.at(i)+2=='-'||inputString.at(i)+2==','||inputString.at(i)+2=='.'||inputString.at(i)+2=='0'||inputString.at(i)+2=='1'||inputString.at(i)+2=='2'||inputString.at(i)+2=='3'){
						return false; 
					}
				}
			i++; //continue to search through the text within the tag 
			count++; //increase the number of characters allowed in the tag 
			}
			//if we are caught at a whitespace, we must find the ending bracket: 
			if(inputString.at(i)==' '||inputString.at(i)=='\n'||inputString.at(i)=='\r'||inputString.at(i)=='\t'){ //i is now at the first whitespace found 
				if(count>5000){ return false; } //make sure we are not outside the text before the end >
				while(inputString.at(i+1)!='>'){ //while we still have not reached the end bracket >
					//then keep searching
					i++;
					count++; 
				}
				//once the while look is broken, we have found the ending bracket > 
			//i is now at the end bracket, so we need to skip over one position to get past > 
			i+=1; //skip over one space 
			}
			//however, if we are caught at a />, we need to skip over two positions to get to the end of the tag: 
			if(inputString.at(i)=='>'){
			i+=2; //skip over two positions if /> is at the end
			}

			//once we've determined this tag to be a declaration tag, update tokenStruct and push it to the tokenizedVector:
			token.tokenType=START_TAG;  //assign token type 
			token.tokenString="START_TAG"; //assign name: read in chars and append to tokenString
			tokenizedInputVector.push_back(token); //push entire token to vector 		
		}
	//2) test the content (everything that IS NOT a matkup)
	while(inputString.at(i)!='<'&&inputString.at(i)!='>'){ //while we are not the text enclosed in the brackets < >
		token.tokenType=CONTENT;  //assign token type 
		token.tokenString="CONTENT"; //assign name: read in chars and append to tokenString
		tokenizedInputVector.push_back(token); //push entire token to vector 		
		}		
	} //end of big ass for loop lmao 

	for(int i=0; i<tokenizedInputVector.size(); i++){
		//if start, end, empty AND is not already in the bag 
		if(tokenizedInputVector.at(i).tokenType==1||tokenizedInputVector.at(i).tokenType==2||tokenizedInputVector.at(i).tokenType==3){
			if(elementNameBag->contains(tokenizedInputVector.at(i).tokenString)){
				elementNameBag->add(tokenizedInputVector.at(i).tokenString); //add token string to the bag if both of them are true 
			}
		}
	}

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

