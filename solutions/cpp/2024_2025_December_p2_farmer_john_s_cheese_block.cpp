/*
USACO Bronze: Farmer John's Cheese Block
Season: 2024-2025
Contest: December
Problem: 2
Tags: GRID, COUNT, UPDATE

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
    int N,Q; cin>>N>>Q;
    vector<vector<int>> xy(N,vector<int>(N,0)),yz(N,vector<int>(N,0)),zx(N,vector<int>(N,0));
    int ans=0;
    while(Q--){
        int x,y,z; cin>>x>>y>>z;
        xy[x][y]++; if(xy[x][y]==N) ans++;
        yz[y][z]++; if(yz[y][z]==N) ans++;
        zx[z][x]++; if(zx[z][x]==N) ans++;
        cout<<ans<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
