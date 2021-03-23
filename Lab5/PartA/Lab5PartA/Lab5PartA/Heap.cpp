/* **Some help from here on the parent and child index nodes for the heap**
Title: Data Structures: Heap
  Author: Hacker Rank
  Place: Youtube
  Date: 27 Sep 2016
  Link: https://www.youtube.com/watch?v=t0Cq6tVNRBA
*/

#include "Heap.h"
#include <algorithm>
#include <iostream>

//Dylan Nelson - X00144862

using namespace std;

Heap::Heap() {}

Heap::~Heap() {}

int Heap::getLChildIndex(int parentIndex)
{
	return 2 * parentIndex + 1;
}

int Heap::getRChildIndex(int parentIndex)
{
	return 2 * parentIndex + 2;
}

int Heap::getPIndex(int childIndex)
{
	return (childIndex - 1) / 2;
}

bool Heap::hasLChild(int index)
{
	return getLChildIndex(index) < heap.size();
}

bool Heap::hasRChild(int index)
{
	return getRChildIndex(index) < heap.size();
}

bool Heap::hasParent(int index)
{
	return getPIndex(index) >= 0;
}

int Heap::lChild(int index)
{
	return heap[getLChildIndex(index)];
}

int Heap::rChild(int index)
{
	return heap[getRChildIndex(index)];
}

int Heap::parent(int index)
{
	return heap[getPIndex(index)];
}

void Heap::insert(int value) {
	heap.push_back(value);
	trickleUp();
}

void Heap::remove() {
	
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	trickleDown();
}

void Heap::trickleDown() {
	int index = 0;
	while (hasLChild(index)) {
		int smallChildIndex = getLChildIndex(index);
		if (hasRChild(index) && rChild(index) < lChild(index)) {
			smallChildIndex = getRChildIndex(index);
		}


		if (heap[index] < heap[smallChildIndex])
			break;
		else {
			swap(heap[index], heap[smallChildIndex]);
		}
		index = smallChildIndex;
	}
}

void Heap::trickleUp() {
	int index = heap.size() - 1;

	while (hasParent(index) && parent(index) > heap[index]) {
		swap(heap[getPIndex(index)], heap[index]);
		index = getPIndex(index);
	}
}

void Heap::display()
{
	for (int i = 0; i < heap.size(); i++)
	{
		cout << "[" << heap[i] << "] ";
	}
	cout << endl;
}