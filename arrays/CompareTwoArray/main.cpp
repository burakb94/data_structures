#include <iostream>
#include<vector>
#include<map>

using namespace std;

  bool CompareTwoArray(vector<char> one, vector<char> two){

    for (auto items1 : one){
      for (auto items2 : two){
        if (items1 == items2)
          return true;
      }
    }
    return false;
  }

  bool BetterCompareTwoArray(vector<char> one, vector<char> two){
    map<char,bool> comp;
    for (auto items1 : one){
      if(!comp[one[items1]]){
        comp.insert ({items1, true});
      }
    }

    for (auto items2 : two){
      if (comp[items2])
        return true;
    }    
    return false;
  }

int main() {
  const vector<char> v1 = {'c', 'b', 'a'};
  const vector<char> v2 = {'x', 'y', 'z', 'q'};
  const vector<char> v3 = {'1', 's', 'h', 'd'};
  const vector<char> v4 = {'h', 'k', 'p'};  

  cout<<CompareTwoArray(v1, v2)<<"\n";
  cout<<CompareTwoArray(v3, v4)<<"\n";
  cout<<BetterCompareTwoArray(v1, v2)<<"\n";
  cout<<BetterCompareTwoArray(v3, v4);  
}

