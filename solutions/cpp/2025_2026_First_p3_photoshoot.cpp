/*
USACO Bronze: Photoshoot
Season: 2025-2026
Contest: First (January)
Problem: 3
Problem ID: cpid=1541
Tags: GRID, SIM, SLIDING WINDOW

Problem statement:
N×N grid (N ≤ 500), K×K camera (K ≤ min(N,25)).
Initially all beauty values = 0.
Q updates (Q ≤ 3e4): cow at (r,c) gets new beauty value v (v > previous value).
After each update, output max sum of any K×K subgrid.

Solution:
Since values only INCREASE, window sums are non-decreasing.
Global max only goes up.

Maintain grid[r][c] and window_sum[r1][c1] for each K×K window.
For each update (r,c,v):
  diff = v - grid[r][c]; grid[r][c] = v
  For each window (r1,c1) containing (r,c):
    window_sum[r1][c1] += diff
    global_max = max(global_max, window_sum[r1][c1])
  Output global_max

Each update affects at most K×K ≤ 625 windows.
O(Q * K^2) ≈ 1.9e7, fast.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K; cin >> N >> K;
    int Q; cin >> Q;

    vector<vector<ll>> grid(N + 1, vector<ll>(N + 1, 0));
    int W = N - K + 1; // number of window positions per dimension
    vector<vector<ll>> win(W, vector<ll>(W, 0));
    ll global_max = 0;

    while (Q--) {
        int r, c; ll v; cin >> r >> c >> v;
        --r; --c;
        ll diff = v - grid[r][c];
        grid[r][c] = v;

        // Affected windows: top-left corners from (r1,c1) to (r2,c2)
        int r1 = max(0, r - K + 1);
        int r2 = min(W - 1, r);
        int c1 = max(0, c - K + 1);
        int c2 = min(W - 1, c);

        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                win[i][j] += diff;
                if (win[i][j] > global_max) global_max = win[i][j];
            }
        }
        cout << global_max << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
