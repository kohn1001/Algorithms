//This is an implementation of Binary tree in a vector C++
#include <iostream>
using namespace std;
#include <vector> 
#include <stack>
#include <queue>

int main()
{
	vector<int> v = {3, 9, 8, 4, 0, 1, 7, 15, 18};

	int i=0;
	queue<pair<int, int>> st;	
	//stack<pair<int, int>> st;
	st.push(make_pair(0, v[0]));
	int treeH = 1;
	while (!st.empty()) {
		auto curr = st.front(); st.pop();
		cout << "index: " << curr.first << " value: " << curr.second << endl;
		int leftInd = curr.first << 1 | 1;
		int rightInd = (curr.first+1) << 1;
			
		if(leftInd <= v.size()-1 && leftInd >= 0 ) {
				//cout << "leftInd: " << leftInd << endl;
				//cout << "leftChild: " << v[leftInd] << endl;
				st.push(make_pair(leftInd, v[leftInd]));
		}
		if(rightInd <= v.size()-1 && rightInd >= 0) {
				//cout << "rightInd: " << rightInd << endl;
				//cout << "rightChild: " << v[rightInd] << endl;
				st.push(make_pair(rightInd, v[rightInd]));
		}
	}
		return 0;
}
