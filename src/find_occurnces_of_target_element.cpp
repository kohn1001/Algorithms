// Given an array count the number of times a given target element occurs in the array
//Am I allowed to use additional space: 
/*
arr = [ 1, 2, 1, -1 ,3, 11]
        0  1  2    3   4    5   6  7
arr = [-1, 3, 12, 12, 12, 12, 13, 14]

index  left  cnt

  3     2     0
              1
              2
  4      1    3
  5      0      4
    
 */ 

//arr = [11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13]
//in our example if x was 1, then res was 2
//in our example if x was 12, then res was 3
//I getting the index in case the element is there else -1
// 2 binary seach
// 1st find left index -- log n
// 2nd find right index -- log n
// return differe
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int binarySearch(std::vector<int> &a, int x)
{
  int start = 0, end = a.size()-1;
  while (start <= end) {
    int mid = start +(end-start)/2;
    if(a[mid] == x) {
      return mid;
    }
    else if( x > a[mid] ) {
      start = mid + 1;
    }
    else {
      end = mid -1;
    }
   
  }
  return -1;
}

int getNumOfOccurs(std::vector<int> &a, int x)
{
  int cnt=0;
  if (a.size() == 0) {
    return 0;
  }
  std::sort(a.begin(), a.end());
  
  int index = binarySearch(a, x);
  if( index == -1) { return 0; }
  auto lb = std::lower_bound(a.begin(), a.end(), x);
  auto upper = std::upper_bound(a.begin(), a.end(), x);
  auto diffR = a.end() - upper;
  auto diffL = lb - a.begin();
  cnt = a.size() - (diffR + diffL);
  
  return cnt;
}

#include <iostream>

// To execute C++, please define "int main()"
int main() {
  //auto words = { "Hello, ", "World!", "\n" };
  std::vector<int> a = {0, 0, -1, 1, 1, 12, 12, 12, 13, 13, 13};
  int i = 0;
  std::cout << i << " in the array occurs: " << getNumOfOccurs(a, i) << std::endl;

  return 0;
}

