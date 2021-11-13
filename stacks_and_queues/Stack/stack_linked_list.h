#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    Node *next;
    string data;
    Node (string data) {
      this->next = NULL;
      this->data = data;
    }
};

class MyStack {
  Node *top;
  Node *bottom;
  int length;

  public:
    MyStack () {
      this->top = NULL;
      this->bottom = NULL;
      this->length = 0;
    }

    void peek ();
    void push (string data);
    void pop ();
    bool isEmpty ();
    void display ();

};

void MyStack::peek(){
  cout<<this->top->data<<"\n";
}

void MyStack::push(string data) {
  Node *newNode = new Node (data);  
  if (isEmpty()) {
    this->top = newNode;
    this->bottom = newNode;
  }
  else {
    Node *tempNode = this->top;
    this->top = newNode;
    this->top->next = tempNode;
  }
  this->length++;
}

void MyStack::pop() {
  if (!isEmpty()) {
    if (this->top == this->bottom) {
      this->bottom = NULL;
    }
    this->top = this->top->next;
    this->length--;
  }
  else {
    cout<<"Stack is empty\n";
  }
}

bool MyStack::isEmpty() {
  return this->length == 0 ? true : false;
}

void MyStack::display() {
  Node *tempNode = this->top;
  while (tempNode) {
    cout<<tempNode->data<<" ";
    tempNode = tempNode->next;
  }
  cout<<endl;
}