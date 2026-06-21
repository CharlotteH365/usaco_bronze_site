/*
USACO Bronze: Race
Season: 2019-2020
Contest: January
Problem: 3
Tags: MATH, SIM

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
    int K,N; cin>>K>>N;
    while(N--){
        int X; cin>>X;
        int speed=1,time=0;
        long long dist=0;
        while(true){
            dist+=speed; time++;
            if(dist>=K) break;
            if(speed>=X){
                long long need=0;
                for(int v=speed;v>=X;--v) need+=v;
                if(dist+speed+1+need<=K) speed++;
                else if(dist+need>K) speed--;
            } else speed++;
        }
        cout<<time<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
