/*
USACO Bronze: Rotate and Shift
Season: 2022-2023
Contest: US Open
Problem: 3
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
    int N,K,T; cin>>N>>K>>T;
    vector<int> active(K);
    for(int i=0;i<K;++i){cin>>active[i];active[i]--;}
    vector<int> ans(N);
    // Active cows rotate among themselves
    for(int i=0;i<K;++i)
        ans[active[i]]=active[(i+T)%K];
    // Non-active cows: find nearest active cow to the left
    for(int i=0;i<N;++i){
        if(ans[i]!=0) continue; // already set (active cow)
        // Find distance to nearest active cow
        int dist=0, j=i;
        while(ans[j]==0){
            j=(j-1+N)%N;
            dist++;
        }
        ans[i]=((j+T)%N);
    }
    for(int i=0;i<N;++i) cout<<ans[i]+1<<" \n"[i==N-1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
