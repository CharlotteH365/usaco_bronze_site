/*
USACO Bronze: Logical Moos
Season: 2023-2024
Contest: US Open
Problem: 1
Tags: STR, LOGIC, PREFIX

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
    int N,Q; cin>>N>>Q;
    vector<string> tok(N);
    for(int i=0;i<N;++i) cin>>tok[i];
    vector<bool> vals(N/2+1);
    for(int i=0;i<N;i+=2) vals[i/2]=(tok[i]=="true");
    while(Q--){
        int idx; string nv; cin>>idx>>nv; idx--;
        vals[idx/2]=(nv=="true");
        bool res=vals[0];
        for(int i=2;i<N;i+=2){
            if(tok[i-1]=="and") res=res&&vals[i/2];
            else res=res||vals[i/2];
        }
        cout<<(res?"true":"false")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
