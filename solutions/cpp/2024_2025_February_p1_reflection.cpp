/*
USACO Bronze: Reflection
Season: 2024-2025
Contest: February
Problem: 1
Problem ID: cpid=1491
Tags: GRID, SYMMETRY, UPDATE

Problem: NxN grid (even N), cells with . or #. Cells reflect across midlines
forming groups of 4. Each group must be uniform. After U flip updates, output
minimum total flips needed after each update.
Solution: For each group, cost = min(count(.), count(#)). On update, recompute
only the affected group. O(N^2 + U) time.
*/

#include <iostream>
#include <vector>
using namespace std;

int upds(int x, int y, int n, vector<vector<char>> &grid) {
    int cntA = 0, cntB = 0;
    vector<pair<int,int>> pts = {{x,y},{n-x+1,y},{x,n-y+1},{n-x+1,n-y+1}};
    for (auto& p : pts) {
        if (grid[p.first][p.second] == '.') cntA++;
        else cntB++;
    }
    return min(cntA, cntB);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u; cin >> n >> u;
    vector<vector<char>> grid(n+1, vector<char>(n+1));
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++) grid[i][j] = s[j-1];
    }
    int cnt = 0;
    for (int i = 1; i <= n/2; i++)
        for (int j = n/2+1; j <= n; j++)
            cnt += upds(i, j, n, grid);
    cout << cnt << "\n";
    while (u--) {
        int x, y; cin >> x >> y;
        cnt -= upds(x, y, n, grid);
        grid[x][y] = (grid[x][y] == '.' ? '#' : '.');
        cnt += upds(x, y, n, grid);
        cout << cnt << "\n";
    }
    return 0;
}
