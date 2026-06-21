/*
USACO Bronze: Blocks
Season: 2021-2022
Contest: February
Problem: 3
Tags: STR, COUNT

Approach note:
Primary pattern: String Processing (字符串). Think in substrings, character counts, ordering, and pattern matching. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process string characters with counting or matching
    int N; cin>>N;
    pair<string,string> blocks[4];
    for(int i=0;i<4;++i) cin>>blocks[i].first>>blocks[i].second;
    while(N--){
        string word; cin>>word;
        bool ok=false;
        int perm[4]={0,1,2,3};
        do{
            for(int mask=0;mask<(1<<(int)word.size());++mask){
                bool can=true;
                for(int i=0;i<(int)word.size();++i){
                    int side=(mask>>i)&1;
                    auto&b=blocks[perm[i%4]];
                    if((side?b.second:b.first).find(word[i])==string::npos)
                    {can=false;break;}
                }
                if(can){ok=true;break;}
            }
            if(ok) break;
        }while(next_permutation(perm,perm+4));
        cout<<(ok?"YES":"NO")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
