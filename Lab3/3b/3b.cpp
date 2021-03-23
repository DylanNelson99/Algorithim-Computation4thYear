//used link in labsheet for help - https://www.techiedelight.com/hybrid-quicksort/
//Dylan Nelson - X00144862

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>   
using namespace std;

/** Swap function to swap two elements **/
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void quickSort(int* theArray, int size)
{
	if (size > 0)
	{
		/** Pivot index split  **/
		int pi = quickSortDivide(theArray, size);

		/** Sort the left side of the pivot **/
		quickSort(theArray, pi - 1);

		/** Sort the ride side of the pivot **/
		quickSort(&theArray[pi], size - pi);
	}
}

int quickSortDivide(int *theArray, int size)
{
	/** Index of smaller element **/
	int i = - 1; 
	/** Initializing the pivot **/
	int p = theArray[size - 1]; 

	for (int j = 0; j <= size - 1; j++)
	{
		/** If the current element is smaller than the pivot **/
		if (theArray[j] < p)
		{
			/** Increment index of smaller element **/
			i++; 
			swap(theArray[i], theArray[j]);
		}
	}
	swap(theArray[i + 1], theArray[size - 1]);

	return (i + 1);
}


/** I'm getting a problem with the stack overflow section but my code is below: **/
int main()
{

	int* randArray = new int[200000];
	clock_t  clock1, clock2;
	int n = 200000;

	/** Filling the array with random numbers **/
	for (int i = 0; i < n; i++)
		randArray[i] = rand() % 200000;

	/** Starting time **/
	clock1 = clock();
	auto t_start = chrono::high_resolution_clock::now();

	quickSort(randArray, n);

	/** End time **/
	clock2 = clock();
	auto t_end = chrono::high_resolution_clock::now();

	cout << "Quick sort CPU time: " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Quick sort Wall time: " << chrono::duration<double, std::milli>(t_end - t_start).count() << " seconds"<< endl;
	delete[] randArray;

	int* sortedArray = new int[100000];
	int n_sorted = 100000;

	/** Fill in array **/
	for (int i = 0; i < n_sorted; i++)
		sortedArray[i] = (i + 1);
	
	/** Starting time **/
	clock1 = clock();
	quickSort(sortedArray, n_sorted);

	/** End time **/
	clock2 = clock();

	cout << "Quick sort CPU time for sorted array: " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Quick sort Wall time for sorted array:: " << chrono::duration<double, std::milli>(t_end - t_start).count() << " seconds" << endl;
	delete[] sortedArray;

	return 0;
}
