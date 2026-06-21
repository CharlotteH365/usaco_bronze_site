/*
USACO Bronze: Palindrome Game
Season: 2023-2024
Contest: February
Problem: 1
Tags: STR, GAME, ADHOC

Approach note:
Primary pattern: String Processing (字符串). Think in substrings, character counts, ordering, and pattern matching. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        int n=s.size(),diff=0;
        for(int i=0;i<n/2;++i) if(s[i]!=s[n-1-i]) diff++;
        if(diff==0) cout<<"B\n";  // already palindrome
        else cout<<(diff%2?"E":"B")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
