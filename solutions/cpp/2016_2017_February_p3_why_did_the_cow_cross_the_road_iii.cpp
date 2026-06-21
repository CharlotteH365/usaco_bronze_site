/*
USACO Bronze: Why Did the Cow Cross the Road III
Season: 2016-2017
Contest: February
Problem: 3
Tags: GRID, GRAPH

Approach note:
Primary pattern: Union-Find (DSU) to find connected components of cells that are reachable
without crossing a road. Then count pairs of cows in different components as "distant".
Roads exist between some adjacent cells; cells without roads between them are connected.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int sz) : parent(sz) {
        for (int i = 0; i < sz; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[a] = b;
    }
};

void solve() {
    // Key: process the 2D grid with nested loops
    int N,K,R; cin>>N>>K>>R;
    set<tuple<int,int,int,int>> roads;
    for(int i=0;i<R;++i){
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        --r1;--c1;--r2;--c2;
        roads.insert({r1,c1,r2,c2});
        roads.insert({r2,c2,r1,c1});
    }
    vector<pair<int,int>> cows(K);
    for(int i=0;i<K;++i){cin>>cows[i].first>>cows[i].second;--cows[i].first;--cows[i].second;}
    int dr[]={0,0,1,-1},dc[]={1,-1,0,0};
    auto bfs=[&](int sr,int sc){
        vector<vector<bool>> vis(N,vector<bool>(N,false));
        vector<pair<int,int>> q; q.push_back({sr,sc});
        vis[sr][sc]=true;
        set<pair<int,int>> reach;
        for(int idx=0;idx<(int)q.size();++idx){
            auto[r,c]=q[idx]; reach.insert({r,c});
            for(int d=0;d<4;++d){
                int nr=r+dr[d],nc=c+dc[d];
                if(nr>=0&&nr<N&&nc>=0&&nc<N&&!vis[nr][nc]&&!roads.count({r,c,nr,nc})){
                    vis[nr][nc]=true; q.push_back({nr,nc});
                }
            }
        }
        return reach;
    };
    int distant=0;
    for(int i=0;i<K;++i){
        auto reach=bfs(cows[i].first,cows[i].second);
        for(int j=i+1;j<K;++j)
            if(!reach.count(cows[j])) distant++;
    }
    cout<<distant<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
