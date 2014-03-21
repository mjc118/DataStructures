#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"

class BinaryTree
{
private:
	BinaryNode* Root;
	void Destruct(BinaryNode*);//used by deconstructor
public:
	BinaryTree();
	BinaryTree(BinaryNode*);
	~BinaryTree();

	BinaryNode* Get_Root()const;//grabs address of root of tree
	bool Insert(BinaryNode*);//inserts node
	BinaryNode* Check(BinaryNode*, BinaryNode*);//used with the insert function
	BinaryNode* Search(int, BinaryNode*);//Finds if a node with given value is in tree
	void Print(BinaryNode*);//Prints Tree Highest to Lowest
	bool Delete_Node(int);//FINISH THIS FUNCTION
	int Depth(BinaryNode*, BinaryNode*, int = 0);//finds height of specified node if it is in tree
	int Cost(BinaryNode*);//returns cost of most expensive path (not height wise)
	BinaryNode* Predecessor(BinaryNode*);
	bool Balanced(BinaryNode*);//returns if tree is balanced, difference in tree heights must not be > 1
	int Height(BinaryNode*);//returns height of tree
};

#endif