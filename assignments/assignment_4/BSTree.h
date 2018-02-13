#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
class BSTree {
private:
	node * root;
	int count(node *root);
	void insert(node *&root, node *&temp);
	void print_node(node *n, string label);
	node *minValueNode(node *root);
	node *deleteNode(node *&root, int key);
	int height(node *root);
	void printGivenLevel(node *root, int level);
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);
public:

	BSTree() { root = NULL; }
	void insert(int x);
	void deleteNode(int key);
	void minValue();
	int height(int key);
	int top();
	void printLevelOrder();
	void GraphVizOut(string filename);
};
