#include <iostream>


#include <vector>

#define eb emplace_back

using namespace std;


vector<int> merge(const vector<int> &l, const vector<int> &r)
{
	vector<int> ans;
	int il=0, ir=0;
	while (il < l.size() && ir < r.size()) {
		if (l[il] <=r[ir]) {
			ans.eb(l[il++]);
		}
		else {
			ans.eb(r[ir++]);
		}
	}
	while (il < l.size()) {
		ans.eb(l[il++]);
	}
	while (ir < r.size()) {
		ans.eb(r[ir++]);
	}
	return ans;
}


vector<int> mergeSort(const vector<int> &a, int l, int r)
{
	vector<int> ans;
	if(l >= r) {
		ans.eb(a[r]);
		return ans;
	}
	int mid = l +(r-l)/2;
	vector<int> la = mergeSort(a, l, mid);
	vector<int> lr = mergeSort(a, mid+1, r);
	ans = merge(la, lr);
	return ans;
}


int main()
{
	vector<int> a = {1, 7, 3, 9, 17, 5, -1};

	vector<int> sorted = mergeSort(a, 0, a.size()-1);
	
	for (auto &i : sorted ) {
		cout << i << endl;
	}
	return 0;

}
