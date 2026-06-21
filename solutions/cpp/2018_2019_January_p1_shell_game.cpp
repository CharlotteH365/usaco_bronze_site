/*
USACO Bronze: Shell Game
Season: 2018-2019
Contest: January
Problem: 1
Tags: SIM

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
    vector<pair<int,int>> sw(N);
    vector<int> g(N);
    for(int i=0;i<N;++i){
        int a,b; cin>>a>>b>>g[i]; --a;--b;--g[i];
        sw[i]={a,b};
    }
    int best=0;
    for(int start=0;start<3;++start){
        int pos=start,score=0;
        for(int i=0;i<N;++i){
            if(pos==sw[i].first) pos=sw[i].second;
            else if(pos==sw[i].second) pos=sw[i].first;
            if(pos==g[i]) score++;
        }
        best=max(best,score);
    }
    cout<<best<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
