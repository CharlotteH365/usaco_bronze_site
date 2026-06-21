/*
USACO Bronze: Word Processor
Season: 2019-2020
Contest: January
Problem: 1
Tags: SIM, STR

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: simulate the process step by step
    int N,K; cin>>N>>K;
    vector<string> words(N);
    for(int i=0;i<N;++i) cin>>words[i];
    int cur=0;
    for(int i=0;i<N;++i){
        if(cur+words[i].size()>K){
            cout<<"\n"; cur=0;
        }
        if(cur>0) cout<<" ";
        cout<<words[i];
        cur+=words[i].size();
    }
    cout<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
