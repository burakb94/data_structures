//Create a linked list which has append,
//prepend, insert, remove, reverse operations

#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:

    int value;
    Node* next;  
      Node (int value) {
        this->value = value;
        this->next = NULL;
      }
};

class LinkedList {

  Node *head;
  Node *tail;
  int length;

  public:
    LinkedList () {
      this->head = NULL;
      this->tail = NULL;
      this->length = 0;
    }
    void append (int value);
    void prepend (int value);
    void insert (int value, int index);
    void remove (int index);
    void reverse ();
    void display ();
    Node* traverse (int index);
};

void LinkedList::append(int value) {
  //append function inserts the value to the end of list
  Node *newNode = new Node (value);

  if (this->head == NULL) {
    this->head = newNode;
    this->tail = newNode;
    this->length++;
  }
  else {
    this->tail->next = newNode;
    this->tail = newNode;
    this->length++;
  }
}

void LinkedList::prepend(int value) {
  //prepend function inserts the value to the start of list
  Node *newNode = new Node (value);

  if (this->head == NULL) {
    this->head = newNode;
    this->tail = newNode;
    this->length++;
  }
  else {  
    newNode->next = this->head;
    this->head = newNode;
    this->length++;
  }
}

void LinkedList::insert(int value, int index) {
  if (index >= this->length) {
    append(value);
  }
  else if (index == 0) {
    prepend(value);
  }
  else {
    Node *newNode = new Node (value);
    Node *currNode = traverse(index-1);

    newNode->next = currNode->next;
    currNode->next = newNode;
    this->length++;
  }
}

void LinkedList::remove(int index) {
  if (index > this->length) {
    cout<<"Invalid index"<<"\n";
    return;
  }
   Node *currNode = traverse(index-1);

   currNode->next = currNode->next->next;
   this->length--;
}

void LinkedList::reverse() {
  Node *first = this->head;
  this->tail = this->head;
  Node *second = first->next;

  while (second != NULL) {
      Node *tmp = second->next;
      second->next = first;
      first = second;
      second = tmp;
  }

  this->head->next = NULL;
  this->head = first;
}

void LinkedList::display() {
  Node *curr = this->head;
  while (curr != NULL) {
    cout<<curr->value<<" ";
    curr = curr->next;
  }
  cout<<"\n";
}

Node* LinkedList::traverse(int index) {
  Node* curr;
  curr = this->head;
  for (int i=0; i<index; i++) {
    curr = curr->next;
  }
  return curr;
}

int main() {
  LinkedList myList;

  myList.prepend(8);
  myList.append(5);
  myList.append(16);
  myList.append(25);
  myList.append(39);
  myList.append(61);
  myList.display();
  myList.remove(2);
  myList.display();
  myList.prepend(9);
  myList.display();
  myList.insert(55, 3);
  myList.append(99);
  myList.display();
  myList.reverse();
  myList.display();
  myList.reverse();
  myList.display();  

  return 0;
}