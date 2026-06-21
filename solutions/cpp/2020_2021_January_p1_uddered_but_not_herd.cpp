/*
USACO Bronze: Uddered but not Herd
Season: 2020-2021
Contest: January
Problem: 1
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
    string cow, heard; cin>>cow>>heard;
    int pos[26];
    for(int i=0;i<26;++i) pos[cow[i]-'a']=i;
    int ans=1;
    for(int i=1;i<(int)heard.size();++i)
        if(pos[heard[i]-'a']<=pos[heard[i-1]-'a']) ans++;
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
