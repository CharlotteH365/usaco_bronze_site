/*
USACO Bronze: Back and Forth
Season: 2018-2019
Contest: December
Problem: 3
Tags: SEARCH, SET

Approach note:
Primary pattern: Complete Search / Brute Force (枚举 / 暴力). Use constraints to choose enumeration depth; keep validation in a clean check function. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: enumerate all possibilities within constraints
    vector<int> a(10),b(10);
    for(int i=0;i<10;++i) cin>>a[i];
    for(int i=0;i<10;++i) cin>>b[i];
    set<int> possible;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            vector<int> a1=a,b1=b;
            int x=a1[i]; a1.erase(a1.begin()+i); b1.push_back(x);
            int y=b1[j]; b1.erase(b1.begin()+j); a1.push_back(y);
            for(int k=0;k<(int)a1.size();++k){
                for(int l=0;l<(int)b1.size();++l){
                    vector<int> a2=a1,b2=b1;
                    int x2=a2[k]; a2.erase(a2.begin()+k); b2.push_back(x2);
                    int y2=b2[l]; b2.erase(b2.begin()+l); a2.push_back(y2);
                    int sum=accumulate(a2.begin(),a2.end(),0);
                    possible.insert(sum);
                }
            }
        }
    }
    cout<<possible.size()<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
