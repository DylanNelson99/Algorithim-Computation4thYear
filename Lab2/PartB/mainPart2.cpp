#include <iostream>
#include <vector>
//Dylan Nelson - X00144862
using namespace std;

// Referenced from -> https://www.geeksforgeeks.org/binary-search/
template <typename T>
int binarySearch(vector<T> vect, int i, int sizeOfVector, T number) {
    if (sizeOfVector >= i) {

        // Get the middle element
        int mid = i + (sizeOfVector - i) / 2;

        if (vect[mid] == number)
            return mid;

        if (vect[mid] > number)
            return binarySearch(vect, i, mid - 1, number);

        else
            return binarySearch(vect, mid + 1, sizeOfVector, number);
    }

    return -1;
}

int main() {

    /vector<int> vectInts = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int value = 2;/

    vector<double> vect = { 1.4, 2.5, 3.6, 4.6, 5.5, 6.6, 7.7, 8.8, 9.9, 10.9 };
    double value = 2.5;

    int index = binarySearch(vect, 0, vect.size() - 1, value);

    if (index == -1)
        cout << "Element not found within the vector  " << endl;
    else
        cout << "Element is found at index [" << index << "]" << endl;



    return 0;
}