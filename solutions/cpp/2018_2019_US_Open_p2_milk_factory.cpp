/*
USACO Bronze: Milk Factory
Season: 2018-2019
Contest: US Open
Problem: 2
Tags: GRAPH

Approach note:
Primary pattern: Graph-lite / Connectivity (轻量图论). Use adjacency, reachability, indegree/outdegree, or simple DFS/BFS when needed. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: build adjacency and traverse with DFS/BFS
    int N; cin>>N;
    vector<int> outdeg(N,0);
    for(int i=0;i<N-1;++i){
        int a,b; cin>>a>>b; --a;--b;
        outdeg[a]++;
    }
    int sink=-1;
    for(int i=0;i<N;++i){
        if(outdeg[i]==0){
            if(sink!=-1){cout<<"-1\n";return;}
            sink=i+1;
        }
    }
    cout<<sink<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
