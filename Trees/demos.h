#pragma once
#include "Tree.h"


void demoSimpleBinaryTreeAndBFS()
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

	auto pGibberish = binaryTree.find_withBFS("aslkadkafdklsafd"); //not present

}

//void demoDepthFirstTraversal()
//{
//	auto inorderTree = generateInorderTree();
//	//std::string gibberishToSearchFor = "afdasdf"; //causes traversal of entire tree
//
//	//start the recursive search at the root (the "beginning" of the tree):
//	auto pRoot = inorderTree.getPRoot();
//
//	//inorderTree.find(gibberishToSearchFor, pRoot);
//
//	//inorderTree.inorderTraverse(pRoot); 
//	//inorderTree.getNodeDepth("asfdasd",)
//	inorderTree.nonrecursiveDFT(pRoot);
//}