#pragma once
#include <vector>

//Dylan Nelson - X00144862

using namespace std;

class Heap {
public:
	Heap();
	~Heap();
	void insert(int value); //Add new value
	void remove(); // remove first node
	void trickleUp(); //move node from bottom position
	void trickleDown(); //move node from top position
	void display(); //Display all data in the heap
private:
	int getLChildIndex(int pIndex);
	int getRChildIndex(int pIndex);
	int lChild(int index);
	int rChild(int index);
	int parent(int index);
	bool hasLChild(int index);
	bool hasRChild(int index);
	bool hasParent(int index);
	int getPIndex(int cIndex);
	vector<int> heap;
};
