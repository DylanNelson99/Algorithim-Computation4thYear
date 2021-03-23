#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

int main()
{
	BinaryTree bt = BinaryTree();

	bt.add(1);
	bt.add(10);
	bt.add(1);
	bt.add(17);
	bt.add(11);
	bt.add(3);
	bt.add(2);
	bt.add(2);

	cout << "Height :" << bt.height() << endl;

	cout << bt.hasPathSum(bt.getRoot(), 12) << endl;

	cout << bt.hasPathSum(bt.getRoot(), 4) << endl;

	cout << "----Printed Path below: ----" << endl;

	bt.printPaths(bt.getRoot());

	system("pause");

	return 0;
}