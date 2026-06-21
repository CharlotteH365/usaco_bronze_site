/*
USACO Bronze: Team Tic Tac Toe
Season: 2017-2018
Contest: US Open
Problem: 1
Tags: GRID, COUNT

Approach note:
Primary pattern: Grid / Geometry (网格 / 几何). Draw coordinates, standardize indexing, and watch inclusive/exclusive borders. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string g[3];
    for (int i = 0; i < 3; ++i) cin >> g[i];

    set<set<char>> ind_wins, team_wins;
    // Check 8 lines: 3 rows, 3 cols, 2 diagonals
    auto check = [&](set<char> s) {
        if (s.size() == 1) ind_wins.insert(s);
        else if (s.size() == 2) team_wins.insert(s);
    };
    for (int i = 0; i < 3; ++i) {
        check({g[i][0], g[i][1], g[i][2]});
        check({g[0][i], g[1][i], g[2][i]});
    }
    check({g[0][0], g[1][1], g[2][2]});
    check({g[0][2], g[1][1], g[2][0]});

    cout << ind_wins.size() << "\n";
    cout << team_wins.size() << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
