/*
USACO Bronze: Stamp Grid
Season: 2022-2023
Contest: February
Problem: 2
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
        int N; cin>>N;
        vector<string> target(N);
        for(int i=0;i<N;++i) cin>>target[i];
        int K; cin>>K;
        vector<string> stamp(K);
        for(int i=0;i<K;++i) cin>>stamp[i];
        vector<pair<int,int>> stars;
        for(int r=0;r<K;++r)
            for(int c=0;c<K;++c)
                if(stamp[r][c]=='*') stars.push_back({r,c});
        vector<string> painted(N,string(N,'.'));
        for(int r=0;r<=N-K;++r){
            for(int c=0;c<=N-K;++c){
                bool can=true;
                for(auto&[dr,dc]:stars)
                    if(target[r+dr][c+dc]!='*'){can=false;break;}
                if(can)
                    for(auto&[dr,dc]:stars)
                        painted[r+dr][c+dc]='*';
            }
        }
        bool ok=true;
        for(int r=0;r<N;++r)
            if(target[r]!=painted[r]){ok=false;break;}
        cout<<(ok?"YES":"NO")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
