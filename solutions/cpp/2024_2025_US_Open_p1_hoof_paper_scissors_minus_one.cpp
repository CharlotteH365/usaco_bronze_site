/*
USACO Bronze: Hoof Paper Scissors Minus One
Season: 2024-2025
Contest: US Open
Problem: 1
Problem ID: cpid=1515
Tags: BRUTE FORCE, COUNTING

Problem: N symbols with win/draw/loss relationships. For each of Elsie's M pairs
(x,y), count how many ordered pairs (L,R) Bessie can play that guarantee a win
regardless of which symbol Elsie keeps.
Solution: For each query, count symbols j that beat both x and y (winboth).
Answer = N^2 - (N-winboth)^2 using complementary counting. O(N*M).
*/

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> win(n+1, vector<char>(n+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> win[i][j];
    while (m--) {
        int x, y; cin >> x >> y;
        int winboth = 0;
        for (int j = 1; j <= n; j++) {
            bool scoreA = (j > x) ? (win[j][x] == 'W') : (win[x][j] == 'L');
            bool scoreB = (j > y) ? (win[j][y] == 'W') : (win[y][j] == 'L');
            if (scoreA && scoreB) winboth++;
        }
        cout << 1LL * n * n - 1LL * (n - winboth) * (n - winboth) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
