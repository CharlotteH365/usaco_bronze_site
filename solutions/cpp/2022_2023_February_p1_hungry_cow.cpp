/*
USACO Bronze: Hungry Cow
Season: 2022-2023
Contest: February
Problem: 1
Tags: SIM, MATH

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
    int N; long long T; cin>>N>>T;
    vector<pair<long long,long long>> del(N);
    for(int i=0;i<N;++i) cin>>del[i].first>>del[i].second;
    sort(del.begin(),del.end());
    long long day=1,hay=0,ans=0;
    for(auto&[d,b]:del){
        if(day<d){long long skip=min(hay,d-day);ans+=skip;hay-=skip;day=d;}
        hay+=b;
        long long eat=min(hay,T-day+1);
        ans+=eat; hay-=eat; day+=eat;
        if(day>T) break;
    }
    if(day<=T){ans+=min(hay,T-day+1);}
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
