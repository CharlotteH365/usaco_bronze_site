/*
USACO Bronze: Why Did the Cow Cross the Road
Season: 2016-2017
Contest: February
Problem: 1
Tags: COUNT, SIM

Approach note:
Primary pattern: Track the last seen side for each cow. When a cow is observed on a different
side than previously recorded, it must have crossed the road. Count these crossings.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: count frequencies with arrays/maps
    int N; cin>>N;
    map<int,int> last;
    int crossings=0;
    for(int i=0;i<N;++i){
        int cow,side; cin>>cow>>side;
        if(last.count(cow) && last[cow]!=side) crossings++;
        last[cow]=side;
    }
    cout<<crossings<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
