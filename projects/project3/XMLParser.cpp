// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

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

	//test all markup (tokens)

	//validity check
	//start from the beginning of the input string
	//cannot have nested <>

	//first, test the markup 
	//determine tag type: START_TAG, END_TAG, EMPTY_TAG, CONTENT, and DECLARATION
	//include conditions for the specific markup sections (tags)
		//condition for end tag
		//condition for start tag 
		//condition for declaration tag 
		//condition for empty tag 
		//conditions for content 
	//save the token name and token type to a TokenStruct (helpful for tokenizeInputvector)	
	//make sure token names follow the correct format and don't have any weird characters

	//test the content (stuff between brackets < >) -- content is everything that IS NOT a matkup

	//return true if tokenization was successful 

	return false;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}

