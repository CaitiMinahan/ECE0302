#include <iostream>
#include "string"
#include "image.cpp"
#include "deque.hpp"

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  //scan the image recursively until we have reached an exit 
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
