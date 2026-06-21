/*
USACO Bronze: Sleepy Cow Sorting
Season: 2018-2019
Contest: January
Problem: 2
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
    int ans=N-1;
    while(ans>0 && a[ans-1]<a[ans]) ans--;
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
