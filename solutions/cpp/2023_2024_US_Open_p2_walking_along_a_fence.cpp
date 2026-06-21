/*
USACO Bronze: Walking Along a Fence
Season: 2023-2024
Contest: US Open
Problem: 2
Tags: GRID, PATH, PREFIX

Approach note:
Primary pattern: Grid / Geometry (网格 / 几何). Draw coordinates, standardize indexing, and watch inclusive/exclusive borders. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N,P; cin>>N>>P;
    vector<pair<int,int>> pts(P);
    for(int i=0;i<P;++i) cin>>pts[i].first>>pts[i].second;
    // Compute prefix perimeter distances
    long long total=0;
    vector<long long> pref={0};
    auto dist=[&](auto&a,auto&b){return (long long)abs(a.first-b.first)+abs(a.second-b.second);};
    for(int i=0;i<P;++i){
        total+=dist(pts[i],pts[(i+1)%P]);
        pref.push_back(total);
    }
    auto pos=[&](int x,int y){
        for(int i=0;i<P;++i){
            auto[x1,y1]=pts[i]; auto[x2,y2]=pts[(i+1)%P];
            if(x1==x2&&x1==x&&min(y1,y2)<=y&&y<=max(y1,y2))
                return pref[i]+abs(y-y1);
            if(y1==y2&&y1==y&&min(x1,x2)<=x&&x<=max(x1,x2))
                return pref[i]+abs(x-x1);
        }
        return 0LL;
    };
    while(N--){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        long long p1=pos(x1,y1),p2=pos(x2,y2);
        long long d=abs(p1-p2);
        cout<<min(d,total-d)<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
