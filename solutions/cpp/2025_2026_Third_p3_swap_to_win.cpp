/*
USACO Bronze: Swap to Win
Season: 2025-2026
Contest: Third
Problem: 3
Tags: GREEDY, SORT, ADHOC

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
    vector<int> a(N),b(N);
    for(int i=0;i<N;++i) cin>>a[i];
    for(int i=0;i<N;++i) cin>>b[i];
    auto inv=[&](vector<int>&arr){
        int cnt=0;
        for(int i=0;i<(int)arr.size();++i)
            for(int j=i+1;j<(int)arr.size();++j)
                if(arr[i]>arr[j]) cnt++;
        return cnt;
    };
    cout<<inv(a)+inv(b)<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
