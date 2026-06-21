/*
USACO Bronze: Air Cownditioning
Season: 2021-2022
Contest: December
Problem: 2
Tags: GREEDY, PREFIX

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
    int N; cin>>N;
    vector<int> target(N),cur(N);
    for(int i=0;i<N;++i) cin>>target[i];
    for(int i=0;i<N;++i) cin>>cur[i];
    vector<int> diff(N);
    for(int i=0;i<N;++i) diff[i]=target[i]-cur[i];
    int ans=0,prev=0;
    for(int d:diff){
        if((d>0&&prev<=0)||(d<0&&prev>=0)) ans+=abs(d);
        else if(abs(d)>abs(prev)) ans+=abs(d)-abs(prev);
        prev=d;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
