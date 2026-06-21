/*
USACO Bronze: Lifeguards
Season: 2017-2018
Contest: January
Problem: 2
Tags: SORT, INTERVAL

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
    int N;
    cin >> N;
    vector<pair<int,int>> iv(N);
    for (int i = 0; i < N; ++i) cin >> iv[i].first >> iv[i].second;

    const int MAXT = 1000;
    int best = 0;
    for (int i = 0; i < N; ++i) {
        vector<int> cov(MAXT + 1, 0);
        for (int j = 0; j < N; ++j) {
            if (j == i) continue;
            for (int t = iv[j].first; t < iv[j].second; ++t) cov[t] = 1;
        }
        best = max(best, accumulate(cov.begin(), cov.end(), 0));
    }
    cout << best << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
