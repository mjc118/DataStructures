#pragma once
#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <string>
#include <cstdlib>
#include <iostream>

class BinaryNode
{
private:
	int Data;
	BinaryNode*  left, * right;
public:
	BinaryNode* Prev;

	BinaryNode();
	BinaryNode(int);
	~BinaryNode();

	BinaryNode* get_left();
	BinaryNode* get_right();
	int get_data();

	void set_left(BinaryNode*);
	void set_right(BinaryNode*);
	void set_data(int);
};

#endif