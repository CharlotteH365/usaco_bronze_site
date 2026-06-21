/*
USACO Bronze: Balancing Bacteria
Season: 2023-2024
Contest: January
Problem: 3
Tags: PREFIX, GREEDY, MATH

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
    vector<long long> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    long long cur=0,slope=0,ans=0;
    for(int i=0;i<N;++i){
        cur+=slope;
        long long target=-a[i];
        long long diff=target-cur;
        ans+=abs(diff);
        cur+=diff;
        slope+=diff;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
