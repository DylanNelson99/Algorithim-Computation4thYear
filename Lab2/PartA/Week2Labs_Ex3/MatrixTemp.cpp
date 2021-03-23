//Dylan Nelson - X00144862 

#include <vector>
#include <iostream>
#include "MatrixTemp.h"
using namespace std;

template < class T>
MatrixTemp<T>::MatrixTemp() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = j;
		}
	}
};

template < class T >
void MatrixTemp<T>::printMatrix() {
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << "  " << this->matrix[row][col];
		}
		cout << endl;
	}
}

template < class T >
void MatrixTemp<T>::setMatrix(vector<vector<T>>& vect) {
	bool sameSize = false;

	if ((sizeof(matrix) / sizeof(matrix[0]) == vect[0].size()) &&
		(sizeof(matrix[0]) / sizeof(T)) == vect.size())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = vect = [i][j];
			}
		}
		MatrixTemp::printMatrix();
	}
	else
	{
		cout << "Vector is not the same size as the matrix! " << endl;
	}
}