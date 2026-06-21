/*
USACO Bronze: Photoshoot 2
Season: 2021-2022
Contest: February
Problem: 2
Tags: SORT, ADHOC

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
    string A,B; cin>>A>>B;
    vector<int> posG,posH;
    for(int i=0;i<N;++i){
        if(A[i]=='G') posG.push_back(i);
        else posH.push_back(i);
    }
    int gi=0,hi=0;
    vector<int> arr(N);
    for(int i=0;i<N;++i){
        if(B[i]=='G') arr[i]=posG[gi++];
        else arr[i]=posH[hi++];
    }
    int inv=0;
    for(int i=0;i<N;++i)
        for(int j=i+1;j<N;++j)
            if(arr[i]>arr[j]) inv++;
    cout<<inv<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
