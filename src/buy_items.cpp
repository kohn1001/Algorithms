#include <iostream>
#include <vector>
#include <string>
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
	findCreditMatch(itemPrices, credit, 0, res, 0);
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

