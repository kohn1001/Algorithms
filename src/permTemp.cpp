#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>



using namespace std;
template <typename T>
class permut {
	public:
		permut (T str) 
			: in (str),
			  used (str.size(), false)
		{}
		void getPerm();
		void print(vector<T> &t);
	private:
		T in;
		vector<T> out;
		vector<bool> used;

};

template <typename T>
void permut<T>::print(vector<T> &t)
{
	for (auto & curr : t) {
		for (auto &i : curr) {
			cout << i << " " ;
		}
		cout << " ";
	}
	cout << endl;
}

template <typename T>
void permut<T>::getPerm()
{
	if (out.size() == in.size()) {
		print(out);
		return;
	}
	for (int i=0; i < in.size(); ++i) {
		if (!used[i]) {
			T toPush {in[i]};
			out.emplace_back(toPush);
//			out.emplace_back(in[i]);
			used[i] = true;
			getPerm();
			out.pop_back();
			used[i] = false;
		}
	}
}


int main()
{
	permut<string> p ("abcd");
	p.getPerm();
	vector<string> vs{"boola" , "natty", "kohn", "adi"};
//	string s1 = "boola";
//	vs.emplace_back(s1);

	permut<vector<string>> pvs (vs);
	pvs.getPerm();
	return 0;
}

