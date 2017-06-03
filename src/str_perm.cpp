#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getPermut(string str)
{
	vector<string> permutations;
	cout << "this is str: " << str << endl;

	if(str.size() == 0) {
		permutations.emplace_back("");
		return permutations;
	}
	string s; 
	s += str[0];

	vector<string> subPerm   = getPermut(str.substr(1, str.size()-1));

	for (auto &p : subPerm) {
		if (p.size() == 0) {
			permutations.emplace_back(s);
		}
		else {
			for (int i=0; i <= p.size(); ++i) {
				permutations.emplace_back(p.substr(0, i) + s + p.substr(i, p.size()-i));
			}
		}
	}
	return permutations;
}

int main()
{
	cout << "this is a permutation test \n";
	vector<string> res = getPermut("abc");

	for (auto &i : res) {
		cout << i << endl;
	}
	return 0;
}
