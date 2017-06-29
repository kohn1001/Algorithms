#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isPali(string str)
{
	if(str.size() == 0) return true;
	int start =0, end = str.size()-1;
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	while (start < end) {
		if(!is_letter(str[start])) { ++start; continue;}
		if(!is_letter(str[end])) { --end; continue; }
		if(str[start] != str[end]) { return false; }
		++start; --end;
	}
	return true;
}

int main () 
{
	cout << "Please endter the string you want to check if palindrom: " << endl;
	string str;
	cin >> str;
	
	cout << "This is " << (isPali(str) ? "" : "NOT " ) << "a Palindrom" << endl;
	return 0;
}
