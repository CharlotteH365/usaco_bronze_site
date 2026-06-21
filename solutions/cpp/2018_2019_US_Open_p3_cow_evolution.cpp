/*
USACO Bronze: Cow Evolution
Season: 2018-2019
Contest: US Open
Problem: 3
Tags: SET, SEARCH

Approach note:
Primary pattern: Sets (集合). Use uniqueness and membership tests to simplify repeated comparisons. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: use set operations for uniqueness checks
    int N; cin>>N;
    vector<set<string>> cows(N);
    set<string> all_traits;
    for(int i=0;i<N;++i){
        string name; int K; cin>>name>>K;
        for(int j=0;j<K;++j){string t;cin>>t;cows[i].insert(t);all_traits.insert(t);}
    }
    vector<string> tl(all_traits.begin(),all_traits.end());
    for(int i=0;i<(int)tl.size();++i){
        for(int j=i+1;j<(int)tl.size();++j){
            string t1=tl[i],t2=tl[j];
            int only1=0,only2=0,both=0;
            for(auto&ct:cows){
                bool h1=ct.count(t1),h2=ct.count(t2);
                if(h1&&!h2) only1++;
                else if(h2&&!h1) only2++;
                else if(h1&&h2) both++;
            }
            if(only1>0 && only2>0 && both>0){cout<<"no\n";return;}
        }
    }
    cout<<"yes\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
