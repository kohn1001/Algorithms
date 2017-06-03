#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#define SUBMIT

using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;
const string file_name = "test.txt";

int main()
{
	int n, k ,q, i;
	ifstream fs(file_name);
	string str;
	if(fs.peek() != EOF) {
		fs >> n >> k >> q;
		vector<int> v;
		for (size_t i = 0; i < n; ++i) {
			int t ;
			fs >> t;
			v.emplace_back(t);	
		}
		
		for(int ik = 0; ik < q; ++ik) {
	//			getline(fs, str);
			fs >> i;
			if(i > n-1) { return -1;}
			int newStart = n - k%n;
			int newIndex = (i+newStart)%n;
			cout << v[newIndex] << endl;
		}	

		//cout << str << endl;
	}
#ifdef SUBMIT

	cin >> n >> k >> q;
	vector<int> v;
	for (size_t i = 0; i < n; ++i) {
		int t ;
		cin >> t;
		v.emplace_back(t);	
	}

/*	
	for (auto &i : v) {

		cout << i << "\t" << endl;
	}
	*/

	for(int ik = 0; ik < q; ++ik) {
		cin >> i;
		if(i > n-1) { return -1;}
		int newIndex = (i+k-1)%n;
	//	cout << "The new index is: " << newIndex << endl;
		
		cout << v[newIndex] << endl;
	}	
#endif
	return 0;
}

