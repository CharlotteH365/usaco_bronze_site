/*
USACO Bronze: Drought
Season: 2021-2022
Contest: January
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
    // Key: make locally optimal choices
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<long long> h(N);
        for(int i=0;i<N;++i) cin>>h[i];
        long long ans=0; bool ok=true;
        for(int i=0;i<N-1;++i){
            if(h[i]<0){ok=false;break;}
            ans+=h[i]*2;
            h[i+1]-=h[i];
            h[i]=0;
        }
        if(ok&&h[N-1]==0) cout<<ans<<"\n";
        else cout<<"-1\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
