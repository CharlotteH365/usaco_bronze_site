/*
USACO Bronze: The Great Revegetation
Season: 2018-2019
Contest: February
Problem: 2
Tags: GRAPH, GREEDY

Approach note:
Primary pattern: Graph-lite / Connectivity (轻量图论). Use adjacency, reachability, indegree/outdegree, or simple DFS/BFS when needed. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N,M; cin>>N>>M;
    vector<vector<pair<int,char>>> adj(N);
    for(int i=0;i<M;++i){
        char t; int u,v; cin>>t>>u>>v; --u;--v;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    vector<int> color(N,0);
    // Greedy: assign smallest compatible grass type
    for(int i=0;i<N;++i){
        set<int> used;
        int forced=-1;
        for(auto&[v,t]:adj[i]){
            if(v<i && color[v]!=0){
                if(t=='S') forced=color[v];
                else used.insert(color[v]);
            }
        }
        if(forced!=-1) color[i]=forced;
        else {
            for(int g=1;g<=4;++g)
                if(!used.count(g)){color[i]=g;break;}
        }
    }
    for(int c:color) cout<<c;
    cout<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
