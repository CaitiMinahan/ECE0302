#include <iostream>
#include "string"
#include "image.cpp"
#include "deque.hpp"

int main(int argc, char *argv[])
{
  //helper variables: 
  int rowEnter, colEnter, sourceNode; 

  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  //call the read from file function: 
  Image<Pixel>ip_image = readFromFile(argv[1]);

  //search for the maze entrance: 
  //loop through the height of the image (columns)
  //loop through the width of the image (rows)
  //see if we are truly at an entrance (where the source node will have a red colored pixel)
  //validty check to make sure that we are not at the end (make sure position is not found at a green pixel) therefore it can be either white, red or black
  //make sure we only have one entrance (so only one pixel)


  //an exit can be found at the edges of the maze (so either max width or max height of the image)

  //read in a PNG file, write to it, and compare the output to the solution PNG file

  //conduct a bread-first-search, when we've visited a white space, mark it as visited
  //keep track of the visited spaces in a deque (to mark our tracks)


  //mark the pixel green when we have reached our goal
  //return EXIT_SUCCESS and print solution Found to standard output

  //consider a pixel with coordinates (r,c):

  //consider a pixel with coordinates (r-1, c) for previousRow: 

  //consider a pixel with coordinates (r+1, c) for nextRow 

  //consider a pixel with coordinates (r, c-1) for previousColumn 

  //consider a pixel with coordinates (r, c+1) for nextColumn:



}
