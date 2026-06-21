/*
USACO Bronze: Leaders
Season: 2022-2023
Contest: January
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
    vector<int> E(N);
    for(int i=0;i<N;++i){cin>>E[i];E[i]--;}
    int fg=s.find('G'),lg=s.rfind('G');
    int fh=s.find('H'),lh=s.rfind('H');
    bool leadG=(fg!=-1&&E[fg]>=lg);
    bool leadH=(fh!=-1&&E[fh]>=lh);
    int ans=(leadG&&leadH);
    for(int i=0;i<N;++i){
        if(s[i]=='G'&&leadH&&E[i]>=fh&&i<fh) ans++;
        if(s[i]=='H'&&leadG&&E[i]>=fg&&i<fg) ans++;
    }
    cout<<ans<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
