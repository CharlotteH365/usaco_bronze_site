/*
USACO Bronze: FEB
Season: 2022-2023
Contest: US Open
Problem: 1
Tags: STR, COUNT, ADHOC

Approach note:
Primary pattern: String Processing (字符串). Think in substrings, character counts, ordering, and pattern matching. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; string s; cin>>N>>s;
    if(count(s.begin(),s.end(),'F')==N){
        cout<<N<<"\n";
        for(int i=0;i<N;++i) cout<<i<<"\n";
        return;
    }
    string a=s,b=s;
    // Max excitement: fill F with neighbor
    for(int i=0;i<N;++i){
        if(a[i]=='F'){
            if(i>0&&a[i-1]!='F') a[i]=a[i-1];
            else if(i<N-1&&a[i+1]!='F') a[i]=a[i+1];
            else a[i]='B';
        }
    }
    int mx=0;
    for(int i=0;i<N-1;++i) if(a[i]==a[i+1]) mx++;
    // Min excitement
    for(int i=0;i<N;++i){
        if(b[i]=='F'){
            if(i>0&&b[i-1]!='F') b[i]=(b[i-1]=='B'?'E':'B');
            else if(i<N-1&&b[i+1]!='F') b[i]=(b[i+1]=='B'?'E':'B');
            else b[i]='B';
        }
    }
    int mn=0;
    for(int i=0;i<N-1;++i) if(b[i]==b[i+1]) mn++;
    int step=2;
    if(s[0]=='F'||s[N-1]=='F') step=1;
    vector<int> res;
    for(int i=mn;i<=mx;i+=step) res.push_back(i);
    cout<<res.size()<<"\n";
    for(int x:res) cout<<x<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
