/*
USACO Bronze: Candy Cane Feast
Season: 2023-2024
Contest: December
Problem: 1
Tags: SIM, ADHOC

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
    int N,M; cin>>N>>M;
    vector<long long> cows(N),canes(M);
    for(int i=0;i<N;++i) cin>>cows[i];
    for(int i=0;i<M;++i) cin>>canes[i];
    for(long long cane:canes){
        long long eaten=0;
        for(int i=0;i<N;++i){
            if(cows[i]>eaten){
                long long eat=min(cows[i],cane)-eaten;
                cows[i]+=eat; eaten+=eat;
            }
            if(eaten>=cane) break;
        }
    }
    for(long long c:cows) cout<<c<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
