//
//  main.cpp
//  technical
//
//  Created by Nathaniel Kohn on 22 Shevat 5777.
//  Copyright © 5777 Nathaniel Kohn. All rights reserved.
//

/*hackarank pangrams*/
#include <iostream>
#include <map>
using namespace std;
map<char, int> createDict()
{
    map<char, int> dict;
    string allAbc("abcdefghijklmnopqrstuvwxyz");
    for(auto &i : allAbc) {
        dict.emplace(i, 0);
    }
    for(auto &i : dict) {
        cout << " char is: " << i.first << " freq is: " << i.second<<  endl;
    }
    return dict;
}

bool isPangram(const string & str)
{
    std::string lowerStr;
    
    for(const auto &i : str) {
        lowerStr += std::tolower(i);
    }
    map<char, int> dict = createDict();
    for(auto &i : lowerStr) {
        if(!('a' <= i && i <= 'z')) {
            continue;
        }
        if(dict[i] == 0) {
            dict[i] = 1;
        }
    }
    for(auto &i : dict) {
        if(i.second == 0 ) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    getline(cin,str);


    bool res = isPangram(str);
    cout << (res ? "pangram" : "not pangram") << endl;
    return 0;
}
