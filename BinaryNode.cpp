#include "BinaryNode.h"


BinaryNode::BinaryNode()
:Data(-1),
left(NULL),
right(NULL),
Prev(NULL)
{}

BinaryNode::BinaryNode(int l)
: Data(l),
left(NULL),
right(NULL),
Prev(NULL)
{}

BinaryNode::~BinaryNode()
{
}

//accessors
BinaryNode* BinaryNode::get_left(){ return left; }

BinaryNode* BinaryNode::get_right(){ return right; }

int BinaryNode::get_data(){ return Data; }

//mutators
void BinaryNode::set_left(BinaryNode* l){ left = l; }

void BinaryNode::set_right(BinaryNode* r){ right = r; }

void BinaryNode::set_data(int d){ Data = d; }