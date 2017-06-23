//
//
//  Created by Nathaniel Kohn on 11 M 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>
#include <memory>
#include <iomanip>
#include <cmath>
#include <condition_variable>
#include <mutex>
#include "AutoExpireTab.h"
#include <thread>


/* My Templates for convenience */
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int)j; i < (int)k; ++i)
#define sz(x) ( (int) x.size())
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define zero(x) memset((x), 0, sizeof((x)))
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int ,int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using seii = set<ii>;
using stii = stack<ii>;
using StrSet = set<string>;
using vs = vector<string>;

#include <unistd.h>
//#include <thread

void foo()
{
    
}

template <typename K, typename V>
void AutoExpireTab<K, V>::init()
{
//    t1 = unique_ptr<thread>(new thread(&AutoExpireTab<K,V>::run(), this));
    //threads.push_back(thread(&AutoExpireTab<K, V>::run, this));
//    t1 = new thread(&AutoExpireTab<K, V>::run, this);
    t1 = thread(&AutoExpireTab<K, V>::run, this);
    
//    run();
}
template <typename K, typename V>
void AutoExpireTab<K, V>::insert(K k, V v, size_t timeDur)
{
    std::time_t t = std::time(0);
    cout << t << " seconds since epoch\n";
    t += timeDur;
    cout << "Expiration time for " << k << " is: " << t << endl;
    expHandler.emplace(make_pair(t, k));
    auto first = expHandler.begin()->first;
    cout << "first is: " << first << endl;
    table.emplace(k, v);
    cv.notify_one();
}

auto sec = std::chrono::seconds(1);

template <typename K, typename V>
void AutoExpireTab<K, V>::run()
{
    while(true) {
        unique_lock<mutex> lk(mut);
        cv.wait(lk, [this]() {return expHandler.begin() != expHandler.end(); });
        auto first = expHandler.begin()->first;
        time_t t = time(0);
        auto diff = first -t;
        cv.wait_for(lk, diff*sec);
        
        cout << "Finished waiting" << endl;
        auto ub = expHandler.upper_bound(t);
        if(ub == expHandler.end()) {continue;}
        for (auto it = expHandler.begin(); it != expHandler.end(); ++it) {
            auto to_delete = table.find(it->second);
            table.erase(to_delete);
            expHandler.erase(it);
            if(it == ub) { break;}
        }
    }
}

template <typename K, typename V>
V AutoExpireTab<K, V>::get(K key)
{
    return table[key];
}




int main()

{
    AutoExpireTab<int, int> aTab(10);
    //A a;
    
    aTab.insert(1,5, 10);
//    thread t1(&AutoExpireTab<int, int>::init, &aTab);
    aTab.init();
    condition_variable cv;
    mutex mut;
    int cnt = 0;
    while (cnt < 5) {
        //this_thread::sleep_for(5s);
        cout << "value in table: " << aTab.get(1) << endl;
        unique_lock<mutex> lk(mut);
        cv.wait_for(lk, std::chrono::seconds(5));
        cout << "after cv: " << aTab.get(1) << endl;
        ++cnt;
    }
//    t1.join();
    return 0;
}








#ifdef DEGBUG
    /*
    int N; int T;
    cin >> T;
    rep(i, 0, T) {
        vii v;
        cin >> N;
       int M;
        cin >> M; set<string> fs;
        for (int i = 0; i < N; ++i) {
            string name;
//            while(getline(cin, name) && name.empty());
           //        reverseStr(s) ;
        }
//        printFs(fs);
        
        rep(i, 0, M) {
            string dir;
            while(getline(cin, dir) && dir.empty());
//            ll num = getCommNum(fs, dir);
//            cout << "Case #" << i+1 << ": " << num << endl;
        }
    }
    
    //    cout << "the sum: " << sum << endl;
    // cout << "the sum: " << sum << endl;
   */

#endif
