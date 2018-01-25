///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Program_1
// Files:            main.cpp
// Semester:         Spring 2018
//
// Author:           Shania Roberts 
// Mentions: 		 Code base provided in class 
// Email:            shaniamoro@gmail.com
// Description:		 This program uses a custom liked list [orderedSert] which 
//					 accepts random integers and also sorts them in ascending 
//					 order when they are added to the list.
//       
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node{
  int data;
  node* next;
};

//Creats acustom linked list class
class intLinkedList{
  private:
  node* Head;
  public:
  intLinkedList(){
    Head = NULL;
  }
    void objectSert(int x){
      //Empty list case 
      if (!Head) {
        //create the head node
        Head = new node; 
        //assign the value
        Head->data = x;
        Head->next = NULL;
        //Non Empty list 
       }else {
          node* T =new node;
          T->data = x;
          //Checks if inserted item is less than the first element in the list 
          if(T->data < Head->data) {
            //Assigns inserted item at front of the list 
            T->next = Head;
            Head = T;
          }else{
            //Variable used to traverse the list
            node* traverse = Head; 
            /*Goes through the list and ensures that the inserted element 
            is placed in the right location. */
            while (traverse->next != NULL && traverse->next->data < T->data) {
               traverse= traverse->next;
            }
            //updates the current node during traversal
            T->next =traverse->next;
            traverse->next=T;
          }
       }
    }
  
  void print(){
    node* p = Head;
    while(p){
      cout<<p->data<<endl;
      p = p->next;
    }
  }
};

int main() {
  // seed random number generator
  srand(8734587);
  
  // declare instance of intLinkedList turning
  // a class definition into an "object"
  intLinkedList mylist;
  
  //loops to insert 10 random numbers into the list 
  for (int i=0; i<10;i++){
    mylist.objectSert(rand()%100);
  }
  
  //Prints the list
  mylist.print();

  system("pause");
}