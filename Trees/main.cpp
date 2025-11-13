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

	std::string filename = "popularWords.txt"; //25K words in English 

	std::vector<std::string> words = getWordsInDictionaryFile(filename); 

	/************************SKEWED BST*****************************************/
	BinarySearchTree SKEWEDbst(words[0]);

	int numberOfWordsToAddToTree = 1'000; 
	//for (int i = 1; i < words.size(); ++i) //this will cause stack overflow!
	auto pRootSKEWED = SKEWEDbst.getPRoot(); 

	for (int i = 1; i < numberOfWordsToAddToTree; ++i)
	{
		SKEWEDbst.addBSTNode(words[i], pRootSKEWED);
	}

	std::string targetToSearchFor = "asdfasdfasdf"; //WORST-case input to a search algo. 

	//std::vector<int>::
	int numberOfSearchesInTheSKEWEDTree = SKEWEDbst.searchBST(targetToSearchFor);



	/************************More balanced BST*****************************************/
	//now shuffle the words and create a (more) balanced binary search tree: 
	std::mt19937 rng(std::random_device{}());

	std::shuffle(words.begin(), words.end(), rng); 
	//std::random_shuffle(words.begin(), words.end()); //std::random_shuffle is DEPRECATED
	std::uniform_int_distribution<> distribution(0, words.size() - 1);

	BinarySearchTree moreBalancedBST(words[0]);

	auto pRootOfBalanced = moreBalancedBST.getPRoot();
	for (int i = 1; i < words.size(); ++i)
	{
		moreBalancedBST.addBSTNode(words[i], pRootOfBalanced);
	}

	std::cout << "The HEIGHT of the more balanced tree is: " << moreBalancedBST.getTreeHeight() << "\n";

	/*Now SEARCH for some random thing in the tree (or worst-case -> something NOT in the tree)*/
	std::string gibberishNotInTheDictionary = "adsfasfasdf";
	int comparisonCount = moreBalancedBST.searchBST("adsfasfasdf");
	/*"Average" input search target (something that IS in the tree)*/
	std::string somethingInTheDictionary = words[distribution(rng)];

	comparisonCount = moreBalancedBST.searchBST(somethingInTheDictionary);

	/***************************The best boy (a self-balancing tree)*/
	rbTree<int, std::string> redBlackTree; //NOT my implementation
	for (int i = 0; i < words.size(); ++i)
	{
		redBlackTree.insert(i, words[i]);
	}

	std::cout << "The HEIGHT of the red-black tree is: " << redBlackTree.getTreeHeight() << "\n";


	//generate a red-black of 100K nodes (and check if the height ~= log2(100'000))
}

