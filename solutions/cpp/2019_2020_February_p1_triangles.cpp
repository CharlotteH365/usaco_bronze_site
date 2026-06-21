/*
USACO Bronze: Triangles
Season: 2019-2020
Contest: February
Problem: 1
Tags: GEOMETRY, SEARCH

Approach note:
Primary pattern: Geometry (几何). Use coordinates, areas, distances, intersections, and orientation. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: compute areas and overlap of axis-aligned rectangles
    int N; cin>>N;
    vector<pair<int,int>> pts(N);
    for(int i=0;i<N;++i) cin>>pts[i].first>>pts[i].second;
    const int MOD=1e9+7;
    long long ans=0;
    for(int i=0;i<N;++i){
        auto[xi,yi]=pts[i];
        vector<long long> sx,sy;
        for(int j=0;j<N;++j){
            if(i==j) continue;
            auto[xj,yj]=pts[j];
            if(xj==xi) sy.push_back(abs(yj-yi));
            if(yj==yi) sx.push_back(abs(xj-xi));
        }
        long long sumx=0,sumy=0;
        for(long long v:sx) sumx=(sumx+v)%MOD;
        for(long long v:sy) sumy=(sumy+v)%MOD;
        ans=(ans+sumx*sumy)%MOD;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
