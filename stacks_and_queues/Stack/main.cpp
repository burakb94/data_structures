#include "stack_array.h"
#include "stack_linked_list.h"

int main() {
  MyStack newStack;
  newStack.push("first");
  newStack.push("second");
  newStack.peek();
  newStack.push("third");
  newStack.display();
  newStack.pop();
  newStack.display();
  newStack.pop();
  newStack.display();  
  newStack.pop();
  newStack.display();    
  newStack.pop();
  newStack.display();    
  newStack.push("here");
  newStack.peek();

  MyStackUsingArray anotherStack;
  anotherStack.push("another");
  anotherStack.push("stack");
  anotherStack.peek();
  anotherStack.push("described");
  anotherStack.display();
  anotherStack.pop();
  anotherStack.display();
  anotherStack.pop();    
  anotherStack.display();

  return 0;
}