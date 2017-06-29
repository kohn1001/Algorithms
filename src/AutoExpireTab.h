//
//  AutoExpireTab.cpp
//  competitive
//
//  Created by Nathaniel Kohn on 19 J 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//

#include <stdio.h>
#include <thread>
#include <unordered_map>
#include <mutex>
#include <condition_variable>

using namespace std;
template <typename K, typename V>
class AutoExpireTab {
public:
    AutoExpireTab(int size) {}
    void init();
    void insert(K k, V v, size_t timeDur);
    void run();
    V get(K key);
    
private:
    thread t1;
    map<time_t, K> expHandler;
    unordered_map<K, V> table;
    mutex mut;
    condition_variable cv;
};



