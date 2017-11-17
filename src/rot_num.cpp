#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctype.h>

using namespace std;
/*
 * This is question fron a google interview:
 * Write a function that checks whether a number looks the same when rotated 180 degrees (looked at upside down)
 *
 * The solution below is highly elegant - I haven't come up with it during the interview - only afterwards! :(o
 * The reason that it is so elegant is that it is easily extensible/scalable - if one decide that we want to add more digits that are consider valid
 * only extend the dictionary - you don't have to tounch any other line of code
 *
 *
 */
class RotNum {
	public:
		RotNum() {}
		bool isRot(vector<int> &num);
		bool inDict(int num) {
			if(dict.find(num) == dict.end() || 
				dict.find(num) == dict.end()) {
				return false;
			}
			return true;
		}
		void init()
		{
			dict[1] = 1;
			dict[9] = 6;
			dict[6] = 9;
			dict[8] = 8;
			dict[0] = 0;
		}
	private:
	unordered_map<int, int> dict;
};

bool RotNum::isRot(vector<int> &num)
{
	if (num.size() == 0) { return true; }
	int start = 0, end = num.size()-1;

	while (start <= end) {
		if (!inDict(num[start]) || 
			!inDict(num[end]) ||
			dict[num[start]] != num[end]) {
			return false;
		}
		--end; ++start;
	}
	return true;
}


int main()
{
	RotNum rn;
	rn.init();
	//vector<int> n = {5, 1, 0};
	vector<int> vn ;
	string str;
	cout << "Type in the number you want to check please " << endl;
	int number;
	while (!getline(cin, str)); 
	cout << "The full number is: " << str << endl;
	for (auto i : str) {
		if (!isdigit(i)) { continue; }
		number = i - '0';
		vn.emplace_back(number);
	}
	cout << endl;
	int cnt=1;
	for (auto i : vn) {
		cout << "The number object #" << cnt++ <<  " is: "; 
		cout << i << " " << endl;
	}
	cout << "This is " << (rn.isRot(vn) ? "a Rot num." : "not a Rot num " ) << endl;
	return 0;
}

