#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
  public:
    stack<int> stackPush, stackPop;
    MyQueue() {
        
    }
    
    void push(int x) {
      stackPush.push(x);
    }
    
    void pop() {
      peek();
      stackPop.pop();       
    }
    
    void peek() {
      if (stackPop.empty()) {
          while (stackPush.size()) {
              stackPop.push(stackPush.top());
              stackPush.pop();
          }
      }    
    }
    
    bool empty() {
      return (stackPush.empty() && stackPop.empty());
    }

    void display() {
      if (stackPop.empty()){
        cout<<endl;
        return;
      }

      int x = stackPop.top();
      stackPop.pop();
      display();  
      cout<<x<<" ";
      stackPop.push(x);

    }
};

int main() {
  MyQueue newQueue;
  newQueue.push(1);
  newQueue.push(2);
  newQueue.push(3);
  newQueue.push(4);
  newQueue.pop();
  newQueue.display();
  newQueue.pop();
  newQueue.display();  

  return 0;
} 