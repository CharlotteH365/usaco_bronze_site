/*
USACO Bronze: Sleeping in Class
Season: 2021-2022
Contest: February
Problem: 1
Tags: MATH, SEARCH

Approach note:
Primary pattern: Math / Number Patterns (数学规律). Generate small cases, identify parity/modulo/divisibility patterns, then prove bounds. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: apply mathematical formulas and parity patterns
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> a(N);
        int total=0;
        for(int i=0;i<N;++i){cin>>a[i];total+=a[i];}
        for(int num=N;num>=1;--num){
            if(total%num) continue;
            int target=total/num,cur=0;
            bool ok=true;
            for(int x:a){
                cur+=x;
                if(cur>target){ok=false;break;}
                if(cur==target) cur=0;
            }
            if(ok&&cur==0){cout<<N-num<<"\n";break;}
        }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
