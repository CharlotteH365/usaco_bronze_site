/*
USACO Bronze: Mixing Milk
Season: 2018-2019
Contest: December
Problem: 1
Tags: SIM

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
    int cap[3],milk[3];
    for(int i=0;i<3;++i) cin>>cap[i]>>milk[i];
    for(int step=0;step<100;++step){
        int i=step%3, j=(i+1)%3;
        int pour=min(milk[i],cap[j]-milk[j]);
        milk[i]-=pour; milk[j]+=pour;
    }
    for(int m:milk) cout<<m<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
