/*
USACO Bronze: Do You Know Your ABCs?
Season: 2020-2021
Contest: December
Problem: 1
Tags: SEARCH, MATH

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
    vector<int> nums(7);
    for(int i=0;i<7;++i) cin>>nums[i];
    sort(nums.begin(),nums.end());
    int A=nums[0], B=nums[1];
    int C=nums[6]-A-B;
    cout<<A<<" "<<B<<" "<<C<<"\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
