/*
USACO Bronze: Acowdemia III
Season: 2020-2021
Contest: US Open
Problem: 3
Tags: GRID, COUNT

Approach note:
Primary pattern: Grid / Geometry (网格 / 几何). Draw coordinates, standardize indexing, and watch inclusive/exclusive borders. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process the 2D grid with nested loops
    int N,M; cin>>N>>M;
    vector<string> g(N);
    for(int i=0;i<N;++i) cin>>g[i];
    int dr[]={0,0,1,-1},dc[]={1,-1,0,0};
    set<pair<pair<int,int>,pair<int,int>>> pairs;
    for(int r=0;r<N;++r){
        for(int c=0;c<M;++c){
            if(g[r][c]=='G'){
                vector<pair<int,int>> adj;
                for(int d=0;d<4;++d){
                    int nr=r+dr[d],nc=c+dc[d];
                    if(nr>=0&&nr<N&&nc>=0&&nc<M&&g[nr][nc]=='C')
                        adj.push_back({nr,nc});
                }
                for(int i=0;i<(int)adj.size();++i)
                    for(int j=i+1;j<(int)adj.size();++j)
                        pairs.insert(minmax(adj[i],adj[j]));
            }
        }
    }
    cout<<pairs.size()<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
