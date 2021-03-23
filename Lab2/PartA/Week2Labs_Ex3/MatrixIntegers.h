//Dylan Nelson - X00144862 

#pragma once
#include <vector>
using namespace std;

class MatrixIntegers {
public:
	MatrixIntegers();
	~MatrixIntegers();
	void printMatrix();
	void setMatrix(vector<vector<int>>&);

private:
	int matrix[3][3];
}; 
