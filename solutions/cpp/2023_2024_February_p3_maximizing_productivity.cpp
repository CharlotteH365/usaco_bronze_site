/*
USACO Bronze: Maximizing Productivity
Season: 2023-2024
Contest: February
Problem: 3
Tags: SORT, GREEDY

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
    int N,Q; cin>>N>>Q;
    vector<int> c(N),t(N);
    for(int i=0;i<N;++i) cin>>c[i];
    for(int i=0;i<N;++i) cin>>t[i];
    vector<int> lim(N);
    for(int i=0;i<N;++i) lim[i]=c[i]+t[i]-i;
    sort(lim.begin(),lim.end());
    while(Q--){
        int V,S; cin>>V>>S;
        if(lim[V-1]>=S) cout<<"YES\n";
        else cout<<"NO\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
