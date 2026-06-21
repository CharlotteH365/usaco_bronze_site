/*
USACO Bronze: Acowdemia II
Season: 2020-2021
Contest: US Open
Problem: 2
Tags: GRAPH, COUNT

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
    int K,N; cin>>K>>N;
    vector<vector<string>> pubs(N,vector<string>(K));
    set<string> cows_set;
    for(int i=0;i<N;++i){
        for(int j=0;j<K;++j){
            cin>>pubs[i][j];
            cows_set.insert(pubs[i][j]);
        }
    }
    set<pair<string,string>> senior;
    for(auto&names:pubs){
        for(int i=0;i<K;++i){
            for(int j=i+1;j<K;++j){
                if(names[i]>names[j])
                    senior.insert({names[i],names[j]});
            }
        }
    }
    cout<<senior.size()<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
