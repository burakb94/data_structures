#include <iostream>
// bits/stdc is imported for algorithm.h->reverse function
#include <bits/stdc++.h>

using namespace std;

string ReverseString (string inputStr) {
  string retStr;
  for (int i=inputStr.length(); i>=0; i--) {
    retStr.push_back(inputStr[i]);
  }

  return retStr;
}

int main() {
  
  string name = "Burak Biyikli";
  string anotherName = "Another Name";

  //reversing with our own function
  cout<<ReverseString(name)<<"\n";

  //all thing can be done with a built-in function
  reverse(name.begin(), name.end());
  cout<<name<<"\n";

  //or with constructor of string
  string rev(anotherName.rbegin(), anotherName.rend());
  cout<<rev<<"\n";
}