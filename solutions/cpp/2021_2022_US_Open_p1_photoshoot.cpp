/*
USACO Bronze: Photoshoot
Season: 2021-2022
Contest: US Open
Problem: 1
Tags: GREEDY, ADHOC

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
    int ans=0, need=0;
    for(int i=0;i<N;i+=2){
        if(s[i]=='G'&&s[i+1]=='H'){
            if(need==0){ans++;need=1;}
        } else if(s[i]=='H'&&s[i+1]=='G'){
            if(need==1){ans++;need=0;}
        }
    }
    if(need==0&&ans>0) ans--;
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
