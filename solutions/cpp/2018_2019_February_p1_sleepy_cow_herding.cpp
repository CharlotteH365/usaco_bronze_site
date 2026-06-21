/*
USACO Bronze: Sleepy Cow Herding
Season: 2018-2019
Contest: February
Problem: 1
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
    int a[3]; cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int mn;
    if(a[2]-a[0]==2) mn=0;
    else if(a[1]-a[0]==2||a[2]-a[1]==2) mn=1;
    else mn=2;
    int mx=max(a[1]-a[0],a[2]-a[1])-1;
    cout<<mn<<"\n"<<mx<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
