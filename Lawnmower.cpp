// Assignment 1: Alternating disks problem, lawnmower algorithm
// Doina Bein
// Given 2n alternating disks (dark, dark, light, light)
// the program reads the number of single color disks (light or dark),
// arranges the disks in the correct order and outputs the number of swaps
// INPUT: an even positive integer n and a list of 2n disks of alternating 
// colors dark-dark-light-light, starting with dark
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks 
// are dark, and an integer m representing the number of moves necessary
// to move the dark ones before the light ones

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
void print_disks(int n, char *disks)
{
	cout << "List of disks\n";
	for (int i = 0; i < 2*n; ++i)
	{
		if (disks[i] == 0)
		{
			cout << "D ";
		}
		else
		{
			cout << "L ";
		}
		
	}
	cout << endl;
}
// YOU NEED TO IMPLEMENT THIS FUNCTION
// function to print the list of disks, given the number of single color disks and the actual list                                                                                                                                                                                                                                                                                                     
// n represents the number of single color disks                                                                                                                                                         
// disks represents the list of disks (index 0 being the first disk) where                                                                                                                               
// 0 = a light color disks                                                                                                                                                                               
// 1 = a dark color disks     

int main() {
  int n, m, k, i;
  char *disks;
  // display the header                                                                                                                                                                                  
  cout << endl << "CPSC 335-x - Programming Assignment #1" << endl;
  cout << "The alternating disks problem: lawnmower algorithm" << endl;
  cout << "Enter the number of single color disks (light or dark)" << endl;
  // read the number of disks                                                                                                                                                                            
  cin >> n;
  // allocate space for the disks                                                                                                                                                                        
  disks = new char[2*n];
// set the initial configurations for the disks to alternate
  for( i=0; i < n/2; i++) {
    disks[4*i  ] = 0;
    disks[4*i+1] = 0;
    disks[4*i+2] = 1;
    disks[4*i+3] = 1;
  }
 
  // print the initial configuration of the list of disks                                                                                                                                                
  cout << "Initial configuration" << endl;
  print_disks(n,disks);
 // reset the number of moves to 0;
  m = 0;
  // loop to push light one before darks ones 
  
  for (k=0;  k < 2*n ; k++) 
  {
	  for (int j = 0; j < 2*n - 1; j++)
	  {
			if (disks[j] > disks[j+1])
			{
				
					disks[j] = 0;
					disks[j+1] = 1;
					m++;
				
			}
	 }
  
	  //Going right to left
	  for (int t = 2*n - 1; t > 0; t--)
	  {
			if (disks[t] < disks[t-1])
			{
					disks[t] = 1;
					disks[t-1] = 0;
					m++;
				
			}
	 }
  }

  // after shuffling them                                                                                                                                                                                
  cout << "After moving darker ones to the left" << endl;
  print_disks(n, disks);
  // print the total number of moves                                                                                                                                                                     
  cout << "Number of swaps is " << m << endl;
  // de-allocate the dynamic memory space                                                                                                                                                                
  delete [] disks;
  return EXIT_SUCCESS;
}

