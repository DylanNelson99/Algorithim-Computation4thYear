#include "BinaryTree.h"
#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

int main()
{
	BinaryTree bt = BinaryTree();

	bt.add('h');
	bt.add('z');
	bt.add('p');
	bt.add('a');
	bt.add('c');
	bt.add('l');
	bt.add('b');
	bt.add('r');
	bt.add('i');

	cout << bt.Search('l') << endl;

	cout << bt.Search('f') << endl;

	bt.Print();

	cout << endl;

	bt.PostOrder();

	cout << endl;

	bt.PreOrder();

	system("PAUSE");

	return 0;
}