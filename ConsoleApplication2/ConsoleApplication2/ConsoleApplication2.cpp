// Chapter 9, Programming Challenge 8: Mode Function
#include <iostream>
using namespace std;

// Function prototypes
int getMode(int*, int);
int* makeArray(int);

int main()
{
	// Constant for the array size
	const int SIZE = 11;

	// An array of test values
	int test[SIZE] = { 1, 2, 3, 3, 3, 2, 2, 1, 3, 4, 5 };

	// A variable to hold the mode of the test values
	int mode;

	// Get the mode of the test values.
	mode = getMode(test, SIZE);

	// Display the mode, if any.
	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: "
		<< mode << endl;

	return 0;
}

//**********************************************************
// Function getMode                                        *
// This function returns the mode of the array pointed to  *
// by array. If there is no mode, the function returns -1. *
//**********************************************************
int getMode(int* array, int size)
{
	// A pointer to reference a dynamically allocated array
	// to hold the frequencies of each value.
	int* frequencies = nullptr;
	int mode = -1;		// The mode, initialized to -1
	int highest = 0;	// The value with highest frequency
	int element = 0;	// To hold an element subscript
	int count = 0;		// Loop counter

	// Dynamically allocate an array to hold
	// the frequencies of each element in the
	// array. When this function ends, frequencies[0]
	// will hold the frequency of the value in
	// array[0], and so forth.
	frequencies = makeArray(size);

	// Store 0 in all the elements of frequencies.
	for (count = 0; count < size; count++)
		frequencies[count] = 0;

	// Find the frequency of each element in array.
	for (int count1 = 0; count1 < size; count1++)
	{
		// The inner loop compares the array element at
		// *(array + count1) with every element in the
		// array. When it finds a matching element, it
		// increments the element's frequency.
		for (int count2 = 0; count2 < size; count2++)
		{
			if (*(array + count2) == *(array + count1))
				(*(frequencies + count1))++;
		}
	}

	// Find the element with the highest frequency.
	// Start by assuming the first element has the
	// highest frequency.
	highest = *frequencies;
	element = 0;

	// Step through the frequencies array and find
	// the highest value.
	for (count = 1; count < size; count++)
	{
		if (*(frequencies + count) > highest)
		{
			highest = *(frequencies + count);
			element = count;
		}
	}
	delete[] frequencies;
	frequencies = nullptr;

	// If there is no mode (no element has a frequency 
	// greater than 1), then return -1. Otherwise return
	// the element with the greatest frequency.
	if (highest > 1)
	{
		mode = *(array + element);
	}

	return mode;
}

//********************************************************
// Function makeArray                                    *
// This function dynamically allocates an array of ints  *
// and returns a pointer to it. The size parameter is    *
// the number of elements to allocate.                   *
//********************************************************
int* makeArray(int size)
{
	int* ptr = new int[size];

	return ptr;
}