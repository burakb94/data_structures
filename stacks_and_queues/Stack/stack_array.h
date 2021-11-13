#include <iostream>
#include <vector>

using namespace std;

class MyStackUsingArray {
  public:
    vector<string> arr;
    MyStackUsingArray (){
      this->arr = {};
    }
    void peek ();
    void push (string data);
    void pop ();
    void display ();
};

void MyStackUsingArray::peek() {
  cout<<arr[arr.size()-1]<<"\n";
}

void MyStackUsingArray::push(string data) {
  arr.push_back (data);
}

void MyStackUsingArray::pop() {
  if (arr.size()) {
    arr.pop_back();
  }
  else {
    cout<<"Stack is empty\n";
  }
}

void MyStackUsingArray::display() {
  for (int i=0; i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}
