#include <iostream>

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

class Queue {
  Node *head;
  Node *tail;
  int length;  
  
  public:
    Queue () {
      this->head = NULL;
      this->tail = NULL;
      this->length = 0;
    }  
    void peek ();
    void enqueue (string data);
    void dequeue ();
    bool isEmpty ();
    void display ();
};

void Queue::peek() {
  if (!isEmpty()) {
    cout<<this->head->data<<"\n";
  }
  else {
    cout<<"Head of queue is NULL\n";
  }
}

void Queue::enqueue(string data) {
  Node *newNode = new Node (data);
  if (isEmpty()) {
    this->head = newNode;
    this->tail = newNode;
  }
  else {
    this->tail->next = newNode;
    this->tail = newNode;
  }
  this->length++;
}

void Queue::dequeue() {
  if (isEmpty()) {
    cout<<"Queue is empty\n";
  }
  else {
    if (this->head == this->tail) {
      this->tail = NULL;
    }   
    this->head = this->head->next;
    this->length--;
  }
}

bool Queue::isEmpty() {
  return this->length == 0 ? true : false;
}

void Queue::display() {
  Node *tempNode = this->head;
  while (tempNode) {
    cout<<tempNode->data<<"->";
    tempNode = tempNode->next;
  }
  cout<<endl;
}

int main() {
  Queue myQueue;
  myQueue.peek();  
  myQueue.enqueue("first");
  myQueue.enqueue("second");
  myQueue.enqueue("third");
  myQueue.peek();
  myQueue.display();
  myQueue.dequeue();
  myQueue.dequeue();
  //myQueue.dequeue();
  //myQueue.dequeue();
  myQueue.enqueue("after");
  myQueue.display();

  return 0;
} 