// Main.cpp
// Group 2 - 

#include <iostream>
#include "BST.h"

int main() 
{
	BST<int> tree;
	std::cout << tree.isEmpty();
	tree.insert(5);
	
	return 0;
}
