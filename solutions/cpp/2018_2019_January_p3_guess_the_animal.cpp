/*
USACO Bronze: Guess the Animal
Season: 2018-2019
Contest: January
Problem: 3
Tags: COUNT, SET

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
    vector<set<string>> traits(N);
    for(int i=0;i<N;++i){
        string name; int K; cin>>name>>K;
        for(int j=0;j<K;++j){string t;cin>>t;traits[i].insert(t);}
    }
    int best=0;
    for(int i=0;i<N;++i)
        for(int j=i+1;j<N;++j){
            int common=0;
            for(auto&t:traits[i]) if(traits[j].count(t)) common++;
            best=max(best,common+1);
        }
    cout<<best<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
