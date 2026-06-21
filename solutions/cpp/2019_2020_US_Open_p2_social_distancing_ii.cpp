/*
USACO Bronze: Social Distancing II
Season: 2019-2020
Contest: US Open
Problem: 2
Tags: SORT, SIM

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
    vector<pair<int,int>> cows(N);
    for(int i=0;i<N;++i) cin>>cows[i].first>>cows[i].second;
    sort(cows.begin(),cows.end());
    int R=1e9;
    for(int i=0;i<N-1;++i)
        if(cows[i].second!=cows[i+1].second)
            R=min(R,cows[i+1].first-cows[i].first);
    int ans=0;
    for(int i=0;i<N;){
        if(cows[i].second==1){
            ans++;
            while(i+1<N && cows[i+1].second==1 && cows[i+1].first-cows[i].first<R) i++;
        }
        i++;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
