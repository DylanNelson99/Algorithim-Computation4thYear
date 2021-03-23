#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

int main()
{
	BinaryTree bt = BinaryTree();

	cout << bt.minValue(bt.getRoot()) << endl;

	bt.add(3);
	bt.add(6);
	bt.add(2);
	bt.add(4);
	bt.add(10);

	cout << "Min vaLue is : " << bt.minValue(bt.getRoot()) << endl;

	cout << "Max value is : " << bt.maxValue(bt.getRoot()) << endl;

	cout << "Is this a binary search tree?(1=yes / 0=no): " << bt.isBSTV1(bt.getRoot()) << endl;

	cout << "Is this a binary search tree? (2ND)(1=yes / 0=no): " << bt.isBST2(bt.getRoot()) << endl;

	system("PAUSE");

	return 0;
}