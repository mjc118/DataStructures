#include "BinaryTree.h"
#include <algorithm>

BinaryTree::BinaryTree()
:Root(NULL),
 Prev(NULL)
{}

BinaryTree::BinaryTree(BinaryNode* n)
: Root(n),
  Prev(NULL)
{}

BinaryTree::~BinaryTree()
{
}

BinaryNode* BinaryTree::Get_Root()const{ return Root; }

bool BinaryTree::Insert(BinaryNode* ln){

	if (!Root){
		Root = ln;
		return true;
	}
	return Check(ln, Root);
}

BinaryNode* BinaryTree::Check(BinaryNode* ln, BinaryNode* temproot){
	if (ln->get_data() <= temproot->get_data())
	{
		if (temproot->get_left() != NULL){
			Prev = temproot;
			return Check(ln, temproot->get_left());
		}
		else{
			temproot->set_left(ln);
			
			return ln;
		}
	}
	else
	{
		if (temproot->get_right() != NULL){
			Prev = temproot;
			return Check(ln, temproot->get_right());
		}
		else{
			temproot->set_right(ln);
			
			return ln;
		}
	}
}

BinaryNode* BinaryTree::Search(int num, BinaryNode* rn){
	if (num == rn->get_data())
		return rn;
	
	Prev = rn;
	if (num < rn->get_data() && rn->get_left() != NULL)
		return Search(num, rn->get_left());
	
	if (num > rn->get_data() && rn->get_right() != NULL)
		return Search(num, rn->get_right());
	
	return NULL;
}

void BinaryTree::Print(BinaryNode* temp){
	if (temp == NULL)
		return;
	
	if (temp->get_right() != NULL)
		Print(temp->get_right());

	std::cout << temp->get_data() << ", ";

	if (temp->get_left() != NULL)
		Print(temp->get_left());
}

bool BinaryTree::Delete_Node(int num){
	BinaryNode* temp = Search(num, Root);
	if (temp == NULL)
		return false;
	if (temp->get_left() == NULL && temp->get_right() == NULL)
		delete temp;
	return true;
}