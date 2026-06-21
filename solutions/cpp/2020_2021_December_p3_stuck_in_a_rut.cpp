/*
USACO Bronze: Stuck in a Rut
Season: 2020-2021
Contest: December
Problem: 3
Tags: SIM, GEOMETRY

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: simulate the process step by step
    int N; cin>>N;
    vector<char> dir(N);
    vector<int> x(N),y(N);
    for(int i=0;i<N;++i) cin>>dir[i]>>x[i]>>y[i];
    const int INF=1e9;
    vector<int> stop(N,INF);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(i==j||dir[i]==dir[j]) continue;
            int ni=dir[i]=='N'?i:j, ei=dir[i]=='E'?i:j;
            if(dir[ni]!='N'||dir[ei]!='E') continue;
            int nx=x[ni],ny=y[ni],ex=x[ei],ey=y[ei];
            if(nx<=ex||ny>=ey) continue;
            int tn=ey-ny, te=nx-ex;
            if(tn<te){
                if(stop[ni]>tn) stop[ei]=min(stop[ei],te);
            } else if(te<tn){
                if(stop[ei]>te) stop[ni]=min(stop[ni],tn);
            }
        }
    }
    for(int i=0;i<N;++i){
        if(stop[i]==INF) cout<<"Infinity\n";
        else cout<<stop[i]<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
