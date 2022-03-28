#include <iostream>
#include "string"
#include "image.cpp"
#include "deque.hpp"

  //declare a struct for current position in the maze:
  struct currentPos{
    int x; 
    int y; 
  };
  //declare a struct for the node's position and its distance from the entrance 
  struct curNode{
    currentPos node; 
    int distance; 
  };

int main(int argc, char *argv[])
{
  //helper variables: 
  int row, col, pos=0; 

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
  for(int i=0; i<ip_image.height(); i++){
    //loop through the width of the image (rows)
    for(int j=0; j<ip_image.width(); j++){
      //see if we are truly at an entrance (where the source node will have a red colored pixel)
      if(ip_image(i,j)==RED){
        col = i; 
        row = j; 
        pos++; //now we have one red pixel (denoted as the entrance)
      }
      //validty check to make sure that we are not at the end (make sure position is not found at a green pixel) therefore it can be either white, red or black
      if(ip_image(i,j)!=WHITE &&ip_image(i,j)!=RED &&ip_image(i,j)!=BLACK){
        return EXIT_FAILURE; 
      }
      //make sure we only have one entrance (so only one red pixel)
      if(pos>1){
        return EXIT_FAILURE; //remember pos represents the node at the entrance, therefor the red pixel 
      }
    }
  }

  //conduct a bread-first-search, returns a solution or failure
  bool BFS[ip_image.width()][ip_image.height()]; //searches the entire image (all the rows and cols)
  memset(BFS, false, sizeof BFS); //memset copies a single character for a specified number of times to an object (www.geeksforgeeks.org)

  //visited the source
  BFS[row][col] = true;

  //frontier-->our deque with the states
  Deque<curNode>D; 

  //initialize the states of the problem (states denoted by s):
  currentPos s; //instantiate the state, s
  s.x = row; 
  s.y = col; 
  curNode src = {s, 0}; //initial start-->the starting position
  //add the current state to the deque
  D.pushBack(src); 

  //now start the BFS from the starting position:
  while(!D.isEmpty()){
    curNode current = D.front(); //the current position accesses the front item from the deque (most recent addition)
    currentPos node = current.node; 

    //condition for when we have reached our goal state:
    //the order the actions must be considered in the breadth-frist search: (r,c), (r-1,c), (r+1,c), (r, c-1), (r, c+1)

    //search for (r,c)
    if(node.x==0 || node.y == 0 || node.x==ip_image.width()-1 || node.y == ip_image.height()-1){
      //then we are done path finding and can turn the pixel green 
      ip_image(node.y, node.x) = GREEN; 
      //write to the output image: 
      writeToFile(ip_image, output_file); 
      //print solution message to standard output: 
      std::cout << "Solution Found" << std::endl; 
      //return exit success:s
      return EXIT_SUCCESS; 
    }
    //pop the current pos and keep searching: 
    D.popFront(); 

    //search the next column and see if there's a wall and if we have already visited that position before:
    //search for (r, c+1)
    if(ip_image(node.y+1, node.x)!= BLACK && !BFS[node.x][node.y+1]){
      //mark that we have visited this position
      BFS[node.x][node.y+1] = true; 
      //create new node to hold current position: 
      currentPos newNode; 
      newNode.x = node.x; 
      newNode.y = node.y+1; 
      //add the visited node
      curNode newCurrent = {newNode, newCurrent.distance++};
      //add the visited position to the deque:
      D.pushBack(newCurrent); 
    }

    //search the previous column and see if there's a wall and if we have already visited that position before: 
    if(ip_image(node.y-1, node.x)!= BLACK && !BFS[node.x][node.y-1]){
      //mark that we have visited this position
      BFS[node.x][node.y-1] = true; 
      //create new node to hold current position: 
      currentPos newNode; 
      newNode.x = node.x; 
      newNode.y = node.y-1; 
      //add the visited node
      curNode newCurrent = {newNode, newCurrent.distance++};
      //add the visited position to the deque:
      D.pushBack(newCurrent); 
    }
    
    //search for the previous row and see if there's a wall and if we have already visited that position before: 
    //search for (r-1, c)
    if(ip_image(node.y, node.x-1)!=BLACK && !BFS[node.x-1][node.y]){
      //mark that we have visited this position 
      BFS[node.x-1][node.y] = true; 
      //create a new node to hold current position:
      currentPos newNode;
      newNode.x = node.x-1; 
      newNode.y = node.y; 
      //add the visited node
      curNode newCurrent = {newNode, newCurrent.distance++};
      //add the visited position to the deque:
      D.pushBack(newCurrent); 
    }

    //search the next row and see if there's a wall and if we have already visited that position before: 
    //search for (r+1,c)
    if(ip_image(node.y, node.x+1)!=BLACK && !BFS[node.x+1][node.y]){
      //mark that we have visited this position 
      BFS[node.x+1][node.y] = true; 
      //create a new node to hold current position:
      currentPos newNode; 
      newNode.x = node.x+1; 
      newNode.y = node.y; 
      //add the visited node
      curNode newCurrent = {newNode, newCurrent.distance++};
      //add the visited position to the deque:
      D.pushBack(newCurrent); 
    }
  }
  //if we've skipped all the above conditions, we have not found our soultion:
  std::cout << "No Solution Found" << std::endl; 
  return EXIT_FAILURE; 
  
}
