/*
USACO Bronze: Teleportation
Season: 2017-2018
Contest: February
Problem: 1
Tags: MATH, ADHOC

Approach note:
Primary pattern: Math / Number Patterns (数学规律). Generate small cases, identify parity/modulo/divisibility patterns, then prove bounds. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: apply mathematical formulas and parity patterns
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans = min({abs(b - a),
                   abs(a - x) + abs(b - y),
                   abs(a - y) + abs(b - x)});
    cout << ans << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
