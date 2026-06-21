/*
USACO Bronze: The Bucket List
Season: 2018-2019
Contest: December
Problem: 2
Tags: PREFIX, SIM

Approach note:
Primary pattern: Prefix / Difference / Incremental Update (前缀 / 差分). Precompute reusable sums or maintain local contribution changes. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: use prefix sums for O(1) range queries
    int N; cin>>N;
    vector<int> tl(1002,0);
    for(int i=0;i<N;++i){
        int s,t,b; cin>>s>>t>>b;
        tl[s]+=b; tl[t]-=b;
    }
    int cur=0,mx=0;
    for(int i=1;i<=1000;++i){cur+=tl[i];mx=max(mx,cur);}
    cout<<mx<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
