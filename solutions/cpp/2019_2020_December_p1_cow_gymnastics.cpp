/*
USACO Bronze: Cow Gymnastics
Season: 2019-2020
Contest: December
Problem: 1
Tags: COUNT, SEARCH

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
    int K,N; cin>>K>>N;
    vector<vector<int>> ranks(K,vector<int>(N));
    for(int i=0;i<K;++i)
        for(int j=0;j<N;++j) cin>>ranks[i][j];
    int pairs=0;
    for(int a=1;a<=N;++a){
        for(int b=1;b<=N;++b){
            if(a==b) continue;
            bool ok=true;
            for(auto&s:ranks){
                int pa=-1,pb=-1;
                for(int j=0;j<N;++j){
                    if(s[j]==a) pa=j;
                    if(s[j]==b) pb=j;
                }
                if(pa>pb){ok=false;break;}
            }
            if(ok) pairs++;
        }
    }
    cout<<pairs<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
