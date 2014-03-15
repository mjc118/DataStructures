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
	BinaryNode();
	BinaryNode(int);
	~BinaryNode();

	BinaryNode* get_left()const;
	BinaryNode* get_right()const;
	int get_data()const;

	void set_left(BinaryNode*);
	void set_right(BinaryNode*);
	void set_data(int);
};

#endif