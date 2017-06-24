#include <iostream>

#include <vector>
#include <string>
#include <ctime>



using namespace std;

void shuffle(vector<int> &a)
{
	for (auto &i : a) {
		cout << i << endl;
	}
	srand((unsigned)time(0));
	for (int i=a.size()-1; i >= 0; --i) {
		int r = (int)rand();
		r %= (i+1);
		std::swap(a[r], a[i]);
	}
}

int main()
{
	vector<int> a = {0, 5, 13, 1, 17, 9};
	shuffle(a);
	for (auto &i : a) {
		cout << i << endl;
	}

	return 0;
}
