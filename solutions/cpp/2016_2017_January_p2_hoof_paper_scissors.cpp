/*
USACO Bronze: Hoof, Paper, Scissors
Season: 2016-2017
Contest: January
Problem: 2
Tags: COUNT, ADHOC

Approach note:
Primary pattern: Enumerate all mapping permutations and all strategy splits.
N <= 100 so O(6 * 3 * 3 * N^2) is fine. For each of 6 mappings of (1,2,3)->(H,P,S),
try every pair of gestures for first / rest and every split point k.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

// gesture A beats gesture B if (A+1)%3 == B  (0=H, 1=P, 2=S)
bool beats(int a, int b) {
    return (a + 1) % 3 == b;
}

void solve() {
    // Key: count frequencies with arrays/maps
    int N; cin>>N;
    vector<int> a(N),b(N);
    for(int i=0;i<N;++i) cin>>a[i]>>b[i];
    int best=0;
    for(int x=0;x<3;++x){
        for(int y=0;y<3;++y){
            if(x==y) continue;
            int z=3-x-y;
            int mp[4]={0,x,y,z};
            int wins=0;
            for(int i=0;i<N;++i){
                int g1=mp[a[i]], g2=mp[b[i]];
                if((g1==0&&g2==2)||(g1==1&&g2==0)||(g1==2&&g2==1)) wins++;
            }
            best=max(best,wins);
        }
    }
    cout<<best<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
