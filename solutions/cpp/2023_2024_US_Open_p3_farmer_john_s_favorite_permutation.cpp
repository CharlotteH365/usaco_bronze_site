/*
USACO Bronze: Farmer John's Favorite Permutation
Season: 2023-2024
Contest: US Open
Problem: 3
Tags: SORT, ADHOC

Approach note:
Primary pattern: Sorting / Ordering (排序). After sorting, inspect neighbors, prefixes, suffixes, or endpoints. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: sort then process greedily
    int N; cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    long long inv=0;
    for(int i=0;i<N;++i)
        for(int j=i+1;j<N;++j)
            if(a[i]>a[j]) inv++;
    cout<<inv<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
