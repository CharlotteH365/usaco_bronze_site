/*
USACO Bronze: Moo Language
Season: 2022-2023
Contest: US Open
Problem: 2
Tags: STR, PARSING

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
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        int n=s.size(),ans=-1;
        for(int i=0;i+2<n;++i){
            if(s.substr(i,3)=="MOO"){
                int ops=i+(n-1-(i+2));
                if(ans==-1||ops<ans) ans=ops;
            }
        }
        cout<<ans<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
