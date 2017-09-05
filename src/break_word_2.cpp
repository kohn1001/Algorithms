#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isInDict(string str)
{
	static unordered_set<string> dict = { "ilo", "ilove", "love","harry", "potter" };
	if (dict.find(str) == dict.end()) { return false; }
	return true;
}


bool break_word (string str, vector<string> &res)
{
	if (str.empty()) { 
		return true;
	}
	for (int i=0; i <= str.size(); ++i) {
		string new_str = str.substr(0, i);
		cout << "new_str is : " << new_str << endl;
		if (isInDict(new_str)) { 
			res.emplace_back(new_str);
			if(break_word(str.substr(i, str.size()-i), res)) {
				return true;
			}
			else {
				auto to_del = find(res.begin(), res.end(), new_str);
				res.erase(to_del);
			}
		}
	}
	return false;
}

int main()
{
	vector<string> res;
	break_word("iloveharrypotter", res);
	for (auto &r : res) {
		cout << r << endl;
	}

	return 0;
}
/*output is:
 * In the example we see that although the algo will firt try to break the word with "ilo" eventually fails and then
 * we get the output below:
ilove
harry
potter
 *
 *
 *
 */
