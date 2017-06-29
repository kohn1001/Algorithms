//
//  bucket_sort.h
//  competitive
//
//  Created by Nathaniel Kohn on 26 J 2017.
//  Copyright © 2017 Nathaniel Kohn. All rights reserved.
//

#ifndef bucket_sort_h
#define bucket_sort_h

#include<vector>

using namespace std;

class BucketSort {
public:
    BucketSort(int numOfCat, int arrSize);
    
private:
    int catNum;
    int arraySize;
    vector<int> indexes;
    vector<int> arr;
};

#endif /* bucket_sort_h */
