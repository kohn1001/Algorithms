#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int findCreditMatch(vector<int> &itemPrices, int credit, int idx, vector<bool> &res, int numOfItem)
{
//	cout << "find credit : item price " << itemPrices[idx] << endl;
//	cout << "credit : " << credit << endl;
//	cout << "idx: " << idx;
//	cout << endl;
	if (credit < 0) {
		return 0;
	}
	
	if(numOfItem > 2) { return 0;}
	if(credit == 0) {
		return 1;
	}
	if(idx > itemPrices.size() ) {
		return 0;
	}
	if(findCreditMatch(itemPrices, credit-itemPrices[idx], idx+1, res, numOfItem+1)) {
		res[idx] = true;
		return 1;
	}
	else {
		res[idx] = false;
//		cout << "item: " << itemPrices[idx] << endl;
		return findCreditMatch(itemPrices, credit, idx+1, res, numOfItem);
	}
}

vector<bool>  getItemList(vector<int> &itemPrices, int credit)
{
	vector<bool> res(itemPrices.size(), false);
	//map<int, bool> mapNum;
	map<int, int> itemSet;
/*
	for (auto i =0; i < itemPrices.size() ; ++i) {
		itemSet.emplace(make_pair(itemPrices[i], i));
	}
*/
	int tofind = 0;
	int matchCnt = 0;
	for (auto i = 0 ; i < itemPrices.size(); ++i) {
/*		if(credit-itemPrices[i] < 0 ) {continue;} */
		if(itemSet.find(credit - itemPrices[i]) != itemSet.end()) { 
			//continue;
			res[i] = true;
			int index = itemSet[credit-itemPrices[i]] ;
			res[itemSet[credit-itemPrices[i]]] = true;
			return res;
		}
		itemSet.emplace(make_pair(credit- itemPrices[i], i));
	}
	return res;
}

int main()
{
	int N;
	int C;
	int l;
	cin >> N;
	for(int j = 0 ; j < N; ++j) {
		cin >> C;
		cin >> l;
		vector<int> pricesItems(l, 0);

		for (int i = 0; i < l; ++i) {
			int price;
			cin >> price;
			pricesItems[i] = price;
/*			cout << "pircesItems[i] " << pricesItems[i]  << " ";
			cout << endl;*/
		}
		
		vector<bool> listOfPurchasedItems = getItemList(pricesItems, C);
		cout << " Case #" << j+1 << ": " ;
		for(int t = 0; t < listOfPurchasedItems.size(); ++t) {
			if(listOfPurchasedItems[t] == true) {
				cout << t+1 << " ";
			}
		}
		
		cout << endl;
	}
	return 0;
}

