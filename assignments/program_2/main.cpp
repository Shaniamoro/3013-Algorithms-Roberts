///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Program_2
// Files:            main.cpp , BSTree.cpp, BSTree.h
// Semester:         Spring 2018
//
// Author:           Shania Roberts 
// Mentions: 		     Code base provided in class 
// Email:            shaniamoro@gmail.com
// Description:		   This program deletes the nodes in a BST for three cases
//                     (Case 1: 0 Children , Case 2: 1 Child, Case 3: 2 Children )
//       
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h"
using namespace std;


int main()
{
	srand(2342);

	BSTree B;

	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");


	while (B.top()) {
		cout << "removing: " << B.top() << endl;
		B.deleteNode(B.top());
		B.printLevelOrder();
	}
	//B.deleteNode(38);
	//B.deleteNode(43);

	/*B.deleteNode(3);
	B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);*/
	B.printLevelOrder();
	B.GraphVizOut("after.txt");
	system("PAUSE");
	return 0;


}
