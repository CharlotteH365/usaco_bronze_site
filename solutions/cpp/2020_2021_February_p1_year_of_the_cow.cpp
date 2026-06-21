/*
USACO Bronze: Year of the Cow
Season: 2020-2021
Contest: February
Problem: 1
Tags: SORT, MATH

Approach note:
Primary pattern: Sorting / Ordering (排序). After sorting, inspect neighbors, prefixes, suffixes, or endpoints. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: sort then process greedily
    int N; cin>>N;
    vector<string> zod={"Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"};
    map<string,int> zidx;
    for(int i=0;i<12;++i) zidx[zod[i]]=i;
    map<string,int> year; year["Bessie"]=0;
    for(int i=0;i<N;++i){
        string a,_,__,dir,ani,___,____,b;
        cin>>a>>_>>__>>dir>>ani>>___>>____>>b;
        int by=year[b], target=zidx[ani];
        int cur=((by%12)+12)%12;
        if(dir=="previous"){
            int diff=(cur-target+12)%12;
            if(diff==0) diff=12;
            year[a]=by-diff;
        } else {
            int diff=(target-cur+12)%12;
            if(diff==0) diff=12;
            year[a]=by+diff;
        }
    }
    cout<<abs(year["Elsie"])<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
