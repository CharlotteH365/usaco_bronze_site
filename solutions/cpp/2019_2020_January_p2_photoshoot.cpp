/*
USACO Bronze: Photoshoot
Season: 2019-2020
Contest: January
Problem: 2
Tags: ADHOC, MATH

Approach note:
Primary pattern: Ad Hoc / Casework (分类讨论). Look for invariants, small examples, and edge cases before coding. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: identify the invariant and handle edge cases
    int N; cin>>N;
    vector<int> b(N-1);
    for(int i=0;i<N-1;++i) cin>>b[i];
    for(int start=1;start<=N;++start){
        vector<int> a={start};
        set<int> used={start};
        bool ok=true;
        for(int bi:b){
            int nxt=bi-a.back();
            if(nxt<1||nxt>N||used.count(nxt)){ok=false;break;}
            a.push_back(nxt); used.insert(nxt);
        }
        if(ok){
            for(int i=0;i<N;++i) cout<<a[i]<<" \n"[i==N-1];
            return;
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
