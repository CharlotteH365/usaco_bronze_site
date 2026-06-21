/*
USACO Bronze: Counting Liars
Season: 2021-2022
Contest: US Open
Problem: 2
Tags: SORT, COUNT

Approach note:
Primary pattern: Sorting / Ordering (排序). After sorting, inspect neighbors, prefixes, suffixes, or endpoints. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: sort then process greedily
    int N; cin>>N;
    vector<pair<char,int>> cows(N);
    set<double> positions;
    for(int i=0;i<N;++i){
        cin>>cows[i].first>>cows[i].second;
        positions.insert(cows[i].second-0.5);
        positions.insert(cows[i].second+0.5);
    }
    int best=N;
    for(double pos:positions){
        int liars=0;
        for(auto&[d,p]:cows){
            if(d=='G'&&pos<p) liars++;
            if(d=='L'&&pos>p) liars++;
        }
        best=min(best,liars);
    }
    cout<<best<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
