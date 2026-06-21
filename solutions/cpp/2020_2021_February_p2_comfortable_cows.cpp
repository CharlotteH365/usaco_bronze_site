/*
USACO Bronze: Comfortable Cows
Season: 2020-2021
Contest: February
Problem: 2
Tags: GRID, SIM

Approach note:
Primary pattern: Grid / Geometry (网格 / 几何). Draw coordinates, standardize indexing, and watch inclusive/exclusive borders. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin>>N;
    const int S=2002,OFF=1000;
    vector<vector<bool>> g(S,vector<bool>(S,false));
    int comfy=0;
    int dr[]={0,0,1,-1},dc[]={1,-1,0,0};
    auto cnt=[&](int r,int c){
        int c=0;
        for(int d=0;d<4;++d) if(g[r+dr[d]][c+dc[d]]) c++;
        return c;
    };
    while(N--){
        int x,y; cin>>x>>y; x+=OFF; y+=OFF;
        // Check neighbors before adding
        for(int d=0;d<4;++d){
            int nx=x+dr[d],ny=y+dc[d];
            if(g[nx][ny]){
                int c=cnt(nx,ny);
                if(c==3) comfy--;
            }
        }
        g[x][y]=true;
        int c=cnt(x,y);
        if(c==3) comfy++;
        for(int d=0;d<4;++d){
            int nx=x+dr[d],ny=y+dc[d];
            if(g[nx][ny]){
                int c2=cnt(nx,ny);
                if(c2==3) comfy++;
                else if(c2==4) comfy--;
            }
        }
        cout<<comfy<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
