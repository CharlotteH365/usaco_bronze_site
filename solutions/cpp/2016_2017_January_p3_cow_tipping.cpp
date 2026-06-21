/*
USACO Bronze: Cow Tipping
Season: 2016-2017
Contest: January
Problem: 3
Tags: GRID, SIM

Approach note:
Primary pattern: Greedy from bottom-right. Process cells from (N-1,N-1) down to (0,0).
When the current effective value is 1 (after accounting for all flips applied so far),
we must flip the rectangle from (0,0) to this cell. Since N <= 10, O(N^4) brute
tracking of flip state is fine.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process the 2D grid with nested loops
    int N; cin>>N;
    vector<vector<int>> g(N,vector<int>(N));
    for(int i=0;i<N;++i){string s;cin>>s;for(int j=0;j<N;++j)g[i][j]=s[j]-'0';}
    int flips=0;
    for(int r=N-1;r>=0;--r)
        for(int c=N-1;c>=0;--c)
            if(g[r][c]==1){
                flips++;
                for(int i=0;i<=r;++i)
                    for(int j=0;j<=c;++j) g[i][j]^=1;
            }
    cout<<flips<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
