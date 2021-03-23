//Dylan Nelson - X00144862 

#pragma once
#include <vector>
using namespace std;

template < class T >
class MatrixTemp {
public:
	MatrixTemp();
	~MatrixTemp();
	void printMatrix();
	void setMatrix(vector<vector<T>>&);

private:
	T matrix[3][3];
};

