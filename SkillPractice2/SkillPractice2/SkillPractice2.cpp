/******************************
   Solomon Pattee
   9/11/2019
   SkillPractice2.cpp
   Finding the median in a pointer array
********************************/

// Headers
#include <iostream>
#include <iomanip>

using namespace std;

// Function declarations
int getMedian(int*, int);
int* arrayAllocator(int);
void x();

int main()
{
	// Constants for the sizes 
	int odd[] = { 1, 2, 3, 4, 5, 6, 7 };

	int even[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	cout << "Odd set" << endl;
	// getting the median of the odd
	int theMedodd = getMedian(odd, 7);

	cout << "\nEven set" << endl;
	// and even
	int theMedeven = getMedian(even, 8);


	//	Make sure we place the end message on a new line
	cout << endl;

	//	The following is system dependent. It will only work on Windows
	system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	return 0;
}

// arrayAllocator function, takes an int for size, dynamically allocates
// an array of ints on the number passed in, returns a pointer to the 
// array

void x()
{
	cout << setprecision(2) << endl;
	//	Your code goes here
	int numElements;	// holdt he number of elements
	int* pointer = nullptr;	 // a pointer to the array, set to 0
	int i;
	
	// Enter in size of the array
	cout << "enter the size of the int array: ";
	cin >> numElements;

	// allocate the array
	pointer = arrayAllocator(numElements);

	// fill the array with values 
	for (i = 0; i < numElements; i++)
		* (pointer + i) = i;

	// display the values
	cout << "\n\nHere are the values in the array:\n";
	for (i = 0; i < numElements; i++)
		cout << "Element " << i << " has the value " << *(pointer + i) << endl;

	// deallocate the array
	delete[] pointer;
	pointer = nullptr;

}

int getMedian(int* array0, int size)
{
	// formatting

	cout << setprecision(2) << endl;

	// doubles for the output
	int* pointer = nullptr;
	int count = 0; // for the loop
	double median = 0;
	double median2 = 0;
	double median3 = 0;

	// allocation hold
	pointer = arrayAllocator(size);

	// counting 
	// fill the array with values 
	for (int i = 0; i < size; i++)
	{ 
		pointer[i];
		count += i;
	}

	//median equations
	median = pointer[count] / 2;
	median2 = (pointer[count] / 2) + 1;
	median3 = (median + median2) / 2;

	cout << " Here is the Median " << median << endl;

	return 0;
}

int* arrayAllocator(int num)
{
	int* arrPtr = nullptr;

	// allocate space for the array
	arrPtr = new int[num];

	// return the address of the allocated memory
	return arrPtr;
}