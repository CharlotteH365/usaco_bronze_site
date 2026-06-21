/*
USACO Bronze: Acowdemia I
Season: 2020-2021
Contest: US Open
Problem: 1
Tags: GREEDY, SORT

Approach note:
Primary pattern: Greedy (贪心). Sort or normalize the input, then justify why the local choice is safe. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: make locally optimal choices
    int N,L; cin>>N>>L;
    vector<int> p(N);
    for(int i=0;i<N;++i) cin>>p[i];
    sort(p.rbegin(),p.rend());
    auto can=[&](int h){
        int need=0;
        for(int i=0;i<h;++i){
            if(p[i]<h){
                need+=h-p[i];
                if(need>L||h-p[i]>1) return false;
            }
        }
        return true;
    };
    int lo=0,hi=N;
    while(lo<hi){int mid=(lo+hi+1)/2;if(can(mid))lo=mid;else hi=mid-1;}
    cout<<lo<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
