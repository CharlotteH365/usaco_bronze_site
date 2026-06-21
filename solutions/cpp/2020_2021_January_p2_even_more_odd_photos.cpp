/*
USACO Bronze: Even More Odd Photos
Season: 2020-2021
Contest: January
Problem: 2
Tags: COUNT, GREEDY

Approach note:
Primary pattern: Counting / Frequency (计数 / 频率). Use arrays, maps, sets, or contribution counting instead of repeated scans. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: count frequencies with arrays/maps
    int N; cin>>N;
    int odd=0,even=0;
    for(int i=0;i<N;++i){int x;cin>>x;if(x%2) odd++;else even++;}
    int ans=0, need=0;
    while(true){
        if(need==0){
            if(even>0){even--;ans++;}
            else if(odd>=2){odd-=2;ans++;}
            else break;
        } else {
            if(odd>0){odd--;ans++;}
            else break;
        }
        need^=1;
    }
    if(odd%2==1 && ans>0) ans--;
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
