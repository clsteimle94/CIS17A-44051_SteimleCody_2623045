int binarySearch(const int array[], int numElems, int value)
{
	int first = 0, // First array element
		last = numElems − 1, // Last array element
		middle, // Midpoint of search
		position = −1; // Position of search value
	bool found = false; // Flag
	while (!found && first <= last)
	{
	middle = (first + last) / 2; // Calculate midpoint
	if (array[middle] == value) // If value is found at mid
	{
		found = true;
		position = middle;
	}
	else if (array[middle] > value) // If value is in lower half
		last = middle − 1;
	else
		first = middle + 1; // If value is in upper half
	}
	return position;
} 


#include <iostream>
#include <string>
using namespace std;
int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
							   "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
							   "Taylor, Terri", "Johnson, Jill",
							   "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
							   "James, Jean", "Weaver, Jim", "Pore, Bob",
							   "Rutherford, Greg", "Javens, Renee",
							   "Harrison, Rose", "Setzer, Cathy",
							   "Pike, Gordon", "Holland, Beth" };
 // Insert your code to complete this program
	return 0;
 }