//Dylan Nelson - X00144862

#include <iostream>
#include<cmath>
using namespace std;

template < typename T >
T returnAbsoluteValueOfTwoNumbers(T val1, T val2) {
	return abs(val1 - val2);
}
int main()
{
	cout << returnAbsoluteValueOfTwoNumbers('a', 'c') << endl;
	return 0;
}
