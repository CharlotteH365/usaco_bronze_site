/*
USACO Bronze: The Cow Signal
Season: 2016-2017
Contest: December
Problem: 3
Tags: GRID, SIM

Approach note:
Primary pattern: Simulation (模拟). Scale each character in the M x N grid to a K x K block
in the output. Simply iterate over the input grid row by row, repeating each row K times
and each character K times.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process the 2D grid with nested loops
    int M,N,K; cin>>M>>N>>K;
    for(int i=0;i<M;++i){
        string row; cin>>row;
        string expanded;
        for(char c:row) expanded+=string(K,c);
        for(int k=0;k<K;++k) cout<<expanded<<"\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
