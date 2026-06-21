/*
USACO Bronze: Bucket Brigade
Season: 2018-2019
Contest: US Open
Problem: 1
Tags: GRID, GEOMETRY

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
    string g[10];
    for(int i=0;i<10;++i) cin>>g[i];
    int br,bc,lr,lc,rr,rc;
    for(int r=0;r<10;++r) for(int c=0;c<10;++c){
        if(g[r][c]=='B'){br=r;bc=c;}
        if(g[r][c]=='L'){lr=r;lc=c;}
        if(g[r][c]=='R'){rr=r;rc=c;}
    }
    int dist=abs(br-lr)+abs(bc-lc)-1;
    if(br==lr&&lr==rr&&min(bc,lc)<rc&&rc<max(bc,lc)) dist+=2;
    if(bc==lc&&lc==rc&&min(br,lr)<rr&&rr<max(br,lr)) dist+=2;
    cout<<dist<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
