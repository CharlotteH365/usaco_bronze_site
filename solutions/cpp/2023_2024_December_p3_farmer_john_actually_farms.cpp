/*
USACO Bronze: Farmer John Actually Farms
Season: 2023-2024
Contest: December
Problem: 3
Tags: MATH, ADHOC

Approach note:
Primary pattern: Math / Number Patterns (数学规律). Generate small cases, identify parity/modulo/divisibility patterns, then prove bounds. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: apply mathematical formulas and parity patterns
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<long long> h(N),g(N),t(N);
        for(int i=0;i<N;++i) cin>>h[i];
        for(int i=0;i<N;++i) cin>>g[i];
        for(int i=0;i<N;++i) cin>>t[i];
        auto possible=[&](long long days){
            vector<long long> fin(N);
            for(int i=0;i<N;++i) fin[i]=h[i]+g[i]*days;
            vector<int> ord(N);
            iota(ord.begin(),ord.end(),0);
            sort(ord.begin(),ord.end(),[&](int a,int b){return fin[a]<fin[b];});
            for(int i=0;i<N;++i) if(t[ord[i]]!=i) return false;
            return true;
        };
        long long lo=0,hi=1e9,ans=-1;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(possible(mid)){ans=mid;hi=mid-1;}
            else lo=mid+1;
        }
        cout<<ans<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
