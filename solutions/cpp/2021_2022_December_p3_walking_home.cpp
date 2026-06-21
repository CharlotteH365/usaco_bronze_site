/*
USACO Bronze: Walking Home
Season: 2021-2022
Contest: December
Problem: 3
Tags: GRID, SEARCH

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
    int T; cin>>T;
    while(T--){
        int N,K; cin>>N>>K;
        vector<string> g(N);
        for(int i=0;i<N;++i) cin>>g[i];
        int ans=0;
        function<void(int,int,int,int)> dfs=[&](int r,int c,int turns,int prev){
            if(r==N-1&&c==N-1){ans++;return;}
            if(c+1<N && g[r][c+1]!='H'){
                int nt=turns+(prev!=-1&&prev!=1?1:0);
                if(nt<=K) dfs(r,c+1,nt,1);
            }
            if(r+1<N && g[r+1][c]!='H'){
                int nt=turns+(prev!=-1&&prev!=0?1:0);
                if(nt<=K) dfs(r+1,c,nt,0);
            }
        };
        dfs(0,0,0,-1);
        cout<<ans<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
