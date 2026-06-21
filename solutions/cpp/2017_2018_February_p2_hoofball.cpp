/*
USACO Bronze: Hoofball
Season: 2017-2018
Contest: February
Problem: 2
Tags: SORT, SIM

Approach note:
Primary pattern: Sorting / Ordering (排序). After sorting, inspect neighbors, prefixes, suffixes, or endpoints. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x.begin(), x.end());

    // Determine pass direction for each cow
    vector<int> nxt(N);
    for (int i = 0; i < N; ++i) {
        if (i == 0) nxt[i] = 1;
        else if (i == N - 1) nxt[i] = N - 2;
        else {
            int left = x[i] - x[i-1];
            int right = x[i+1] - x[i];
            nxt[i] = (left <= right) ? i - 1 : i + 1;
        }
    }

    vector<int> indeg(N, 0);
    for (int i = 0; i < N; ++i) indeg[nxt[i]]++;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (indeg[i] == 0) ans++;
        else if (i < N - 1 && nxt[i] == i + 1 && nxt[i+1] == i
                 && indeg[i] == 1 && indeg[i+1] == 1) ans++;
    }
    cout << ans << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
