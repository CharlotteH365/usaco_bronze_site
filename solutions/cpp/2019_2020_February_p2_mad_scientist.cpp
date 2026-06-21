/*
USACO Bronze: Mad Scientist
Season: 2019-2020
Contest: February
Problem: 2
Tags: STR, SIM

Approach note:
Primary pattern: String Processing (字符串). Think in substrings, character counts, ordering, and pattern matching. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process string characters with counting or matching
    int N; cin>>N;
    string A,B; cin>>A>>B;
    int ans=0;
    bool in=false;
    for(int i=0;i<N;++i){
        if(A[i]!=B[i]){
            if(!in){ans++;in=true;}
        } else in=false;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
