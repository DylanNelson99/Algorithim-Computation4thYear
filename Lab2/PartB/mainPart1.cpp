
//Dylan Nelson - X00144862
#include <iostream>
#include <vector>
using namespace std;

// Referenced from -> https://www.geeksforgeeks.org/binary-search/

//int binarySearch(vector<int> vect, int i, int sizeOfVector, int number) {
//	
//	for (i; i <= sizeOfVector;)
//	{
//		// Retrieve the middle element of the array
//		int m = i + (sizeOfVector - i) / 2;
//
//		// Check if the middle element is equal to the number
//		if (vect[m] == number) {
//			return m;
//		}
//
//		// If the middle element is less than the number
//		// then we know that the number is on the higher half of the vector
//		else if (vect[m] < number) {
//			i = m + 1;
//		}
//
//		// If the middle element is greater than the number
//		// then we know that the number is on the lower half of the vector
//		else if (vect[m] > number) {
//			sizeOfVector = m - 1;
//		}
//	}
//	
//	// Return -1 if no number has been found
//	return -1;
//}
//int main()
//{
//	vector<int> vect = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int value;
//	cout << "Enter in a value between 1 - 10: ";
//	cin >> value;
//
//	int index = binarySearch(vect, 0, vect.size() - 1, value);
//
//	if (index == -1)
//		cout << "Element not found within the vector :( " << endl;
//	else
//		cout << "Element is found at index [" << index << "]" << endl;
//	
//	return 0;
//}