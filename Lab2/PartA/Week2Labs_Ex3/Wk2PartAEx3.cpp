//Dylan Nelson - X00144862 

#include <iostream>
#include "MatrixTemp.h"
#include "MatrixTemp.cpp"
#include <vector>

int main()
{

	vector<vector<int>> vect1
	{
		{2,4,6},
		{8,10,12},
		{14,16,18}
	};

	vector<vector<double>> vect2
	{
		{1.2, 1.3, 1.4},
		{2.2, 2.3, 2.4},
		{3.2, 3.3, 3.4},
	};

	vector<vector<float>> vect3
	{
		{719.42484, 1110.6259, 17285.36921},
		{3184.313, 45654.3232, 23659.27416},
		{636.2369, 9636.5876, 6936475.323333},
	};

	MatrixTemp<int>* temp1 = new MatrixTemp<int>();
	cout << "  Vector of integers " << endl;
	temp1->setMatrix(vect1);

	cout << "  ________________________" << endl;

	MatrixTemp<double>* temp2 = new MatrixTemp<double>();
	cout << "  Vector of doubles " << endl;
	temp2->setMatrix(vect2);

	cout << "  ________________________" << endl;

	MatrixTemp<float>* temp3 = new MatrixTemp<float>();
	cout << "  Vector of floats " << endl;
	temp3->setMatrix(vect3);

	return 0;
}