/*
USACO Bronze: Astral Superposition
Season: 2024-2025
Contest: January
Problem: 1
Problem ID: cpid=1467
Tags: GRID, GREEDY, CASEWORK

Problem: Two NxN star photos superimposed with shift (A,B). Cells are W(empty),
G(one star), B(both stars). Find minimum original stars. Output -1 if impossible.

Solution: Casework per cell. If A=B=0, answer = count(B)+count(G).
For B cells: star must exist at (i,j) and (i-A,j-B) originally.
For G cells: check if star moved from here to a B cell, or originated here.
Count original stars. O(N^2) per test case.
*/

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    swap(a, b);
    vector<vector<int>> coding(n+1, vector<int>(n+1));
    vector<vector<int>> old_grid(n+1, vector<int>(n+1));
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            if (c == 'B') { coding[i][j] = 2; total++; }
            if (c == 'G') { coding[i][j] = 1; total++; }
        }
    }
    if (a == 0 && b == 0) { cout << total << "\n"; return; }
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (coding[i][j] == 2) {
                if (i - a <= 0 || j - b <= 0) { bad = 1; }
                else {
                    if (old_grid[i - a][j - b] == 0) { bad = 1; }
                    old_grid[i][j] = 1;
                }
            }
            if (coding[i][j] == 1) {
                if (i + a <= n && j + b <= n && coding[i + a][j + b] == 2) {
                    old_grid[i][j] = 1;
                } else {
                    if (i - a > 0 && j - b > 0 && old_grid[i - a][j - b] == 1) ;
                    else { old_grid[i][j] = 1; }
                }
            }
        }
    }
    if (bad) { cout << -1 << "\n"; return; }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += old_grid[i][j];
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
