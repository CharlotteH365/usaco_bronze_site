/*
USACO Bronze: Cowntact Tracing 2
Season: 2023-2024
Contest: December
Problem: 2
Tags: STR, COUNT, ADHOC

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
    vector<tuple<int,int,int>> blocks;
    for(int i=0;i<N;){
        if(s[i]=='1'){
            int j=i;
            while(j<N&&s[j]=='1') j++;
            blocks.push_back({i,j-1,j-i});
            i=j;
        } else i++;
    }
    if(blocks.empty()){cout<<"0\n";return;}
    int mn=N;
    for(auto&[l,r,len]:blocks){
        if(l==0||r==N-1) mn=min(mn,len-1);
        else mn=min(mn,(len-1)/2);
    }
    int ans=0, spread=2*mn+1;
    for(auto&[l,r,len]:blocks)
        ans+=(len+spread-1)/spread;
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
