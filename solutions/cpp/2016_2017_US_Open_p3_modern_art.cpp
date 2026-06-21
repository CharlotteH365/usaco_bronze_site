/*
USACO Bronze: Modern Art
Season: 2016-2017
Contest: US Open
Problem: 3
Tags: GRID, SEARCH

Approach note:
Primary pattern: For each color 1-9 that appears in the canvas, find its bounding rectangle.
A color X cannot have been painted first if any of X's visible cells lie within another
color Y's bounding rectangle — that would mean Y was painted first (covering that cell)
and X was painted on top. Count colors that could be first.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // Find bounding rectangle for each color
    int min_r[10], max_r[10], min_c[10], max_c[10];
    bool present[10] = {false};
    for (int d = 1; d <= 9; d++) {
        min_r[d] = INF; max_r[d] = -1;
        min_c[d] = INF; max_c[d] = -1;
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int d = grid[r][c] - '0';
            if (d > 0) {
                present[d] = true;
                min_r[d] = min(min_r[d], r);
                max_r[d] = max(max_r[d], r);
                min_c[d] = min(min_c[d], c);
                max_c[d] = max(max_c[d], c);
            }
        }
    }

    // Color X cannot be first if any cell of X lies within another Y's bounding rect
    int can_be_first = 0;
    for (int x = 1; x <= 9; x++) {
        if (!present[x]) continue;
        bool ok = true;
        for (int r = 0; r < n && ok; r++) {
            for (int c = 0; c < n && ok; c++) {
                if (grid[r][c] - '0' != x) continue;
                // Cell (r,c) is colored X. Check if inside any other Y's rect.
                for (int y = 1; y <= 9; y++) {
                    if (y == x || !present[y]) continue;
                    if (min_r[y] <= r && r <= max_r[y] &&
                        min_c[y] <= c && c <= max_c[y]) {
                        // X appears inside Y's bounding rect -> Y was before X
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) can_be_first++;
    }

    cout << can_be_first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
