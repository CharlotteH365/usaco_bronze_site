/*
USACO Bronze: Swapity Swap
Season: 2019-2020
Contest: February
Problem: 3
Tags: SIM, PERMUTATION

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N,K,a1,a2,b1,b2;
    cin>>N>>K>>a1>>a2>>b1>>b2;
    --a1;--a2;--b1;--b2;
    // Compute permutation after one round
    vector<int> p(N);
    iota(p.begin(),p.end(),0);
    reverse(p.begin()+a1,p.begin()+a2+1);
    reverse(p.begin()+b1,p.begin()+b2+1);
    // Find cycles and apply K rounds
    vector<int> ans(N);
    vector<bool> vis(N,false);
    for(int i=0;i<N;++i){
        if(!vis[i]){
            vector<int> cycle;
            int j=i;
            while(!vis[j]){
                vis[j]=true; cycle.push_back(j); j=p[j];
            }
            int L=cycle.size();
            for(int t=0;t<L;++t)
                ans[cycle[(t+K)%L]]=cycle[t]+1;
        }
    }
    for(int x:ans) cout<<x<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
