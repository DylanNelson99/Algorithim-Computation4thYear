#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

void merge(int arraySortedInTwoHalves[], int startIndex, int LengthTosort);

void mergeSort(int arrayToSort[], int startIndex, int LengthTosort);

int main()
{
	int array1[10] = { 9, 1, 0, 3, 2 , 7, 8, 5, 6, 4 };
	int *ptr = array1;
		
	mergeSort(array1, 0, 9);

	for (int i = 0; i <= 9; i++)
	{
		cout << array1[i] << endl;
	}
	
	system("PAUSE");

    return 0;
}

void merge(int arraySortedInTwoHalves[], int startIndex, int LengthTosort)
{
	int mid = ((startIndex + LengthTosort) / 2);
	int left = mid - startIndex + 1;
	int right = LengthTosort - mid;

	int leftArray[10]; 
	int rightArray[10];


	for (int i = 0; i < left; i++)
		leftArray[i] = arraySortedInTwoHalves[startIndex + i];
	for (int j = 0; j < right; j++)
		rightArray[j] = arraySortedInTwoHalves[mid + 1 + j];

	
	int i = 0; 
	int j = 0; 
	int k = startIndex; 
	while (i < left && j < right)
	{
		if (leftArray[i] <= rightArray[j])
		{
			arraySortedInTwoHalves[k] = leftArray[i];
			i++;
		}
		else
		{
			arraySortedInTwoHalves[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < left)
	{
		arraySortedInTwoHalves[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < right)
	{
		arraySortedInTwoHalves[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergeSort(int arrayToSort[], int startIndex, int LengthTosort)
{
	if (startIndex < LengthTosort)
	{
		int mid = (startIndex + (LengthTosort - startIndex) / 2);

		mergeSort(arrayToSort, startIndex, mid);
		mergeSort(arrayToSort, mid + 1, LengthTosort);

		merge(arrayToSort, startIndex, LengthTosort);
	}
	else
	{
		return;
	}
}