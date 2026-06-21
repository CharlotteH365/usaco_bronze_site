/*
USACO Bronze: Reverse Engineering
Season: 2022-2023
Contest: December
Problem: 3
Tags: SEARCH, LOGIC

Approach note:
Primary pattern: Complete Search / Brute Force (枚举 / 暴力). Use constraints to choose enumeration depth; keep validation in a clean check function. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: enumerate all possibilities within constraints
    int T; cin>>T;
    while(T--){
        int N,M; cin>>N>>M;
        vector<string> in(M);
        vector<int> out(M);
        for(int i=0;i<M;++i) cin>>in[i]>>out[i];
        vector<bool> used(M,false);
        bool ok=true;
        for(int step=0;step<M;++step){
            bool found=false;
            for(int pos=0;pos<N&&!found;++pos){
                for(char val='0';val<='1'&&!found;++val){
                    for(int res=0;res<=1&&!found;++res){
                        vector<int> match;
                        for(int i=0;i<M;++i)
                            if(!used[i]&&in[i][pos]==val&&out[i]==res) match.push_back(i);
                        if(!match.empty()){
                            for(int i:match) used[i]=true;
                            found=true;
                        }
                    }
                }
            }
            if(!found){ok=false;break;}
        }
        cout<<(ok?"OK":"LIE")<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
