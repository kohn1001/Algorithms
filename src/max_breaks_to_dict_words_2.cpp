#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;
const int AB_LEN = 26;

static const unordered_set<string> dictionary {"dog", "cat", "rat"};

struct Node {
	Node (): isLeaf(false),
			 children(AB_LEN, nullptr)
	{}
	bool isLeaf;
	vector<Node*> children;	
	~Node () {
		for (auto &n : children) {
			releaseMem(n);
		}
	}
	void releaseMem(Node *n) {
		if (n) {
			for (auto &i : n->children) {
				releaseMem(i);
			}
			delete(n);
		}		
	}
};

bool isInDict(string str)
{
	if (dictionary.find(str) != dictionary.end()) { return true; }
	return false;
}

void insertToTrie(Node *t, string s)
{
	for (auto &is : s) {
		int os = is - 'a';
		if (t->children[os] == nullptr) {
			t->children[os] = new Node();
		}
		t = t->children[os];
	}
	t->isLeaf = true;
}



void printTrie(Node *t, string word)
{
	if (t && t->isLeaf) {
		cout << word << endl;
	}
	for (int i=0; i < AB_LEN; ++i) {
		string s{ char(i +'a')};
		if (t->children[i]) {
			printTrie(t->children[i], word + s);
		}
	}
}

Node *getTrie(string w)
{
	Node *n = new Node();
	for (int i=0; i < w.size(); ++i) {
		string suff = string(w.begin() + i, w.end());
		cout << "test getTrie: " << suff << endl;
		insertToTrie(n, suff);
	}
	return n;
}
void getCurrComb (Node *t, string currW, int &cnt)
{
	if (isInDict(currW)) {
		cout << "in dict " << currW << endl;
		++cnt;
		if(t->isLeaf) { ++cnt; }
	}
	for (int i=0; i < AB_LEN; ++i) {
		if (t->children[i]) {
			string s {char(i+'a')};
			getCurrComb(t->children[i], currW + s, cnt);
		}
	}
}

string getMaxCombWord ( vector<string> &words, int &maxCnt)
{
//	int maxCnt = 0;
	string word;
	Node *t = nullptr;
	for (auto &w : words) {
		t = getTrie(w);
		int currCnt = 0;
		getCurrComb(t, "", currCnt);
		if (currCnt > maxCnt) {
			maxCnt = currCnt;
			word = w;
		}
	}
	return word;
}

int main()
{
	vector<string> words { "dogcat", "dog", "cat", "dogcatrat", "dogcatraatratdog"};
	//Node *n = getTrie (str);
	int maxCnt = 0;
	string res = getMaxCombWord(words, maxCnt);
	cout << "res: " << res << endl;
	cout << "max cnt: " << maxCnt << endl;
	return 0;
}

