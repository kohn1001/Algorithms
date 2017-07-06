
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
/*
O(1) amortized 
vec
1. case insensitive - trasform to lower case
2. remove punctuation, i.e: ".", "!" - everyting that is not 
    a letter
3. itterate of the document and count the occurences 
 ["practice", "3"]
4. sort it according to the # of occurences 

map: {practice - > 3,  perfect -> 2....}
5 when finish -> push it to the result vector.
6 create my own cmp function which sort it according to the second element

*/

bool cmp (const vector<string> &a, const vector<string> &b) {
  return a[1] > b[1];
}

vector<vector<string>> wordCountEngine(string &document) {
  
  vector<vector<string>> res;
  if (document.size() == 0) return res;
  transform (document.begin(), document.end(), document.begin(), ::tolower);
  string new_doc;
  for (auto &d : document) {
    if (!ispunct(d)) {
		new_doc += d;
    }
  }
 

  map<string, int> hist;
  stringstream ss (new_doc);
  string d;

  while (ss >> d) {
	  hist[d]++;
  }

  for (auto &h :hist) {
    vector<string> vs;
    vs.push_back(h.first); vs.push_back(to_string(h.second));
    res.push_back(vs);
  }
  
  sort(res.begin(), res.end(), cmp);
  return res;
}



int main() {
    
    string doc = "Practice makes perfect. you'll only\
                    get Perfect by practice. just practice!";
    
    vector<vector<string>> res = wordCountEngine(doc);
    for (auto &s : res) {
      for (auto &i : s) {
          cout << i << " ";
      }
      cout << endl;
  }
    return 0;
}

/* 
Your last C# code is saved below:
using System;



public class Test
{
    public static void Main()
    {
        Console.WriteLine("Hello");
    }
}
 */
