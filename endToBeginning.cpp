// Assignment 2: Longest non-decreasing subsequence problem, end-to-beginning algorithm        

/****************************************                                                           
* Name: Micah Geertson & Justin Stewart *
* CPSC 335-01 13115                     *
* Date: 03/20/2016                      *
*****************************************/


// Given a sequence of elements the program finds a subsequence of it in which the subsequence's
// elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible.                     	
// The program reads the number of elements in the sequence, then the elements and outputs the sorted
// sequence and the running time.          
// INPUT: a positive integer n and a list of n elements                     	
// OUTPUT: a longest non-decreasing subsequence of the initial sequence   

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

void print_sequence(int, float*);
// function to print a sequence, given the number of elements and           	
// the actual sequence stored as an array    


int main() {

  int n, i, j, max, index;
  float *A, *R;
  int *H;


  // display the header                                                        
  cout << endl << "CPSC 335-x - Programming Assignment #2" << endl;
  cout << "Longest non-decreasing subsequence problem, end-to-beginning algorithm" << endl;
  cout << "Enter the number of elements in the sequence" << endl;
  
  // read the number of elements                                               
  cin >> n;


  // allocate space for the input sequence and array H                          
  A = new float[n];
  H = new int[n];


  // read the sequence                                                         
  cout << "Enter the elements in the sequence" << endl;

  for( i=0; i < n; i++)
  {
	cin >> A[i];
  }

  // print the sequence                                                        
  cout << "Input sequence" << endl;
  print_sequence(n,A);

  // Start the chronograph to time the execution of the algorithm           	
  auto start = chrono::high_resolution_clock::now();
  
  // loop to populate the array H with 0 values                             	
  for(i=0; i< n; i++)
  {
	H[i] = 0;
  }


  // loop to calculate the values of array H                                	
  for ( i = n-2;  i>= 0; i--) 
  {
	for ( j = i+1; j < n ; j++)
	{
	// WRITE THE CODE THAT IS AN IF CONDITION THAT DECIDES WHETHER
 	// TO CHANGE OR NOT THE VALUE OF H[i]
		if(A[i] <= A[j])
		{
			if(H[i] <= H[j])
				H[i] = H[j] + 1;
		}
	}
  }

  // calculate in max the length of the longest subsequence by adding 1     	
  // to the maximum value in H	
  max = H[0];

  for( i=1; i< n; i++)
	if (max < H[i])
  	max = H[i];

  max ++;

  // allocate space for the subsequence R                                   	
  R = new float[max];

  // add elements to R by whose H's values are in decreasing order, starting	
  // with max-1                                                                
  // store in index the H values sought  

  index = max - 1;

  // store in j the index of the element appended to R                      	
  j = 0;

  for(i=0; i< n; i++)
  {
	if (H[i] == index) 
	{
  	// WRITE THE BLOCK OF STATEMENTS TO ADD A[i] TO THE R SEQUENCE BY
  	// STORYING IT INTO R[j], DECREMENTING index AND INCREMENTING j
		R[j] = A[i];
		index--;
		j++;
	}
  }
  
  // End the chronograph to time the loop                                   	
  auto end = chrono::high_resolution_clock::now();
  
  // write the output                                                      
  cout << "The longest non-decreasing subsequence has length " << endl;
  cout << max << endl;
  cout << "The longest non-decreasing subsequence is" << endl;
  print_sequence(max, R);


  // print the elapsed time in seconds and fractions of seconds             	
  int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
  double seconds = microseconds / 1E6;
  cout << "elapsed time: " << seconds << " seconds" << endl;
  
  // de-allocate the dynamic memory space                                   	
  delete [] A;
  delete [] H;
  delete [] R;
  return EXIT_SUCCESS;
}

void print_sequence(int n, float *seq)
{
// function to print a sequence, given the number of elements and           	
// the actual sequence stored as an array                                   	
// n represents the number of elements in the sequence                      	
// seq represents the actual sequence                                       	
// WRITE THE CODE TO PRINT THE ELEMENTS OF A SEQUENCE seq WITH n ELEMENTS

	for (int i = 0; i < n; i++)
	{
		cout << seq[i] << " ";
	}
	cout << endl;
}

