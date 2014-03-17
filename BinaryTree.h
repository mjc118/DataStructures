#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"

class BinaryTree
{
private:
	BinaryNode* Root;
public:
	BinaryTree();
	BinaryTree(BinaryNode*);
	~BinaryTree();


	BinaryNode* Get_Root()const;
	bool Insert(BinaryNode*);
	BinaryNode* Check(BinaryNode*, BinaryNode*);
	BinaryNode* Search(int, BinaryNode*);
	void Print(BinaryNode*);
	bool Delete_Node(int);
	int Depth(int);
	int Cost(BinaryNode*);
	BinaryNode* Predecessor(BinaryNode*);
	//return int + max(Cost(left), Cost(right));
	//max is a function from cmath
	bool Balanced();
	int Height();
};

#endif