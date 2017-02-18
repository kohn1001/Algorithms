//
//  main.cpp
//  algorithms
//
//  Created by Nathaniel Kohn on 22 Shevat 5777.
//  Copyright © 5777 Nathaniel Kohn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <memory>
#include <queue>

using namespace std;
using vi = vector<int>;
using qi = queue<int>;
using mii = map<int, int>;
const int MaxInt = std::numeric_limits<int>::max();



class Graph {
public:
    Graph(int queriesNum, int nodeNum, int edgeNum) :
    queriesNum_(queriesNum),
    nodeNum_(nodeNum+1),
    edgeNum_(edgeNum),
    adjList_(nodeNum_),
    dist_(nodeNum_, MaxInt)
    {
    }
    Graph(const Graph& g){}
    ~Graph(){}
    int getSource() {
        return source_;
    }
    size_t getSize() {
        return nodeNum_;
    }
    const vi getNeighbours(int i) const {
        return adjList_[i];
    }
    const void addEdge(int from, int to) {
        adjList_[from].emplace_back(to);
        adjList_[to].emplace_back(from);
    }
    const int getQueriesNum() const {
        return queriesNum_;
    }
    void bfs();
    void printPath(int source, int curr);
    void setSource(int s) {
        source_ = s;
    }
    
private:
    int queriesNum_;
    int nodeNum_;
    int edgeNum_;
    vector<vi> adjList_;
    vi dist_;
    mii bfsPath_;
    qi bfsQueue_;
    int source_;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hackerrank BFS" << endl;
    int queriesNum, nodeNum, edgeNum, source;
    cin >> queriesNum;
    if(queriesNum < 1) { return 1;}
    
    for (int i = 0; i < queriesNum && i <= 10; ++i) {
        cin >> nodeNum; cin >> edgeNum;
        unique_ptr<Graph> uptrG(new Graph(queriesNum, nodeNum, edgeNum));
        for(int i = 0; i < edgeNum; ++i) {
            int from, to;
            cin >> from; cin >> to;
            uptrG->addEdge(from, to);
        }
        cin >> source;
        uptrG->setSource(source);
        uptrG->bfs();
    }
    return 0;
}




void Graph::bfs()
{
    bfsQueue_.push(source_);
    dist_[source_] = 0;
    bfsPath_.emplace(source_, source_);
    
    while (!bfsQueue_.empty()) {
        auto currNode = bfsQueue_.front(); bfsQueue_.pop();
        for( auto i : getNeighbours(currNode)) {
            if(dist_[i] == MaxInt) {
                dist_[i] = dist_[currNode] + 6;
                bfsQueue_.push(i);
                bfsPath_.emplace(i, currNode);
            }
        }
    }
    for (int i = 1; i < nodeNum_; ++i) {
        if(i == source_) { continue;}
        if( dist_[i] == MaxInt) {
            cout << "-1" << " ";
        }
        else {
            cout << dist_[i] << " ";
        }
    }
    cout << endl;
}

void Graph::printPath(int source, int curr)
{
    if(source == curr) return;
    printPath(source, bfsPath_[curr]);
    cout << "Curr is: " << curr << endl;
    if(dist_[curr] != MaxInt) {
        cout << dist_[curr] << " ";
    }
}
