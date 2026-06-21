/*
USACO Bronze: Feeding the Cows
Season: 2022-2023
Contest: December
Problem: 2
Tags: GREEDY, STR

Approach note:
Primary pattern: Greedy (贪心). Sort or normalize the input, then justify why the local choice is safe. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: make locally optimal choices
    int T; cin>>T;
    while(T--){
        int N,K; string s; cin>>N>>K>>s;
        vector<char> ans(N,'.');
        int cnt=0, lg=-1e6, lh=-1e6;
        for(int i=0;i<N;++i){
            if(s[i]=='G'){
                if(lg+K<i){
                    int pos=min(i+K,N-1);
                    while(pos>=0&&ans[pos]!='.') pos--;
                    ans[pos]='G'; lg=pos; cnt++;
                }
            } else {
                if(lh+K<i){
                    int pos=min(i+K,N-1);
                    while(pos>=0&&ans[pos]!='.') pos--;
                    ans[pos]='H'; lh=pos; cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
        for(char c:ans) cout<<c;
        cout<<"\n";
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
