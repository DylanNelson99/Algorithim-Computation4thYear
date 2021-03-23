#include <iostream>
#include <vector>
#include <algorithm>
#include "Heap.h"

//Dylan Nelson - X00144862

using namespace std;
int main()
{
	Heap heap = Heap();

	//inserts
	heap.insert(4);
	heap.insert(6);
	heap.insert(5);
	heap.insert(7);

	vector<int> vect;

	//Display heap
	cout << "Heap data: " << endl;
	heap.display();

	//Remove first node in heap
	heap.remove();

	//new display
	cout << "Heap After the remove: " <<endl;
	heap.display();


	//Vector
	vect.push_back(4);
	vect.push_back(6);
	vect.push_back(5);
	vect.push_back(7);

	cout << "Size of vector: " << vect.size() << endl;
	for (size_t i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << endl;
	}

	//Displaying Trimmed Vector
	int size = vect.size() - 1;
	cout << "Size of vector (Trimmed): " << size << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << vect[i] << endl;
	}

	//Destructor
	heap.~Heap();
}
