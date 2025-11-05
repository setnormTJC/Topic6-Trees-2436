#include "Tree.h"
///*NOTE: don't attempt to run this - just using as a "reference"*/
///*Also note - uncomment to fix the spacing on ASCII trees*/
//
//#pragma once
//
//#pragma once
//
//#include"C:/Users/Work/Downloads/TreeNode.h"
//
//
//using namespace MySpace::DataStructs::Trees;
///// <summary>
///// Generates this tree: 
/////<para>      a </para>
////			* / \
////		   * b   f 
////		  * / \ / \
//	   //* c  e g  h
////		* /			\
////*		 d           i
///// </summary>
///// <returns>the ROOT of some binary tree </returns>
//auto generateExampleTree1()
//{
//	TreeNode<char>* root = new TreeNode<char>('a');
//
//	//level 1 nodes: 
//	root->left = new TreeNode<char>('b');
//	root->right = new TreeNode<char>('f');
//
//	//level 2 nodes: 
//	root->left->left = new TreeNode<char>('c');
//	root->left->right = new TreeNode<char>('e');
//	root->right->left = new TreeNode<char>('g');
//	root->right->right = new TreeNode<char>('h');
//
//	//level 3 nodes: 
//	root->left->left->left = new TreeNode<char>('d');
//	root->right->right->right = new TreeNode<char>('i');
//
//	return root;
//};
//
///// <summary>
///// /// Generates this tree: 
///            A 
//			* / \
//		   * B   C
//		  * / \   \
	   //* D   E   F
//			\    
//			 G	
///// </summary>
///// <returns></returns>
//auto generateLevelOrderTree()
//{
//	TreeNode<char>* root = new TreeNode<char>('A');
//
//	root->left = new TreeNode<char>('B');
//	//cout << root->left->isLeaf() << endl;
//	//cout << root->isLeaf() << endl;
//
//	root->left->left = new TreeNode<char>('D');
//	//cout << root->left->isLeaf() << endl; 
//	root->left->left->right = new TreeNode<char>('G');
//
//	root->left->right = new TreeNode<char>('E');
//
//	root->right = new TreeNode<char>('C');
//	root->right->right = new TreeNode<char>('F');
//
//
//	return root;
//}
//

/// <summary>
/// Generates: 
///              +
//			 /      \
//		    *        /
//		   / \     /   \
//	      a   b   -     e
//			    /  \     
//			   c    d       
/// </summary>
/// <returns></returns>
BinaryTree generateInorderTree()
{
    BinaryTree tree("+");

    // left subtree (*)
    tree.addNode("*", tree.getPRoot());
    
    //left grandchildren of root: 
    auto pTimes = tree.find_withBFS("*");//left child of root

    tree.addNode("a", pTimes); //addNode adds to the left first, then the right 
    tree.addNode("b", pTimes); 



    // right subtree (/)
    tree.addNode("/", tree.getPRoot());

    auto pOver = tree.find_withBFS("/");

    // children of '/'
    tree.addNode("-", pOver);
    tree.addNode("e", pOver);

    // children of '-'
    auto pMinus = tree.find_withBFS("-");
    tree.addNode("c", pMinus);
    tree.addNode("d", pMinus);

    return tree;
}

//
//
///// <summary>
///// generates: 
/////		   25
/////		/		\
/////	  10		 37
/////     \		/  \ 
/////      15	  30    65
///// </summary>
///// <returns></returns>
//auto generateExampleBST()
//{
//	//level 0 (only 1 node) 
//	TreeNode<int>* root = new TreeNode<int>(25);
//
//
//	//level one nodes: (max number of level one nodes is two) 
//	root->left = new TreeNode<int>(10);
//	root->right = new TreeNode<int>(37);
//
//	//level two nodes: 
//	root->left->right = new TreeNode<int>(15);
//	root->right->left = new TreeNode<int>(30);
//	root->right->right = new TreeNode<int>(65);
//
//	return root;
//}
//
//
