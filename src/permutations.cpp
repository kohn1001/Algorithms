#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Permutations {
	public:
		Permutations (const string &str) : in(str), used(DictSize, false) {}
		void permute();

	private:
		string in;
		vector<bool> used;
		static const int DictSize;
		string out;
};

const int Permutations::DictSize = 256;
void Permutations::permute()
{
	if (out.size() == in.size()) {
		cout << out << endl;
	}

	for (int i=0; i < in.size(); ++i) {
		if (used[in[i]]) {
			continue;
		}

		out.append(1, in[i]);
		used[in[i]] = true;
		permute();
	//	out = out.substr(0, out.size()-1);
		out.pop_back();
		used[in[i]] = false;
	}
}

int main()
{
	cout << "To test string permutations, type in the string to permute: " << endl;
	string s;
	cin >> s;
	cout << endl;
	Permutations per(s);
	per.permute();
	cout << endl;
	//vector<string> res = getPermut("abc");
/*
	for (auto &i : res) {
		cout << i << endl;
	}
	*/
	return 0;
}
