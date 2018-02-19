#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_set>


using namespace std;
using ii = pair<int, int>;
using bfP = pair<int, ii>; // { dist, {i, j}}


namespace my_bfs {


/*
 *              |  i-1, j  |
 *      -------------------------------
 *      i, j-1  |   i, j   |  i, j+1  |
 *      -------------------------------
 *              | i+1, j   |          |
 *
 */

class Bfs {

	static const vector<int> ncol; // = {  0, 1, 0, -1 };
	static const vector<int> nrow; // = { -1, 0, 1,  0 };

	public:
		Bfs(vector<vector<int>> &mat, int rowsNum, int colsNum) :  
			mat(mat), m(rowsNum), n(colsNum), visited(m, vector<bool>(n, false))  
		{
		}	
		int run (ii src, ii dst);
		bool isValid (ii ij) {
				int i = ij.first;
				int j = ij.second;
				/* the ordere of the validation below is IMPORTANT! do not change it */  
				if ( i < 0 || i > m-1 || j < 0 || j > n-1 || isVisited(ij) || !mat[i][j]) {
					return false;
				}
			return true;
		}

		ii nextStep(int i, ii ij) {
			ii next{ij.first +nrow[i], ij.second + ncol[i]};
			return next;;
		}
		void markVisited(ii ij);
		bool isVisited(ii ij);

	private:
		int n;
		int m;
		vector<vector<bool>> visited;
		queue<bfP> q;
		vector<vector<int>> &mat;
};

void Bfs::markVisited(ii ij)
{
	visited[ij.first][ij.second] = true;
}

bool Bfs::isVisited(ii ij) {
	return visited[ij.first][ij.second];
}

int Bfs::run (ii src, ii dst) {
	//if (mat.size() == 0) { return 0; }
	for (int i=0; i < m; ++i ) {
		//if (mat[i].size() < n ) { return -1;}
	}

	q.push({0, src});
	visited[src.first][src.second] = true;
	while (!q.empty()) {
		auto curr = q.front(); q.pop(); 
		int d = curr.first;
		for (int i=0; i<nrow.size(); ++i) {
			auto next = nextStep(i, curr.second);
			if (next == dst) {
				return d+1; //got the distance we want 
			}
			if (isValid(next)) {
				q.push({d+1, next});
				markVisited(next);
			}
		}
	}
	return -1;
}


} // end of my_bfs amespace 

const vector<int> my_bfs::Bfs::nrow = { -1, 0, 1,  0 };
const vector<int> my_bfs::Bfs::ncol = { -1, 0, 1,  0 };

int main()
{
		
	vector<vector<int>> mat = { 
								{ 1, 0, 0, 0, 1, 1, 1, 0 },
								{ 1, 0, 1, 0, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 0, 0, 1 },
								{ 0, 0, 0, 0, 0, 0, 1, 1 },
								{ 0, 0, 1, 1, 1, 0, 0, 1 },
								{ 0, 0, 1, 0, 1, 0, 0 ,1 }, 
								{ 0, 0, 1, 1, 1, 0, 0, 1 },
								{ 0, 0 ,0, 1, 1, 1, 1, 1 } 
								
							   };

	my_bfs::Bfs bfs (mat,8, 8);
	cout << bfs.run(ii(0,0), ii(mat.size()-1, mat[0].size()-1)) << endl;
//	cout << bfs.run(mat, src, dst) << endl;
	return 0;
}



