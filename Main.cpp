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
	BinaryNode * node1 = new BinaryNode(1);
	BinaryNode * node2 = new BinaryNode(2);
	BinaryNode * node3 = new BinaryNode(3);
	BinaryNode * node4 = new BinaryNode(4);
	BinaryNode * node5 = new BinaryNode(5);
	BinaryNode * node6 = new BinaryNode(6);
	BinaryNode * node7 = new BinaryNode(7);

	Tree.Insert(node7);
	Tree.Insert(node5);
	Tree.Insert(node6);
	Tree.Insert(node2);
	Tree.Insert(node4);
	Tree.Insert(node3);
	Tree.Insert(node1);

	if(Tree.Search(4, Tree.Get_Root()))
		cout << "true\n";
	Tree.Print(Tree.Get_Root());
	cout << endl << Tree.Cost(Tree.Get_Root()) << endl;
	Tree.Delete_Node(5);
	Tree.Print(Tree.Get_Root());

	//Tree.Print(Tree.Get_Root());
	/*cout << "4's parent " << node2->Prev << " , 2's " << node3->Prev << " , 3's L & R address's " << node1->get_left() << " " << node1->get_right() << endl;
	cout << "2 address " << node3 << " , 4 address " << node2 << endl;
	cout << "3 address " << node1 << " , left child of 5 " << node->get_left() << endl;
	cout << node2->Prev->get_data();
	*/

	system("pause");
	return 0;
}