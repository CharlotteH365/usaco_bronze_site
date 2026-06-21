/*
USACO Bronze: Lonely Photo
Season: 2021-2022
Contest: December
Problem: 1
Tags: STR, COUNT, PREFIX

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
    long long ans=0;
    for(int i=0;i<N;++i){
        int left=0, j=i-1;
        while(j>=0 && s[j]!=s[i]){left++;j--;}
        int right=0; j=i+1;
        while(j<N && s[j]!=s[i]){right++;j++;}
        ans+=(long long)left*right;
        if(left>=2) ans+=left-1;
        if(right>=2) ans+=right-1;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
