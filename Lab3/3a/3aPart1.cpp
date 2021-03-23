#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

int quickSortDivide(int* theArray, int size);

void quickSort(int* theArray,int size );

void swap1(int &num1, int &num2);

int main()
{
	int nums[10] = { 5,2,0,4,10,10,3,9,8,1 };

	for (int i = 0; i <= 9; i++)
	{
		cout << nums[i] << endl;
	}

	cout << endl;

	quickSort(nums, 0, 9); 

	for (int i = 0; i <= 9; i++)
	{
		cout << nums[i] << endl;
	}

	system("PAUSE");

	return 0;
}

void swap1(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int quickSortDivide(int* theArray,int size)
{	

//?????

	return size;
}

void quickSort(int* theArray, int size)
{
	//???

	if (theArray < size)
	{
		int size = quickSortDivide(theArray, size);
		quickSort(theArray, size- 1); //???
		quickSort(theArray, size + 1);

	}

}