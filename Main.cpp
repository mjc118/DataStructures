/*Michael Crabtree
* Data Structures Project 3
* Binary Tree
*/

#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;

bool Switch(int);

int main(){
	int input;

	do{
		cout << "---Make a Selection---\n";
		cout << "1) Insert a Value\n";
		cout << "2) Delete a Value\n";
		cout << "3) Search for a Value\n";
		cout << "4) Print entire Tree\n";
		cout << "5) Find the Depth of a specific Node\n";
		cout << "6) Display the Cost of your tree\n";
		cout << "7) Check if the Tree is Balanced\n";
		cout << "8) Exit\n";

		cin >> input;

	} while (Switch(input));

	system("pause");
	return 0;
}

bool Switch(int n){
	static BinaryTree Tree;
	int input;
	switch (n){
	case 1:{
			   cout << "Input an integer to be inserted\n";
			   cin >> input;
			   BinaryNode* ln = new BinaryNode(input);
			   Tree.Insert(ln);
			   break;
	}
	case 2:{
			   cout << "Input an integer that will be deleted\n";
			   cin >> input;
			   //delete stuff
			   Tree.Delete_Node(input);
			   break;
	}
	case 3:{
			   cout << "Input an integer to be searched for\n";
			   cin >> input;
			   if (Tree.Search(input, Tree.Get_Root()))
				   cout << "Exists in Tree\n";
			   else
				   cout << "Does not exist in Tree\n";
			   break;
	}
	case 4:{
			   Tree.Print(Tree.Get_Root());
			   cout << endl;
			   break;
	}
	case 5:{
			   cout << "Input the value of the node whos Depth you want\n";
			   cin >> input;
			   int x = Tree.Depth(Tree.Search(input, Tree.Get_Root()), Tree.Get_Root());

			   if (x >= 0)
				   cout << x << endl;
			   else
				   cout << "No such node exists in the tree.\n";
			   break;
	}
	case 6:{
			   cout << Tree.Cost(Tree.Get_Root()) << endl;
			   break;
	}
	case 7:{
			   if (Tree.Balanced(Tree.Get_Root()))
				   cout << "The tree is balanced\n";
			   else
				   cout << "The tree is not balanced\n";
			   break;
	}
	case 8:{
			   return false;
			   break;
	}
	default:{
				cout << "Input a valid Menu Command\n";
				return true;
				break;
	}
	}
	return true;
}