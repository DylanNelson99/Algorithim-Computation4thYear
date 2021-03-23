#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
//Dylan Nelson - X00144862
int main()
{
	BinarySearchTree bt = BinarySearchTree();

	cout << "Height :" << bt.height() << endl;

	bt.add(4);

	cout << "Height :" << bt.height() << endl;

	bt.add(3);
	bt.add(8);
	bt.add(20);
	bt.add(9);
	bt.add(2);
	bt.add(3);
	bt.add(7);

	cout << "Height :" << bt.height() << endl;

	bt.printPaths(bt.getRoot());

	system("PAUSE");

	return 0;
}