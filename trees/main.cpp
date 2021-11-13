#include <iostream>
using namespace std;

#define SPACE 8

class Node {
  public:  
  Node *left;
  Node *right;
  int value;  
    Node (int value) {
      this->left = NULL;
      this->right = NULL;
      this->value = value;
    }
};

class BinarySearchTree {
  public:
    Node *root;
    BinarySearchTree () {
      this->root = NULL;
    }
    void insert (int value);
    bool lookup (int value);
    void display (Node *currNode, int space);
    void remove (int value);
};

void BinarySearchTree::insert(int value) {
  Node *newNode = new Node (value);
  if (this->root == NULL) {
    this->root = newNode;
  }
  else {
    Node *currNode = this->root;
    while (true) {
      if (value < currNode->value) {
        if (!currNode->left) {
          currNode->left = newNode;
          return;
        }
        currNode = currNode->left;
      }
      else {
        if (!currNode->right) {
          currNode->right = newNode;
          return;
        }
        currNode = currNode->right;
      }
    }
  }
}

bool BinarySearchTree::lookup(int value) {
  if (this->root) {
    Node *currNode = this->root;

    while (currNode) {
      if (value < currNode->value) {
        currNode = currNode->left;
      }
      else if (value > currNode->value) {
        currNode = currNode->right;
      }
      else {
          return true;
      }
    }
  }
  return false;  
}

void BinarySearchTree::display(Node *currNode, int space) {

    if (currNode == NULL)
      return;
    space += SPACE;
    display(currNode->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
      cout << " "; 
    cout <<currNode->value << "\n";
    display(currNode->left, space);
    
}

void BinarySearchTree::remove(int value) {

  if (this->root) {
    Node *currNode = this->root;
    Node *parentNode = NULL;
    while (currNode) {
      
      if (value < currNode->value) {
        parentNode = currNode;
        currNode = currNode->left;
      }
      else if (value > currNode->value) {
        parentNode = currNode;
        currNode = currNode->right;
      }
      else {
        // Delete leaf node
        if ((!currNode->left) && (!currNode->right)) {
          if (currNode == parentNode->left){
            parentNode->left = NULL;
          }
          else {
            parentNode->right = NULL;
          }
          return;
        }
        //delete parent node which has one child
        else if ((!currNode->left) || (!currNode->right)) {
          if (currNode == parentNode->left){
            if (currNode->left){
              parentNode->left = currNode->left;
            }
            else {
              parentNode->left = currNode->right;
            }
          }
          else {
            if (currNode->left){
              parentNode->right = currNode->left;
            }
            else {
              parentNode->right = currNode->right;
            }
          }
          return;
        }
        //delete parent node which has two child        
        else {
          Node *temp = currNode->right;
          if (temp->left == NULL && temp->right == NULL)
          {
              currNode->value = temp->value;
              currNode->right = NULL;
              return;
          }
          else if (temp->left == NULL && temp->right != NULL)
          {
              currNode->value = temp->value;
              currNode->right = temp->right;
              return;
          }
          while (temp->left != NULL)
          {
           
              parentNode = temp;
              temp = temp->left;
          }
          currNode->value = temp->value;
          parentNode->left = NULL;
          return;
        }
      }
    }
  }
}

int main() {
  BinarySearchTree myBst;
  myBst.insert(41);
  myBst.insert(20);
  myBst.insert(11);
  myBst.insert(29);
  myBst.insert(32);
  myBst.insert(65);
  myBst.insert(50);
  myBst.insert(91);
  myBst.insert(72);
  myBst.insert(99);
  myBst.insert(5);
  myBst.insert(19);
  myBst.insert(75);
  myBst.insert(26);
  myBst.insert(55);
  /*cout<<endl;
  cout<<"61 : "<<myBst.lookup(61)<<endl;
  cout<<"9 : "<<myBst.lookup(9)<<endl;
  cout<<"55 : "<<myBst.lookup(55)<<endl;
  cout<<"0 : "<<myBst.lookup(0)<<endl;
  cout<<"111 : "<<myBst.lookup(111)<<endl;*/
  cout<<endl<<endl;
  myBst.display(myBst.root, 3);  
  myBst.remove(50);
  cout<<endl<<endl;
  myBst.display(myBst.root, 3);
  myBst.remove(29);
  cout<<endl<<endl;
  myBst.display(myBst.root, 3);  
  myBst.remove(65);
  cout<<endl<<endl;
  myBst.display(myBst.root, 3);    
} 