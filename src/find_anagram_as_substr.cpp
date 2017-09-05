#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;
/*
 * Anagram strings are the string that have the same character not necessarly in the same order/ permutation, for example: cat and tac are
 * anagrams
 *
 * Find Anagram in a string as substring: this is a super cool algorithm I've come with (I'm using a variation of Rabin-Karp Algo)
 *
 * 1. Interate on the longer string (in our case str is given as longer than pattern), for in in str:
 * 2. run substr from i pat.size() bytes, hold it in tmp_str.
 * 3. calc hash (as describe below) of tmp_str and compare to hash of pattern, if eqaul we have a match
 *
 * 
 * Hash calculation:
 * Assign for each character from 'a' to 'z' a prime number (do it once as preprocessing and use a lookup table for every calculation)
 * To get the Hash of a word - get the prime for each char in the word and multiply them, for example:
 * word = abc
 * a = 2
 * b = 3
 * c = 5
 * hash = 2*3*5
 * I'm doing an optimization below - after we calc the first hash from i =0 to i + patt.size(), from now on we can divide by the prime of the i-th char and multiply
 * with the prime of the char that we now inserting in our window, for example, if str is abcdef, the first hash is 2*3*5, the next hash calc would be:
 * divid by 2 (a) and multiply by 7 assuming 7 is the prime assigend to d.
 *
 */

const int SIZE = 1 << 10;
const int alphaBetSize = 26;
const char startWithChar = 'a';

static vector<int> primes (SIZE, 1);
/* we want to get the same unique number to Anagram (order in seq is not import.) */
int getPrime (char c)
{
	static bool firstTime = true;
	static map<char, int> charToPrime;
	/*happen only in first call */
	if(firstTime) {
		int i = 2, cnt = 0;
		char ic = startWithChar;
		while (cnt < alphaBetSize) {
			cnt += (primes[i] ? 1 : 0);
			if(primes[i]) {
				charToPrime.emplace(ic, i);
				++ic;
			}
			++i;
		}
		firstTime = false;
	}
	return charToPrime[c];
}

int calcHash(const string & str, int n = SIZE)
{
	int cnt = 1;
	for (auto s:str) {
		cnt *= getPrime(s);
	}
	return cnt;
}

bool checkAnaAsSubstr(const string &str, const string &pattern)
{
	int patternHash = calcHash(pattern);
	string sub = str.substr(0, pattern.size());
	int strHash = calcHash(sub);
	for ( int i=0; i < str.size(); ++i) {
		if (strHash == patternHash) {
			return true;
		}
		strHash /= getPrime(str[i]);
		strHash *= getPrime(str[i+pattern.size()]);
	}
	return false;
}

int main()
{
	string str = "atcbcba";
	vector<string> v {"cat", "ccb", "abc", "ztc", "tbc"};;
	for (auto &s : v) {
		cout << s << " " <<  (checkAnaAsSubstr(str, s) ? "is Anagram " : "No Anagram ") << endl;
	}
	char c = 'a';
	while (c <= 'z') {
		cout << "prime for: " << c << " is: " << getPrime(c) << endl;
		++c;
	}
	
	return 0;
}
	
