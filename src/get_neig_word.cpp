#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#define eb emplace_back
using namespace std;

bool isWord(string &str)
{
	if(str == "hello") {
		return true;
	}
	return false;
}

vector<string> getAllWordsPerm (vector<string> allWords, set<string> &exist, int wordSize)
{
	vector<string> res;
	if (allWords.size() == 0) {
		res.eb("");
		return res;
	}
	string vs = allWords[allWords.size()-1];
	allWords.pop_back();
	vector<string> rem = getAllWordsPerm(allWords, exist, wordSize);
	
	for (auto &r : rem) {
		for (auto &is : vs) {
			string rs = r + is;
			if (rs.size() == wordSize && isWord(rs)) {
				if(exist.find(rs) == exist.end()) {
					res.eb(rs);	
					exist.emplace(rs);
				}
			}
			else if(rs.size() < wordSize) {
				res.eb(rs);
			}
		}
	}
	return res;
}

vector<string> getAllWordsPerm (vector<string> allWords, int n) {
	set<string> s;

	vector<string> res = getAllWordsPerm(allWords, s, n);
	return res;
}
int main()
{

	vector<string> allWords = { "ghj", "wer", "jkl", "jkl", "iop"};
	vector<string> res = getAllWordsPerm(allWords, 5);
	for (auto &ir : res) {
		cout << ir << endl;
	}
	//cout << "longest Subseq is: " << getLongestSeq(a) << endl;
	return 0;
}
