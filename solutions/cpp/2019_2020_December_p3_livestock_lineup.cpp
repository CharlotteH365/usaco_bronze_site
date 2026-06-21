/*
USACO Bronze: Livestock Lineup
Season: 2019-2020
Contest: December
Problem: 3
Tags: SEARCH, SORT

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
    int N; cin>>N;
    vector<pair<string,string>> cons(N);
    for(int i=0;i<N;++i){
        string a,b,w;
        cin>>a>>w>>w>>w>>w>>b;
        cons[i]={a,b};
    }
    vector<string> cows={"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    sort(cows.begin(),cows.end());
    do{
        bool ok=true;
        for(auto&[a,b]:cons){
            int pa=find(cows.begin(),cows.end(),a)-cows.begin();
            int pb=find(cows.begin(),cows.end(),b)-cows.begin();
            if(abs(pa-pb)!=1){ok=false;break;}
        }
        if(ok){
            for(auto&c:cows) cout<<c<<"\n";
            return;
        }
    }while(next_permutation(cows.begin(),cows.end()));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
