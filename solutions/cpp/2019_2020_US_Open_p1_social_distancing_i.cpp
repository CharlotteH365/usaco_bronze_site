/*
USACO Bronze: Social Distancing I
Season: 2019-2020
Contest: US Open
Problem: 1
Tags: GREEDY, STR

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
    int N; string s; cin>>N>>s;
    auto can=[&](int D){
        int cnt=0,last=-1e9;
        for(int i=0;i<N;++i){
            if(s[i]=='1'){
                if(i-last<D) return false;
                last=i;
            } else if(i-last>=D){
                cnt++; last=i;
            }
        }
        return cnt>=2;
    };
    int lo=1,hi=N;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(can(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
