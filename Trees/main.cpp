// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"Tree.h"

#include<algorithm> 
#include<fstream> 
#include<list> 
#include<vector> 
#include "demos.h"
#include "someTestTrees.h"

int main()
{
	//demoSimpleBinaryTreeAndBFS(); 

	auto inorderTree = generateInorderTree(); 
	std::string gibberishToSearchFor = "afdasdf"; //causes traversal of entire tree

	//start the recursive search at the root (the "beginning" of the tree):
	auto pRoot = inorderTree.getPRoot(); 

	//inorderTree.find(gibberishToSearchFor, pRoot);

	//inorderTree.inorderTraverse(pRoot); 

	inorderTree.nonrecursiveDFT(pRoot); 
}

