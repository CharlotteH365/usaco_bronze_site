/*
USACO Bronze: Cowntact Tracing
Season: 2019-2020
Contest: US Open
Problem: 3
Tags: SEARCH, SIM

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
    int N,T; cin>>N>>T;
    string final_state; cin>>final_state;
    vector<tuple<int,int,int>> inter(T);
    for(int i=0;i<T;++i){
        int t,x,y; cin>>t>>x>>y; --x;--y;
        inter[i]={t,x,y};
    }
    sort(inter.begin(),inter.end());
    int possible_zero=0, min_K=T+1, max_K=-1;
    for(int pz=0;pz<N;++pz){
        if(final_state[pz]=='0') continue;
        bool found=false;
        for(int K=0;K<=T;++K){
            vector<bool> inf(N,false);
            vector<int> shakes(N,0);
            inf[pz]=true;
            for(auto&[t,x,y]:inter){
                if(inf[x]) shakes[x]++;
                if(inf[y]) shakes[y]++;
                if(inf[x] && shakes[x]<=K) inf[y]=true;
                if(inf[y] && shakes[y]<=K) inf[x]=true;
            }
            bool match=true;
            for(int i=0;i<N;++i)
                if(inf[i]!=(final_state[i]=='1')){match=false;break;}
            if(match){found=true;min_K=min(min_K,K);max_K=max(max_K,K);}
        }
        if(found) possible_zero++;
    }
    if(max_K==T) cout<<possible_zero<<" "<<min_K<<" Infinity\n";
    else cout<<possible_zero<<" "<<min_K<<" "<<max_K<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
