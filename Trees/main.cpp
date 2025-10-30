// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"Tree.h"

int main()
{
	//Level 0 node (root): 
	BinaryTree binaryTree("Alice");


	/*Level 1 nodes: */
	auto pRoot = binaryTree.getPRoot(); //get address of parent for these new children

	binaryTree.addNode("Bob", pRoot); 
	binaryTree.addNode("Carol", pRoot);

	/*Level 2 nodes (only Bob will have children in this case)*/
	auto pBob = binaryTree.find_withBFS("Bob");
	//possible alternative to above: auto pBob = pRoot->pLeft (if pLeft is "exposed" to client)

	binaryTree.addNode("Darth", pBob); 
	binaryTree.addNode("Eve", pBob);

	binaryTree.find_withBFS("aslkadkafdklsafd"); //not present
	//
}

