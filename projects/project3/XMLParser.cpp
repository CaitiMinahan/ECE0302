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

	//store both of these in tokenizeInputVector 
	TokenStruct token; 	//store token type 
	std::string tokenName; 	//store string of token

	//tokenizeInputString() should TEST FOR VALID TAGS, including nesting, but should not test for matching start and end tags
	//so, we have to do two things here: 
	//1) test valid markup 
	//2) test valid content 

	//Use elementNameBag to store element names

	//test all markup

	//validity check
	//start from the beginning of the input string
	//cannot have nested <>

	//1) first, test the markup (anything enclosed in the brackets < >)
	//determine tag type: START_TAG, END_TAG, EMPTY_TAG, CONTENT, and DECLARATION
	//include conditions for the specific markup sections (tags)
		//condition for end tag
		//condition for start tag 
		//condition for declaration tag 
		//condition for empty tag 
		//conditions for content 
	//once we've determined what type of tag we have, save it to your variables
	//save the token name and token type to a TokenStruct object 	
		//add conditions where if we found a certain type of a tag in the tests above, update tokenStruct here

	//now that we have determined the tag name and type, make sure it matches the proper syntax 
	//and does not have any weird characters that aren't allowed 
		//add conditions here for what is and isn't allowed for each tag 

	//tokenizedInputvector gets the tag pushed to the stack 


	//2) test the content (everything that IS NOT a matkup)

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
{	//Use the stack variable parseStack along with tokenizedInputVector to check for
	//matching start and end tags while parsing
	//this is our second half of validating an XML file 

	
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

