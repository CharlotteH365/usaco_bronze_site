/*
USACO Bronze: Watching Mooloo
Season: 2022-2023
Contest: February
Problem: 3
Tags: GREEDY, MATH

Approach note:
Primary pattern: Greedy (贪心). Sort or normalize the input, then justify why the local choice is safe. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; long long K; cin>>N>>K;
    vector<long long> days(N);
    for(int i=0;i<N;++i) cin>>days[i];
    sort(days.begin(),days.end());
    // First subscription covers days[0] through days[0]+K
    long long ans=K+1, covered=days[0]+K;
    for(int i=1;i<N;++i){
        long long d=days[i];
        if(d>covered){
            // Cheaper to extend or start new?
            long long ext=d-covered;
            if(ext<K+1) ans+=ext;
            else ans+=K+1;
            covered=d+K;
        }
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
