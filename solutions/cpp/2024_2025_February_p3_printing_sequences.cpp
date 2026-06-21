/*
USACO Bronze: Printing Sequences
Season: 2024-2025
Contest: February
Problem: 3
Problem ID: cpid=1493
Tags: DP, STRING, CONSTRUCTIVE

Problem: Generate target sequence of length N using at most K PRINT statements
and unlimited REP loops. K <= 3, N <= 100. Determine YES/NO.
Solution: DP[l][r][c] = can subarray [l,r] be generated with <= c PRINTs.
Base: uniform subarray needs 1 PRINT. Transitions: concatenation (split) and
REP loop (periodic repetition). O(N^3 * K^2) per test.
*/

#include <iostream>
#include <vector>
using namespace std;

bool solve_one() {
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(N, vector<bool>(K+1,false)));
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            bool same = true;
            for (int i = l; i <= r; i++)
                if (a[i] != a[l]) { same = false; break; }
            if (same) dp[l][r][1] = true;
        }
    }
    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len - 1 < N; l++) {
            int r = l + len - 1;
            for (int c = 1; c <= K; c++) {
                if (dp[l][r][c]) continue;
                for (int m = l; m < r; m++) {
                    for (int c1 = 1; c1 <= c; c1++) {
                        if (dp[l][m][c1] && dp[m+1][r][c-c1]) {
                            dp[l][r][c] = true; break;
                        }
                    }
                    if (dp[l][r][c]) break;
                }
                if (dp[l][r][c]) continue;
                for (int blk = 1; blk <= len/2; blk++) {
                    if (len % blk != 0) continue;
                    int p = len / blk;
                    bool ok = true;
                    for (int rep = 1; rep < p && ok; rep++)
                        for (int i = 0; i < blk; i++)
                            if (a[l+i] != a[l+rep*blk+i]) { ok = false; break; }
                    if (ok && dp[l][l+blk-1][c]) { dp[l][r][c] = true; break; }
                }
            }
        }
    }
    return dp[0][N-1][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) cout << (solve_one() ? "YES" : "NO") << "\n";
    return 0;
}
