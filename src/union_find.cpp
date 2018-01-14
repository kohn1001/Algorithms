#include <vector>
#include <iostream>

using namespace std;
using vi = vector<int>;

class UnionFind {
	public:
		UnionFind(int N) : p(N,0), rank(N,0) {
			for (int i=0; i<N; ++i) {
				p[i] = i;
			}
		}
		int findSet(int i) {
			return (p[i] == i ? i : (p[i] = findSet(p[i])));
		}
		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i);
				int y = findSet(j);
				if (x < y ) {
					p[j] = x;
				}
				else {
					p[i] = y;
				}
			}
		}

	private:
		vi p, rank;

};

int main()
{
	return 0;
}
