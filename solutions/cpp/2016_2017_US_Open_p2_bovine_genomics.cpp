/*
USACO Bronze: Bovine Genomics
Season: 2016-2017
Contest: US Open
Problem: 2
Tags: STR, COUNT

Approach note:
Primary pattern: For each position j in the genome string, collect the set of characters
from all plain cows and all spotted cows. If these two sets are disjoint (no common
character), then position j alone can determine breed.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process string characters with counting or matching
    int N,M; cin>>N>>M;
    vector<string> plain(N),spotted(N);
    for(int i=0;i<N;++i) cin>>plain[i];
    for(int i=0;i<N;++i) cin>>spotted[i];
    int ans=0;
    for(int pos=0;pos<M;++pos){
        set<char> ps,ss;
        for(int i=0;i<N;++i) ps.insert(plain[i][pos]);
        for(int i=0;i<N;++i) ss.insert(spotted[i][pos]);
        bool ok=true;
        for(char c:ps) if(ss.count(c)){ok=false;break;}
        if(ok) ans++;
    }
    cout<<ans<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
