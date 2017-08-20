#include <iostream>
#include <vector>

/* you are given tuples of start time, end time and a bandwidth of tv shows,
 * you need to calculate the maximum bandwidth in a given time 
 *
*/
using namespace std;
using ii = pair<int, int>;

/*
 *
 *  create a vector for start time of the tv show coupled with the compatible bw
 *  create a vector for end time of the tv show coupled with the compatibel bw
 *  sort ech of them (no need for special cmp function) 
 *
*/

int getMaxBw(vector<ii> &startTimeBw, vector<ii> &endTimeBw)
{
	if (startTimeBw.size() == 0 || endTimeBw.size() == 0) {
		return 0;
	}
	sort(startTimeBw.begin(), startTimeBw.end());
	sort(endTimeBw.begin(), endTimeBw.end());

	int maxBw = startTimeBw[0].second;
	int start = 1, end = 0;
	int currBw = startTimeBw[0].second;

	while (start < startTimeBw.size() && end < endTimeBw.size()) {
		if (startTimeBw[start].first <= endTimeBw[end].first) {
			currBw += startTimeBw[start].second;
			++start;
			maxBw = max (maxBw, currBw);
		}
		else {
			currBw -= endTimeBw[end].second;
			++end;
		}
	}
	return maxBw;
}


void convertTupleToTvShowsVectors (vector<tuple<int, int, int>> & input, vector<ii> &startTimeBw, vector<ii> &endTimeBw, int debug=0)
{
	for (auto &t : input ) {
		int start, end, bw;
		tie(start, end, bw) = t;
		if (debug) {
			cout << "start: " << start << ". end: " << end << ". bw: " << bw << endl;
		}
		startTimeBw.emplace_back (start, bw);
		endTimeBw.emplace_back (end, bw);
	}
}


int getMaxBw (vector<tuple<int, int, int>> &input) {
	vector<ii> s, e;
	convertTupleToTvShowsVectors(input, s, e);
	return getMaxBw(s, e);
}


void test(vector<tuple<int, int, int>> &input) {
	cout << "max BW: " << getMaxBw (input) << endl;
}

int main()
{

	/* For input 1
	 * ===========
	 * tuple = { startTime, endTime, Bw }
	 *   tvShows = { {1, 4, 2}, { 2, 3, 1}, {5, 8, 3}, { 6, 7, 5},  {8, 10, 9} }
	 *   1--->4                : 2
	 *    2->3                   : 1 --> 3
	 *         5--->8            : 3
	 *          6->7             : 5
	 *              8-->10       : 9 
	 * Expected: 12
	 * ----------------------------
	 * For input 2
	 * ===========
	 * tuple = { startTime, endTime, Bw }
	 *   tvShows = { {1, 4, 2}, { 2, 3, 1}, {5, 8, 3}, { 6, 7, 5},  {9, 10, 9} }
	 *   1--->4                : 2
	 *    2->3                   : 1 --> 3
	 *         5--->8            : 3
	 *          6->7             : 5
	 *              8-->10       : 9 
	 * expected: 9
	 * ----------------------------
	 */

	vector<tuple<int, int, int>> input1 = { {1, 4, 2}, {2, 3, 1}, {5, 8, 3}, {6, 7, 5}, {8, 10, 9}};
	vector<tuple<int, int, int>> input2 = { {1, 4, 2}, {2, 3, 1}, {5, 8, 3}, {6, 7, 5}, {9, 10, 9}};
	test(input1);
	test(input2);
	return 0;
}


