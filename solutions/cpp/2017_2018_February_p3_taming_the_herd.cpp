/*
USACO Bronze: Taming the Herd
Season: 2017-2018
Contest: February
Problem: 3
Tags: ARRAY, ADHOC

Approach note:
Primary pattern: Array Reasoning (数组). Track positions, values, and local changes carefully. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    if (a[0] > 0) { cout << "-1\n"; return; }
    a[0] = 0;

    // Forward consistency check
    for (int i = 1; i < N; ++i) {
        if (a[i] > 0) {
            int expected = a[i] - 1;
            if (a[i-1] != -1 && a[i-1] != expected) {
                cout << "-1\n"; return;
            }
            a[i-1] = expected;
        }
    }

    // Backward fill
    for (int i = N-1; i > 0; --i)
        if (a[i] > 0 && a[i-1] == -1)
            a[i-1] = a[i] - 1;

    int mn = 0, mx = 0;
    for (int v : a) {
        if (v == 0) { mn++; mx++; }
        else if (v == -1) mx++;
    }
    cout << mn << " " << mx << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
