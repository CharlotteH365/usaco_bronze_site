/*
USACO Bronze: Roundabout Rounding
Season: 2024-2025
Contest: December
Problem: 1
Problem ID: cpid=1443
Tags: MATH, ADHOC

Problem:
Given N, count how many integers x in [1, N] such that:
  - "rounding x to nearest 10^b" ≠ "chain rounding x to nearest 10^b"
  - where b is the smallest power of 10 s.t. 10^b ≥ x.

Standard rounding: round to nearest 10^b directly.
Chain rounding: round to 10^1, then 10^2, ..., then 10^b sequentially.

Solution:
Numbers that differ: intervals [45,49], [445,499], [4445,4999], ...
Pattern: va = 45, vb = 49, then va = va*10-5, vb = vb*10+9.
Count how many numbers in these intervals are ≤ N.
O(log N) per test case.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        ll N; cin >> N;
        ll va = 45, vb = 49;
        ll ans = 0;
        while (va <= N) {
            if (vb <= N) ans += (vb - va + 1);
            else ans += (N - va + 1);
            va = va * 10 - 5;
            vb = vb * 10 + 9;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
