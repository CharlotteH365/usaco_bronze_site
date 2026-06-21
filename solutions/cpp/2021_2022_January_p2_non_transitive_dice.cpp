/*
USACO Bronze: Non-Transitive Dice
Season: 2021-2022
Contest: January
Problem: 2
Tags: SEARCH, COUNT

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
    int T; cin>>T;
    auto beats=[&](vector<int>&X,vector<int>&Y){
        int w=0;
        for(int x:X) for(int y:Y){
            if(x>y) w++; else if(x<y) w--;
        }
        return w>0;
    };
    while(T--){
        vector<int> A(4),B(4);
        for(int i=0;i<4;++i) cin>>A[i];
        for(int i=0;i<4;++i) cin>>B[i];
        bool found=false;
        for(int a=1;a<=10&&!found;++a)
        for(int b=1;b<=10&&!found;++b)
        for(int c=1;c<=10&&!found;++c)
        for(int d=1;d<=10&&!found;++d){
            vector<int> C={a,b,c,d};
            bool ab=beats(A,B),bc=beats(B,C),ca=beats(C,A);
            if(ab&&bc&&ca){cout<<"yes\n";found=true;}
            else if(!ab&&!bc&&!ca&&beats(B,A)&&beats(C,B)&&beats(A,C)){cout<<"yes\n";found=true;}
        }
        if(!found) cout<<"no\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
