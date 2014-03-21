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
	Destruct(Root);
}

void BinaryTree::Destruct(BinaryNode* rn){
	if (rn == NULL)
		return;
	if (rn->get_right() != NULL)
		Destruct(rn->get_right());
	if (rn->get_left() != NULL)
		Destruct(rn->get_left());

	delete rn;
	return;
}

BinaryNode* BinaryTree::Get_Root()const{ return Root; }

bool BinaryTree::Insert(BinaryNode* ln){
	if (Search(ln->get_data(), Root)){
		std::cout << "That value is already in the tree\n";
		delete ln;
		return false;
	}

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
	if (rn == NULL)
		return NULL;
	if (num == rn->get_data())
		return rn;
	else if (num < rn->get_data() && rn->get_left() != NULL)
		return Search(num, rn->get_left());
	else if (num > rn->get_data() && rn->get_right() != NULL)
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
	bool root = false;//if node being deleted is the root of tree, this = true

	if (temp == NULL)
		return false;

	if (temp == Root)
		root = true;

	if (num > temp->Prev->get_data())
		ISL_Child = false;

	//1st case, node is a leaf node
	if ((temp->get_left() == NULL) && (temp->get_right() == NULL)){
		if (root)
			Root = NULL;
		else if (ISL_Child)
			temp->Prev->set_left(NULL);
		else
			temp->Prev->set_right(NULL);
		
		delete temp;
	}
	//2nd case, node has one child
	else if((temp->get_left() == NULL || temp->get_right() == NULL) &&
		(temp->get_left() != NULL || temp->get_right() != NULL)){
		
		if (temp->get_left() == NULL)
			HasL_Child = false;
		
		if (root){//if the node is the Root
			if (HasL_Child){
				Root = temp->get_left();
				temp->get_left()->Prev = Root;
			}
			else{
				Root = temp->get_right();
				temp->get_right()->Prev = Root;
			}
		}
		else if (HasL_Child){
			if (ISL_Child)
				temp->Prev->set_left(temp->get_left());
			else
				temp->Prev->set_right(temp->get_left());
			temp->get_left()->Prev = temp->Prev;
		}
		else{
			if (ISL_Child)
				temp->Prev->set_left(temp->get_right());
			else
				temp->Prev->set_right(temp->get_right());
			temp->get_right()->Prev = temp->Prev;
		}

		delete temp;
	}
	//3rd case, node has two children
	else if ((temp->get_left() != NULL) && (temp->get_right() != NULL)){
		BinaryNode* Predecessor = temp->get_left();
		while (Predecessor->get_right() != NULL)
			Predecessor = Predecessor->get_right();
		//Don't ask me, this function is evil
		if (temp == Root){
			if (Predecessor == temp->get_left()){
				Root = Predecessor;
				Predecessor->set_right(temp->get_right());
				Predecessor->Prev = Root;

				delete temp;
			}
			else{
				Predecessor->Prev->set_right(Predecessor->get_left());
				Root = Predecessor;
				Predecessor->set_left(temp->get_left());
				Predecessor->set_right(temp->get_right());
				Predecessor->Prev = Root;
				delete temp;
			}
		}
		else if (Predecessor == temp->get_left()){
			if (ISL_Child)
				temp->Prev->set_left(Predecessor);
			else
				temp->Prev->set_right(Predecessor);
			Predecessor->set_right(temp->get_right());
			Predecessor->Prev = temp->Prev;

			delete temp;
		}
		else{
			Predecessor->Prev->set_right(Predecessor->get_left());
			if (ISL_Child)
				temp->Prev->set_left(Predecessor);
			else
				temp->Prev->set_right(Predecessor);

			Predecessor->set_left(temp->get_left());
			Predecessor->set_right(temp->get_right());
			Predecessor->Prev = temp->Prev;
			delete temp;
		}
	}

	return true;
}


int BinaryTree::Depth(BinaryNode* ln, BinaryNode* TempRoot, int ans){
	if (ln == NULL)
		return -1;
	if (TempRoot == ln)
		return ans;
	
	if (ln->get_data() < TempRoot->get_data())
		Depth(ln, TempRoot->get_left(), ++ans);
	else
		Depth(ln, TempRoot->get_right(), ++ans);
}

int BinaryTree::Height(BinaryNode* rn){
	if (rn == NULL)
		return -1;
	else
		return 1 + std::max(Height(rn->get_left()), Height(rn->get_right()));
}

bool BinaryTree::Balanced(BinaryNode* rn){
	if (rn == NULL)
		return true;
	if (abs(Height(rn->get_left()) - Height(rn->get_right())) > 1)
		return false;
	return true;
}