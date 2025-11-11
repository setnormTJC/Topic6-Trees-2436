// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include"Tree.h"

#include<algorithm> 
#include<fstream> 

#include<list> 
#include<map> //note that std::map is implemented using a TREE 
#include<random> 
#include<set>
#include<vector> 
#include "demos.h"
#include "someTestTrees.h"
#include"utils.h"
#include "SelfBalancingTree.cpp"

int main()
{
	
	//demoSimpleBinaryTreeAndBFS(); 
	//demoDepthFirstTraversal(); 

	std::string filename = "popularWords.txt";

	auto words = getWordsInDictionaryFile(filename); 

	BinarySearchTree SKEWEDbst(words[0]);

	int numberOfWordsToAddToTree = 1'000; 
	//for (int i = 1; i < words.size(); ++i)
	auto pRootSKEWED = SKEWEDbst.getPRoot(); 

	for (int i = 1; i < numberOfWordsToAddToTree; ++i)
	{
		SKEWEDbst.addBSTNode(words[i], pRootSKEWED);
	}

	//now shuffle the words and create a (more) balanced binary search tree: 
	std::mt19937 rng(std::random_device{}());

	std::shuffle(words.begin(), words.end(), rng); 
	//std::random_shuffle(words.begin(), words.end()); //std::random_shuffle is DEPRECATED
	
	BinarySearchTree moreBalancedBST(words[0]);

	auto pRootOfBalanced = moreBalancedBST.getPRoot();
	for (int i = 1; i < words.size(); ++i)
	{
		moreBalancedBST.addBSTNode(words[i], pRootOfBalanced);
	}

	std::cout << "The HEIGHT of the more balanced tree is: " << moreBalancedBST.getTreeHeight() << "\n";


	/*The best boy (a self-balancing tree)*/
	rbTree<int, std::string> redBlackTree; //NOT my implementation
	for (int i = 0; i < words.size(); ++i)
	{
		redBlackTree.insert(i, words[i]);
	}

	std::cout << "The HEIGHT of the red-black tree is: " << redBlackTree.getTreeHeight() << "\n";
}

