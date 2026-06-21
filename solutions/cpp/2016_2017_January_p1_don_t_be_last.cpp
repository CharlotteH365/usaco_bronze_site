/*
USACO Bronze: Don't Be Last!
Season: 2016-2017
Contest: January
Problem: 1
Tags: SORT, COUNT

Approach note:
Primary pattern: Simulate changes then sort by value. Track milk production for 7 named cows.
After all updates, find the cow(s) with the second-lowest unique production value.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: sort then process greedily
    int N; cin>>N;
    map<string,int> prod;
    for(int i=0;i<N;++i){string name;int amt;cin>>name>>amt;prod[name]+=amt;}
    set<int> totals;
    for(auto&p:prod) totals.insert(p.second);
    if(totals.size()<2){cout<<"Tie\n";return;}
    auto it=totals.begin();++it;
    int second=*it;
    vector<string> cows;
    for(auto&p:prod) if(p.second==second) cows.push_back(p.first);
    if(cows.size()==1) cout<<cows[0]<<"\n";
    else cout<<"Tie\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
