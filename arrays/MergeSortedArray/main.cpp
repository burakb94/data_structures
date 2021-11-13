#include <iostream>
#include <vector>

using namespace std;

//We have two sorted arrays
//We want to merge and sorted them

//Inputs => [0, 3, 4, 31] [4, 6, 30]
//Output => [0, 3, 4, 4, 6, 30, 31]

vector<int> MergeSortedArray (const vector<int> inputOne, const vector<int> inputTwo) {
  vector<int> returnVector;
  int currentIndex1=0, currentIndex2=0;
  int size1=inputOne.size();
  int size2=inputTwo.size();
  if (inputOne.empty()) {
    return inputTwo;
  }
  else if (inputTwo.empty()) {
    return inputOne;
  }
  else {
    while ( (currentIndex1<size1) || (currentIndex2<size2) ) {
      if (!(currentIndex2<size2) || ( (currentIndex1<size1) && (inputOne[currentIndex1] < inputTwo[currentIndex2]) ) ){
        returnVector.push_back(inputOne[currentIndex1++]);
      }
      else {
        returnVector.push_back(inputTwo[currentIndex2++]);
      } 
    }
    return returnVector;
  }
}

int main() {
  vector<int> resultArray;
  resultArray = MergeSortedArray({0, 3, 4, 10, 21, 39, 58, 69}, {4, 6, 8, 55, 61});

  for (auto i : resultArray) {
    cout<<i<<" ";
  }
}