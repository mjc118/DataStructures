#include "BinaryTree.h"
#include <algorithm>

BinaryTree::BinaryTree()
:Root(NULL)
{}

BinaryTree::BinaryTree(BinaryNode* n)
: Root(n)
{}

BinaryTree::~BinaryTree()
{
}

BinaryNode* BinaryTree::Get_Root()const{ return Root; }

bool BinaryTree::Insert(BinaryNode* ln){

	if (!Root){
		Root = ln;
		ln->Prev = Root;
		return true;
	}
	return Check(ln, Root);
}

BinaryNode* BinaryTree::Check(BinaryNode* ln, BinaryNode* temproot){
	if (ln->get_data() <= temproot->get_data())
	{
		if (temproot->get_left() != NULL){
			return Check(ln, temproot->get_left());
		}
		else{
			ln->Prev = temproot;
			temproot->set_left(ln);
			
			return ln;
		}
	}
	else
	{
		if (temproot->get_right() != NULL){
			return Check(ln, temproot->get_right());
		}
		else{
			ln->Prev = temproot;
			temproot->set_right(ln);
			
			return ln;
		}
	}
}

BinaryNode* BinaryTree::Search(int num, BinaryNode* rn){
	if (num == rn->get_data())
		return rn;
	
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

int BinaryTree::Cost(BinaryNode* ln){
	if (ln == NULL)
		return 0;
	return ln->get_data() + std::max(Cost(ln->get_left()), Cost(ln->get_right()));
}

bool BinaryTree::Delete_Node(int num){
	BinaryNode* temp = Search(num, Root);
	bool ISL_Child = true;//figures out which side our deleted node is on
	bool HasL_Child = true;//figures out which side it has a child when it only has one

	if (temp == NULL)
		return false;
	if (num > temp->Prev->get_data())
		ISL_Child = false;

	//1st case, node is a leaf node
	if ((temp->get_left() == NULL) && (temp->get_right() == NULL)){
		if (ISL_Child)
			temp->Prev->set_left(NULL);
		else
			temp->Prev->set_right(NULL);
	}
	//2nd case, node has one child
	else if((temp->get_left() == NULL || temp->get_right() == NULL) &&
		(temp->get_left() != NULL || temp->get_right() != NULL)){
		
		if (temp->get_left() == NULL)
			HasL_Child = false;
		
		if (HasL_Child){
			if (ISL_Child)
				temp->Prev->set_left(temp->get_left());
			else
				temp->Prev->set_right(temp->get_left());
		}
		else{
			if (ISL_Child)
				temp->Prev->set_left(temp->get_right());
			else
				temp->Prev->set_right(temp->get_right());
		}
	}
	//3rd case, node has two children
	else if ((temp->get_left() != NULL) && (temp->get_right() != NULL)){//both should return true if they have children
		BinaryNode* predecessor = Predecessor(temp->get_left());
		//FIX THIS
		predecessor->Prev->set_right(predecessor->get_left());//takes care of loose ends before moving our predecessor

		predecessor->set_left(temp->get_left());
		predecessor->set_right(temp->get_right());
		
		if (ISL_Child)
			temp->Prev->set_left(predecessor);
		else
			temp->Prev->set_right(predecessor);
	}

		delete temp;
	return true;
}

BinaryNode* BinaryTree::Predecessor(BinaryNode* ln){
	if (ln->get_right() != NULL)
		Predecessor(ln->get_right());
	return ln;
}