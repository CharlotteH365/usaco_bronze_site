/*
USACO Bronze: Majority Opinion
Season: 2023-2024
Contest: January
Problem: 1
Tags: COUNT, STR, ADHOC

Approach note:
Primary pattern: Counting / Frequency (计数 / 频率). Use arrays, maps, sets, or contribution counting instead of repeated scans. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: count frequencies with arrays/maps
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> a(N);
        for(int i=0;i<N;++i) cin>>a[i];
        set<int> possible;
        for(int i=0;i<N-1;++i) if(a[i]==a[i+1]) possible.insert(a[i]);
        for(int i=0;i<N-2;++i){
            if(a[i]==a[i+1]||a[i]==a[i+2]) possible.insert(a[i]);
            if(a[i+1]==a[i+2]) possible.insert(a[i+1]);
        }
        if(possible.empty()) cout<<"-1\n";
        else {
            for(int x:possible) cout<<x<<" ";
            cout<<"\n";
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
