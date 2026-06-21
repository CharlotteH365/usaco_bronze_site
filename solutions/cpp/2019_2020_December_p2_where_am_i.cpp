/*
USACO Bronze: Where Am I?
Season: 2019-2020
Contest: December
Problem: 2
Tags: STR, SEARCH

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
    int N; string s; cin>>N>>s;
    for(int K=1;K<=N;++K){
        set<string> seen; bool ok=true;
        for(int i=0;i+K<=N;++i){
            string sub=s.substr(i,K);
            if(seen.count(sub)){ok=false;break;}
            seen.insert(sub);
        }
        if(ok){cout<<K<<"\n";return;}
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
