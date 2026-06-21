/*
USACO Bronze: Milk Exchange
Season: 2023-2024
Contest: February
Problem: 2
Tags: SIM, MATH

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
    int N,M; cin>>N>>M;
    vector<int> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    vector<int> res(N);
    for(int i=0;i<N;++i) res[(i+M)%N]=a[i];
    int mn=*min_element(res.begin(),res.end());
    cout<<mn<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
