/*
USACO Bronze: Measuring Traffic
Season: 2018-2019
Contest: February
Problem: 3
Tags: SIM, INTERVAL

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin>>N;
    vector<tuple<string,int,int>> ev(N);
    for(int i=0;i<N;++i){
        string t; int l,h; cin>>t>>l>>h;
        ev[i]={t,l,h};
    }
    // Forward: after all events
    long long lo=-1e9, hi=1e9;
    for(auto&[t,l,h]:ev){
        if(t=="none"){lo=max(lo,(long long)l);hi=min(hi,(long long)h);}
        else if(t=="on"){lo+=l;hi+=h;}
        else{lo-=h;hi-=l;lo=max(lo,0LL);}
    }
    cout<<max(0LL,lo)<<" "<<hi<<"\n";
    // Backward: before all events
    lo=-1e9; hi=1e9;
    for(int i=N-1;i>=0;--i){
        auto&[t,l,h]=ev[i];
        if(t=="none"){lo=max(lo,(long long)l);hi=min(hi,(long long)h);}
        else if(t=="off"){lo+=l;hi+=h;}
        else{lo-=h;hi-=l;lo=max(lo,0LL);}
    }
    cout<<max(0LL,lo)<<" "<<hi<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
