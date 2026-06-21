/*
USACO Bronze: Air Cownditioning II
Season: 2022-2023
Contest: January
Problem: 2
Tags: SEARCH, SIM

Approach note:
Primary pattern: Complete Search / Brute Force (枚举 / 暴力). Use constraints to choose enumeration depth; keep validation in a clean check function. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: enumerate all possibilities within constraints
    int N,M; cin>>N>>M;
    vector<tuple<int,int,int>> cows(N);
    for(int i=0;i<N;++i){int s,t,c;cin>>s>>t>>c;cows[i]={s,t,c};}
    vector<tuple<int,int,int,int>> acs(M);
    for(int i=0;i<M;++i){int a,b,p,c;cin>>a>>b>>p>>c;acs[i]={a,b,p,c};}
    int best=1e9;
    for(int mask=0;mask<(1<<M);++mask){
        int cost=0;
        vector<int> cool(101,0);
        for(int i=0;i<M;++i) if(mask&(1<<i)){
            auto[a,b,p,c]=acs[i]; cost+=c;
            for(int t=a;t<=b;++t) cool[t]+=p;
        }
        bool ok=true;
        for(auto&[s,t,c]:cows){
            for(int pos=s;pos<=t;++pos)
                if(cool[pos]<c){ok=false;break;}
            if(!ok) break;
        }
        if(ok) best=min(best,cost);
    }
    cout<<best<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
