/*
USACO Bronze: Block Game
Season: 2016-2017
Contest: December
Problem: 2
Tags: STR, COUNT

Approach note:
Primary pattern: String (字符串). For each spelling board, take the max frequency of each letter
between the two sides. Sum these maxima across all boards to get the total blocks needed per letter.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process string characters with counting or matching
    int N; cin >> N;
    vector<int> total(26,0);
    for (int k=0;k<N;++k) {
        string a,b; cin>>a>>b;
        vector<int> ca(26,0),cb(26,0);
        for(char c:a) ca[c-'a']++;
        for(char c:b) cb[c-'a']++;
        for(int i=0;i<26;++i) total[i]+=max(ca[i],cb[i]);
    }
    for(int x:total) cout<<x<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
