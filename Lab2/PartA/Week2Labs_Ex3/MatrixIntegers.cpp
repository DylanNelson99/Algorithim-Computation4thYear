//Dylan Nelson - X00144862 

#include <iostream>
#include "MatrixIntegers.h"
#include <vector>
using namespace std;

MatrixIntegers::MatrixIntegers()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void MatrixIntegers::printMatrix() {
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << "  " << matrix[row][col];
		}
		cout << endl;
	}
}

void MatrixIntegers::setMatrix(vector<vector<int>>& vect) {
	bool sameSize = false;
	if ((sizeof(matrix) / sizeof(matrix[0]) == vect[0].size()) &&
		(sizeof(matrix[0]) / sizeof(int)) == vect.size()) 
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = vect[i][j];
			}
		}
		MatrixIntegers::printMatrix();
	}
	else 
	{
		cout << "Vector is not the same size as the matrix! " << endl;
	}
	
}