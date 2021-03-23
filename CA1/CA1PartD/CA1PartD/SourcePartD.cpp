#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>
#include <random>

//Dylan Nelson - X00144862

int main() {
    //random numbers for tree
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 30);

    //for bst to txt file
    ofstream outFile("bst.txt");
    ifstream inFile("bst.txt");

    BinarySearchTree bst = BinarySearchTree();

    //adding the numbers to the tree
    bst.add(18);
    for (int i = 0; i < 20; i++) {
        bst.add(distribution(generator));
    }

    // outputs
    std::cout << "Tree before serializing:\n";
    bst.pretty_print();
    bst.Serialise(outFile);
    bst.destruct_tree();

    std::cout << "\n\nTree after deserializing file:\n";
    bst.Deserialise(inFile);
    bst.pretty_print();

    return 0;
}