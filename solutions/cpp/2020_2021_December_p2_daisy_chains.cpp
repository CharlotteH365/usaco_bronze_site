/*
USACO Bronze: Daisy Chains
Season: 2020-2021
Contest: December
Problem: 2
Tags: SEARCH, COUNT

Approach note:
Primary pattern: Complete Search / Brute Force (枚举 / 暴力). Use constraints to choose enumeration depth; keep validation in a clean check function. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: enumerate all possibilities within constraints
    int N; cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;++i) cin>>p[i];
    int ans=0;
    for(int i=0;i<N;++i){
        int sum=0;
        for(int j=i;j<N;++j){
            sum+=p[j];
            int len=j-i+1;
            if(sum%len==0){
                int avg=sum/len;
                for(int k=i;k<=j;++k)
                    if(p[k]==avg){ans++;break;}
            }
        }
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
