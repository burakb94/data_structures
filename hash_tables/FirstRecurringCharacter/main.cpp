//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined

#include <iostream>
#include <vector>
#include <map>

using namespace std;

string FindRecurringChar (const vector<int> input){
  map<int, bool> myMap;
  
  for (auto val : input) {
    if (!myMap[val]){
      myMap[val] = true;
    }
    else {
      return to_string(val);
    }
  }
  return "undefined";
}

int main() {

  vector<int> vector1 = {2,5,1,2,3,5,1,2,4};
  vector<int> vector2 = {2,1,1,2,3,5,1,2,4};
  vector<int> vector3 = {2,3,4,5};

  cout<<FindRecurringChar (vector1)<<endl;
  cout<<FindRecurringChar (vector2)<<endl;
  cout<<FindRecurringChar (vector3)<<endl;

}