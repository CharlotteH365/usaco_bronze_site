/*
USACO Bronze: Clockwise Fence
Season: 2020-2021
Contest: February
Problem: 3
Tags: GEOMETRY, STR

Approach note:
Primary pattern: Geometry (几何). Use coordinates, areas, distances, intersections, and orientation. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: compute areas and overlap of axis-aligned rectangles
    int N; cin>>N;
    while(N--){
        string s; cin>>s;
        map<char,int> dm={{'N',0},{'E',1},{'S',2},{'W',3}};
        int turns=0, prev=dm[s[0]];
        for(int i=1;i<(int)s.size();++i){
            int cur=dm[s[i]];
            int diff=(cur-prev+4)%4;
            if(diff==1) turns++;
            else if(diff==3) turns--;
            prev=cur;
        }
        cout<<(turns>0?"CW":"CCW")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
