#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

struct nodes{
	string value;
	nodes *left;
	nodes *right;
	nodes *parent;
	int avlValue;
	nodes(string word){
		value = word;
		left = right = parent = NULL;
		avlValue = 0;
	}
};

class avlTree{

private:
	nodes *root;
	bool rightHeavy(nodes *);
	bool leftHeavy(nodes *);
	void insert(nodes *&, nodes *&);
	void inorder(nodes *);
	void preorder(nodes *);
	void postorder(nodes *);
	nodes* remove(nodes*& , string );
	nodes* predSuccessor(nodes*);
	void printNode(nodes *, string );
	int  height(nodes *);
	void computeAvlValues(nodes *&);
	void rotateLeft(nodes *&);
	void rotateRight(nodes *&);
	int  avlValue(nodes *);

public:
	avlTree();
	~avlTree();
	void doDumpTree(nodes *);
	void dumpTree(){cout<<"---------------------------------"<<endl;
		cout<<"Root:   "<<root<<"\n";
		doDumpTree(root);
	};
	void insert(string);
	void showInorder(){inorder(root);};
	void showPreorder(){preorder(root);};
	void showPostorder(){postorder(root);};
	bool search(string);
	int lookup(nodes *, string, int);
	nodes* getRoot();
	void remove(string word){root = remove(root,word);};
	int  treeHeight();
	void graphVizGetIds(nodes *,ofstream &);
	void graphVizMakeConnections(nodes *,ofstream &);
	void graphVizOut(string );
};

