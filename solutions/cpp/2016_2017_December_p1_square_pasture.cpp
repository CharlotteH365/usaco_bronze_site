/*
USACO Bronze: Square Pasture
Season: 2016-2017
Contest: December
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
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1>>y1>>x2>>y2 >> x3>>y3>>x4>>y4;
    int w = max(x2,x4) - min(x1,x3);
    int h = max(y2,y4) - min(y1,y3);
    int s = max(w, h);
    cout << s * s << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
