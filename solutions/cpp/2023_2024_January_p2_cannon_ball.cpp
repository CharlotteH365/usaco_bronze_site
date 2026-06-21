/*
USACO Bronze: Cannon Ball
Season: 2023-2024
Contest: January
Problem: 2
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
    int N,S; cin>>N>>S; S--;
    vector<pair<int,int>> t(N);
    for(int i=0;i<N;++i) cin>>t[i].first>>t[i].second;
    int pos=S,power=1,dir=1,ans=0;
    vector<bool> broken(N,false);
    set<tuple<int,int,int>> vis;
    while(pos>=0 && pos<N){
        if(vis.count({pos,power,dir})) break;
        vis.insert({pos,power,dir});
        auto[q,v]=t[pos];
        if(q==0){power+=v;dir*=-1;}
        else if(!broken[pos]&&power>=v){broken[pos]=true;ans++;}
        pos+=dir*power;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
