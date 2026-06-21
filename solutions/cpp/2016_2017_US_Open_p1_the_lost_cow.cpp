/*
USACO Bronze: The Lost Cow
Season: 2016-2017
Contest: US Open
Problem: 1
Tags: SIM, MATH

Approach note:
Primary pattern: Simulate John's search pattern. John starts at x, Bessie at y.
John alternates direction and doubles distance each leg: +1, -2, +4, -8, ...
Accumulate total distance traveled. Stop as soon as Bessie lies between the
current position and the next target position (inclusive).

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: simulate the process step by step
    int x,y; cin>>x>>y;
    int pos=x, step=1, total=0;
    while(true){
        int target=x+step;
        if((step>0 && pos<=y && y<=target) || (step<0 && target<=y && y<=pos)){
            total+=abs(y-pos); break;
        }
        total+=abs(target-pos);
        pos=target;
        step*=-2;
    }
    cout<<total<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
