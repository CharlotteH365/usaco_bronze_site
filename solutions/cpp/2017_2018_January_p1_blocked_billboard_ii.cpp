/*
USACO Bronze: Blocked Billboard II
Season: 2017-2018
Contest: January
Problem: 1
Tags: GEOMETRY

Approach note:
Primary pattern: Geometry (几何). Use coordinates, areas, distances, intersections, and orientation. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Key: compute areas and overlap of axis-aligned rectangles
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    int tx1, ty1, tx2, ty2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;

    auto area = [](int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    };
    auto overlap = [](int x1, int y1, int x2, int y2,
                      int u1, int v1, int u2, int v2) {
        int w = max(0, min(x2, u2) - max(x1, u1));
        int h = max(0, min(y2, v2) - max(y1, v1));
        return w * h;
    };

    int ans = area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2);
    ans -= overlap(ax1, ay1, ax2, ay2, tx1, ty1, tx2, ty2);
    ans -= overlap(bx1, by1, bx2, by2, tx1, ty1, tx2, ty2);
    cout << ans << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
