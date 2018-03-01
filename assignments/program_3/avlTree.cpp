#include <iostream>
#include <fstream>
#include <time.h>
#include "avlTree.h"

//https://visualgo.net/en/bst

using namespace std;

avlTree::avlTree(){
	root=NULL;
}

avlTree::~avlTree(){

}

//************************************************************************
// Method Name: insert
//
// Private
//
// Purpose: Inserts a node into a binary tree
//
// Arguments: reference to the root, and a reference to the new node
//
// Returns: Nothing.
//*************************************************************************
void avlTree::insert(nodes *&nodePtr, nodes *&newNode){

	if (nodePtr == NULL){
		nodePtr = newNode;
	}else if (newNode->value <= nodePtr->value){
		newNode->parent = nodePtr;
		insert(nodePtr->left,newNode);

	}else{
		newNode->parent = nodePtr;
		insert(nodePtr->right,newNode);
	}

}

//************************************************************************
// Method Name: insertNode
//
// Public
//
// Purpose: Creates a new node and assigns the passed in value to it. Subsequently
//          calls insert to actually travers the binary tree and link the node in
//          proper location.
//
// Arguments: integer to be placed in binary tree.
//
// Returns: Nothing.
//*************************************************************************
void avlTree::insert(string word){
	nodes *newNode;

	newNode = new nodes(word);
	insert(root,newNode);
	computeAvlValues(root);
}

//************************************************************************
// Method Name: inorder,postorder,preorder (all the same)
//
// Public
//
// Purpose: Traverses a binary tree
//
// Arguments: integer to be placed in binary tree.
//
// Returns: Nothing.
//*************************************************************************
void avlTree::inorder(nodes *nodePtr){
	if(nodePtr){
		inorder(nodePtr->left);
		cout<<nodePtr->value<<" "<<"("<<nodePtr->avlValue<<") ";
		inorder(nodePtr->right);
	}
}

void avlTree::postorder(nodes *nodePtr){
	if(nodePtr){
		inorder(nodePtr->left);
		inorder(nodePtr->right);
		cout<<nodePtr->value<<" "<<"("<<nodePtr->avlValue<<") ";
	}
}

void avlTree::preorder(nodes *nodePtr){
	if(nodePtr){
		cout<<nodePtr->value<<" "<<"("<<nodePtr->avlValue<<") ";
		inorder(nodePtr->left);
		inorder(nodePtr->right);
	}
}

//************************************************************************
// Method Name: searchNode
//
// Public
//
// Purpose: Traverses a binary tree looking for a key value
//
// Arguments: integer to look for
//
// Returns: true if found, false otherwise
//*************************************************************************
bool avlTree::search(string word){
	nodes *nodePtr = root;

	while (nodePtr){
		if(nodePtr->value==word)
			return true;
		else if (word < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}


//************************************************************************
// Method Name: lookupNode
//
// Public
//
// Purpose: Traverses a binary tree looking for a key value
//
// Arguments: the root, string to look for, and an initial counter
//
// Returns: the number of comparisons to lookup work
//*************************************************************************
int avlTree::lookup(nodes* theRoot, string word, int count){
	nodes *nodePtr = theRoot;

	while (nodePtr){
		if(nodePtr->value==word) {
			return count;
		} else if (word < nodePtr->value) {
			count++;
			nodePtr = nodePtr->left;
		} else {
			count++;
			nodePtr = nodePtr->right;
		}
	}
	return count;
}


//************************************************************************
// Method Name: getRootNode
//
// Public
//
// Purpose: Returns the root node
//
// Arguments: N/A
//
// Returns: the root
//*************************************************************************
nodes* avlTree::getRoot() {
	return root;
}


//************************************************************************
// Method Name: remove
//
// Private
//
// Purpose: Actually removes a node from a tree by pointer manipulation and
//          frees the memory
//
// Arguments: address of node to be deleted
//
// Returns: void
//*************************************************************************

nodes* avlTree::remove(nodes*& root, string key)
{
	if (!root)
	{
		return NULL;
	}
	if (key < root->value)
	{
		cout << "going left" << endl;
		root->left = remove(root->left, key);
	}
	else if (key > root->value)
	{
		cout << "going right" << endl;
		root->right = remove(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			nodes *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			nodes *temp = root->left;
			delete root;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		nodes *temp = predSuccessor(root);

		printNode(temp, "predSuccessor");

		// Copy the inorder successor's content to this node
		root->value = temp->value;

		// Delete the inorder successor
		root->right = remove(root->right, temp->value);
	}
	return root;
}

void avlTree::printNode(nodes *n, string label = "")
{
	if (label != "")
	{
		cout << "[" << label << "]";
	}
	cout << "[[" << n << "][" << n->value << "]]\n";
	if (n->left)
	{
		cout << "\t|-->[L][[" << n->left << "][" << n->left->value << "]]\n";
	}
	else
	{
		cout << "\t\\-->[L][null]\n";
	}
	if (n->right)
	{
		cout << "\t\\-->[R][[" << n->right << "][" << n->right->value << "]]\n";
	}
	else
	{
		cout << "\t\\-->[R][null]\n";
	}
}

nodes* avlTree::predSuccessor(nodes *root)
{
	nodes*current = root;

	if (root->right)
	{
		current = root->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
	}
	else if (root->left)
	{
		current = root->left;
		while (current->right != NULL)
		{
			current = current->right;
		}
	}

	return current;
}
//************************************************************************
// Method Name: height
//
// Private
//
// Purpose: Actually removes a node from a tree by pointer manipulation and
//          frees the memory
//
// Arguments: address of the root of the tree (or subtree)
//
// Returns: void
//*************************************************************************
int avlTree::height(nodes *nodePtr){
	int left_height=0;
	int right_height=0;
	if(nodePtr==NULL)
		return 0;
	else{
		left_height = height(nodePtr->left);
		right_height = height(nodePtr->right);
	}
	if(left_height>right_height)
		return 1+left_height;
	else
		return 1+right_height;
}

//************************************************************************
// Method Name: treeHeight
//
// Public
//
// Purpose: Public method to call the private height method
//
// Arguments: none
//
// Returns: void
//*************************************************************************
int avlTree::treeHeight(){
	return height(root);
}

//************************************************************************
// Method Name: avlValue
//
// Private
//
// Purpose: Private method to calculate the avl value of a node.
//
// Arguments: address of a node
//
// Returns: void
//*************************************************************************
int avlTree::avlValue(nodes *nodePtr)
{
	return height(nodePtr->right)-height(nodePtr->left);
}

//************************************************************************
// Method Name: computeAvlValues
//
// Private
//
// Purpose: Private method to calculate the avl values of the entire tree.
//
// Arguments: address of a node
//
// Returns: void
//*************************************************************************
void avlTree::computeAvlValues(nodes *&nodePtr)
{
	if(nodePtr){
		computeAvlValues(nodePtr->left);
		computeAvlValues(nodePtr->right);
		nodePtr->avlValue=avlValue(nodePtr);
		if(nodePtr->avlValue > 1){
			rotateLeft(nodePtr);
		}else if(nodePtr->avlValue < -1){
			rotateRight(nodePtr);
		}
	}
}

//************************************************************************
// Method Name: rotateLeft
//
// Private
//
// Purpose: Private method to perform a left rotation from a given position in a tree
//
// Arguments: address of a node
//
// Returns: void
//*************************************************************************
void avlTree::rotateLeft(nodes *&SubRoot)
{


	if(leftHeavy(SubRoot->right)){
		rotateRight(SubRoot->right);
	}

	nodes *Temp;

	Temp = SubRoot->right;
	SubRoot->right = Temp->left;
	Temp->left = SubRoot;
	SubRoot = Temp;

	computeAvlValues(SubRoot);
}

//************************************************************************
// Method Name: rotateLeft
//
// Private
//
// Purpose: Private method to perform a right rotation from a given position in a tree
//
// Arguments: address of a node
//
// Returns: void
//*************************************************************************
void avlTree::rotateRight(nodes *&SubRoot)
{
	if(rightHeavy(SubRoot->left)){
		rotateLeft(SubRoot->left);
	}

	nodes *Temp;

	Temp = SubRoot->left;
	SubRoot->left = Temp->right;
	Temp->right = SubRoot;
	SubRoot = Temp;

	computeAvlValues(SubRoot);
}

//************************************************************************
// Method to help create GraphViz code so the expression tree can
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive
// tree traversal.
//************************************************************************
void avlTree::graphVizGetIds(nodes *nodePtr,ofstream &VizOut){
	static int NullCount=0;
	if(nodePtr){
		graphVizGetIds(nodePtr->left,VizOut);
		VizOut<<"node"<<nodePtr->value
			  <<"[label=\""<<nodePtr->value<<"\\n"
			  <<"Avl:"<<nodePtr->avlValue<<"\\n"
			  //<<"Add:"<<nodePtr<<"\\n"
			  //<<"Par:"<<nodePtr->parent<<"\\n"
			  //<<"Rt:"<<nodePtr->right<<"\\n"
			  //<<"Lt:"<<nodePtr->left<<"\\n"
			  <<"\"]"<<endl;
		if(!nodePtr->left){
			NullCount++;
			VizOut<<"nnode"<<NullCount<<"[label=\"X\",shape=point,width=.15]"<<endl;
		}
		graphVizGetIds(nodePtr->right,VizOut);
		if(!nodePtr->right){
			NullCount++;
			VizOut<<"nnode"<<NullCount<<"[label=\"X\",shape=point,width=.15]"<<endl;

		}
	}
}

//************************************************************************
// This method is partnered with the above method, but on this pass it
// writes out the actual data from each node.
// Don't worry about what this method and the above method do, just
// use the output as your told:)
//************************************************************************
void avlTree::graphVizMakeConnections(nodes *nodePtr,ofstream &VizOut){
	static int NullCount=0;
	if(nodePtr){
		graphVizMakeConnections(nodePtr->left,VizOut);
		if(nodePtr->left)
			VizOut<<"node"<<nodePtr->value<<"->"<<"node"<<nodePtr->left->value<<endl;
		else{
			NullCount++;
			VizOut<<"node"<<nodePtr->value<<"->"<<"nnode"<<NullCount<<endl;
		}

		if(nodePtr->right)
			VizOut<<"node"<<nodePtr->value<<"->"<<"node"<<nodePtr->right->value<<endl;
		else{
			NullCount++;
			VizOut<<"node"<<nodePtr->value<<"->"<<"nnode"<<NullCount<<endl;
		}

		graphVizMakeConnections(nodePtr->right,VizOut);

	}
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void avlTree::graphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename);
	graphVizGetIds(root,VizOut);
	graphVizMakeConnections(root,VizOut);
	VizOut.close();

}

//************************************************************************
// Method Name: doDumpTree
//
// Private
//
// Purpose: Private method to show the basic pointer structure of the tree.
//          Initially written to help with debugging.
//
// Arguments: address of a node
//
// Returns: void
// Outputs: tree information
//*************************************************************************
void avlTree::doDumpTree(nodes *nodePtr)
{
	if(nodePtr){
		cout<<"Add:    "<<nodePtr<<"\n"
			<<"Parent->"<<nodePtr->parent<<"\n"
			<<"Val:    "<<nodePtr->value<<"\n"
			<<"Avl:    "<<nodePtr->avlValue<<"\n"
			<<"Left->  "<<nodePtr->left<<"\n"
			<<"Right-> "<<nodePtr->right<<"\n\n";

		doDumpTree(nodePtr->left);
		doDumpTree(nodePtr->right);
	}
}

//************************************************************************
// Method Name: leftHeavy,rightHeavy
//
// Private
//
// Purpose: Compares the subtrees of a node to see which is taller
//
// Arguments: address of a node
//
// Returns: true if (left/right) heavy
//
//*************************************************************************
bool avlTree::leftHeavy(nodes *nodePtr)
{
	return height(nodePtr->left)>height(nodePtr->right);
}

bool avlTree::rightHeavy(nodes *nodePtr)
{
	return height(nodePtr->right)>height(nodePtr->left);

}
