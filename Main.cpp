/*Michael Crabtree
* Data Structures Project 3
* Binary Tree
*/

#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;

int main(){
	BinaryTree Tree;
	BinaryNode * node = new BinaryNode(5);
	BinaryNode * node1 = new BinaryNode(7);
	BinaryNode * node2 = new BinaryNode(6);
	BinaryNode * node3 = new BinaryNode(8);
	BinaryNode * node4 = new BinaryNode(4);

	Tree.Insert(node);
	Tree.Insert(node1);
	Tree.Insert(node2);
	Tree.Insert(node3);
	Tree.Insert(node4);

	if (Tree.Search(9, Tree.Get_Root()))
		cout << "true\n";
	Tree.Print(Tree.Get_Root());


	system("pause");
	return 0;
}