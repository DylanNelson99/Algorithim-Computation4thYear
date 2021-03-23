#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <algorithm>   
using namespace std;


int binarySearchRecursion(vector<int> vect, int i, int sizeOfVector, int number) {
	if (sizeOfVector >= i) {

		// Get the middle element
		int mid = i + (sizeOfVector - i) / 2;

		if (vect[mid] == number)
			return mid;

		if (vect[mid] > number)
			return binarySearchRecursion(vect, i, mid - 1, number);

		else
			return binarySearchRecursion(vect, mid + 1, sizeOfVector, number);
	}

	return -1;
}
//
//int binarySearch(vector<int> vect, int i, int sizeOfVector, int number) {
//	if (sizeOfVector >= i) {
//
//		// Get the middle element
//		int mid = i + (sizeOfVector - i) / 2;
//
//		if (vect[mid] == number)
//			return mid;
//
//		if (vect[mid] > number)
//			return binarySearchTemplate(vect, i, mid - 1, number);
//
//		else
//			return binarySearchTemplate(vect, mid + 1, sizeOfVector, number);
//	}
//
//	return -1;
//}

int main() {

	vector<int> vectInts(100000);

	cout << vectInts.size() << endl;
	for (int i = 0; i < vectInts.size(); i++)
	{
		vectInts[i] = (rand() % 100000);
	}

	sort(vectInts.begin(), vectInts.end());

	int value = vectInts[(rand() % 100000)];

	int index = binarySearchRecursion(vectInts, 0, vectInts.size() - 1, value);

	if (index == -1)
		cout << "Element not found within the vector :( " << endl;
	else
		cout << "Element is found at index [" << index << "]" << endl;

	return 0;
}