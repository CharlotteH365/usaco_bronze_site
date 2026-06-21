/*
USACO Bronze: Alchemy
Season: 2021-2022
Contest: US Open
Problem: 3
Tags: SIM, GRAPH

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
    vector<long long> have(N+1);
    for(int i=1;i<=N;++i) cin>>have[i];
    int K; cin>>K;
    vector<vector<vector<int>>> recipes(N+1);
    for(int i=0;i<K;++i){
        int to,m; cin>>to>>m;
        vector<int> ing(m);
        for(int j=0;j<m;++j) cin>>ing[j];
        recipes[to].push_back(ing);
    }
    long long lo=0,hi=1e9;
    while(lo<hi){
        long long mid=(lo+hi+1)/2;
        vector<long long> need(N+1,0);
        vector<long long> cur=have;
        need[N]=mid;
        bool ok=true;
        for(int m=N;m>=1;--m){
            if(need[m]>cur[m]){
                long long sh=need[m]-cur[m];
                cur[m]=0;
                if(recipes[m].empty()){ok=false;break;}
                for(int ing:recipes[m][0]) need[ing]+=sh;
            } else cur[m]-=need[m];
        }
        if(ok) lo=mid; else hi=mid-1;
    }
    cout<<lo<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
