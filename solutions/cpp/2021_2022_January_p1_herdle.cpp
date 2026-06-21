/*
USACO Bronze: Herdle
Season: 2021-2022
Contest: January
Problem: 1
Tags: STR, COUNT

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
    string ans[3],guess[3];
    for(int i=0;i<3;++i) cin>>ans[i];
    for(int i=0;i<3;++i) cin>>guess[i];
    int green=0,ac[26]={},gc[26]={};
    for(int i=0;i<3;++i) for(int j=0;j<3;++j){
        if(ans[i][j]==guess[i][j]) green++;
        else{ac[ans[i][j]-'A']++;gc[guess[i][j]-'A']++;}
    }
    int yellow=0;
    for(int i=0;i<26;++i) yellow+=min(ac[i],gc[i]);
    cout<<green<<"\n"<<yellow<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
