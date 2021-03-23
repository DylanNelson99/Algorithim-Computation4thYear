#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>
#include <random>

//Dylan Nelson - X00144862

int main() {
	//introduce random numbers for the add method
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 30);

    ofstream outFile("bstlab.txt");
    ifstream inFile("bstlab.txt");

    BinarySearchTree bst = BinarySearchTree();
    
	// adding to the tree
    bst.add(15);
    for (int i = 0; i < 20; i++) {
		bst.add(distribution(generator));
    }
    
    std::cout << "Tree before serializing the file:\n";
    bst.pretty_print();
    bst.Serialise(outFile);

    std::cout << "\n\nTree after deserializing the file:\n";
    bst.Deserialise(inFile);
    bst.pretty_print();

    return 0;
}