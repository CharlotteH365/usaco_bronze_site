/*
USACO Bronze: Just Stalling
Season: 2020-2021
Contest: January
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
    int N; cin>>N;
    vector<int> cows(N),stalls(N);
    for(int i=0;i<N;++i) cin>>cows[i];
    for(int i=0;i<N;++i) cin>>stalls[i];
    sort(cows.rbegin(),cows.rend());
    long long ans=1;
    for(int i=0;i<N;++i){
        int fit=0;
        for(int s:stalls) if(s>=cows[i]) fit++;
        ans*=(fit-i);
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
