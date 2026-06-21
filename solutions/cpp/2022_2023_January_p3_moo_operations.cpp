/*
USACO Bronze: Moo Operations
Season: 2022-2023
Contest: January
Problem: 3
Tags: STR, ADHOC

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
    int Q; cin>>Q;
    while(Q--){
        string s; cin>>s;
        int ans=s.size()+1;
        for(int i=0;i+2<(int)s.size();++i){
            int ops=0;
            if(s[i+1]!='O') ops++;
            ops+=(s[i]!='M');
            ops+=(s[i+2]!='O');
            ops+=i + (s.size()-i-3);
            ans=min(ans,ops);
        }
        cout<<(ans>(int)s.size()?-1:ans)<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
