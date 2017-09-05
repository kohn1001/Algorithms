#include <iostream>
#include <string>
#include <vector>
#include <map>
/*

Find the logest sequence the objects are differ by one:
[1,1,1,0,0,2,2,2]

*/
using namespace std;

int getLongestSeq(vector<int> &a)
{
	int maxSeq = 0;
	map<int, int> hist;

	for (auto &i : a) {
		if(hist.find(i) == hist.end()) {
			hist[i] = 1;
		}
		else {
			hist[i]++;
		}
	}

	int prevObjectCount = 0;
	for (auto &h : hist) {
		if (prevObjectCount == 0) {
			prevObjectCount = h.second;
			maxSeq = prevObjectCount;
			continue;
		}
		maxSeq = max(maxSeq, prevObjectCount + h.second);
		prevObjectCount = h.second;
	}
	return maxSeq;
}

int main()
{
	vector<int> a = {1, 1, 1, 0, 0, 2, 2, 2,};

	cout << "longest Subseq is: " << getLongestSeq(a) << endl;
	return 0;
}
