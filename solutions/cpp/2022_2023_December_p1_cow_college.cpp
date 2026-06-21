/*
USACO Bronze: Cow College
Season: 2022-2023
Contest: December
Problem: 1
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
    int N; cin>>N;
    vector<long long> t(N);
    for(int i=0;i<N;++i) cin>>t[i];
    sort(t.begin(),t.end());
    long long best=0, best_t=0;
    for(int i=0;i<N;++i){
        long long profit=t[i]*(N-i);
        if(profit>best){best=profit;best_t=t[i];}
    }
    cout<<best<<" "<<best_t<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
