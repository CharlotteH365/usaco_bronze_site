/*
USACO Bronze: Why Did the Cow Cross the Road II
Season: 2016-2017
Contest: February
Problem: 2
Tags: STR, COUNT

Approach note:
Primary pattern: For each cow (A-Z), find its first and second position in the 52-char string.
Then count pairs (i,j) where entry[i] < entry[j] < exit[i] < exit[j], meaning the two
cows' paths cross.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: process string characters with counting or matching
    string s; cin>>s;
    int entry[26], ex[26];
    fill(entry,entry+26,-1);
    for(int i=0;i<52;++i){
        int idx=s[i]-'A';
        if(entry[idx]==-1) entry[idx]=i;
        else ex[idx]=i;
    }
    int pairs=0;
    for(int i=0;i<26;++i)
        for(int j=0;j<26;++j)
            if(i!=j && entry[i]<entry[j] && entry[j]<ex[i] && ex[i]<ex[j])
                pairs++;
    cout<<pairs<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
