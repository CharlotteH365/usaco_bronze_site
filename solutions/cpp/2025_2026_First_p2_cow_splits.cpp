/*
USACO Bronze: COW Splits
Season: 2025-2026
Contest: First (January)
Problem: 2
Problem ID: cpid=1540
Tags: STR, CONSTRUCTIVE

Problem statement:
String S of length 3N, each length-3 block is a cyclic shift of "COW" (COW, OWC, or WCO).
Operation: remove any subsequence T from S where T is a square string (Y+Y for some Y).
Determine if S can be reduced to empty, and provide a construction.
k=0: use minimum operations. k=1: at most min+1 operations.

Solution:
- N odd → impossible (each operation removes even counts of each char, total is odd)
- N even → always possible.

1-op: S itself is a square (first half == second half).
2-op: S can be split into consecutive prefix+suffix, each a square.
       At block level: find k where blocks[0..k-1]=blocks[k..2k-1]
       AND blocks[2k..2k+m-1]=blocks[2k+m..N-1] where m=(N-2k)/2.
3-op: Remove all C's (square of C's), then all O's (square of O's),
       then all W's (square of W's). Always works for even N.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T, k; cin >> T >> k;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;

        // N odd → impossible
        if (N % 2 == 1) {
            cout << "-1\n";
            continue;
        }

        int len = 3 * N;

        // --- 1 operation: S itself is a square ---
        int half = len / 2;
        bool oneOp = true;
        for (int i = 0; i < half; ++i) {
            if (S[i] != S[i + half]) { oneOp = false; break; }
        }
        if (oneOp) {
            cout << "1\n";
            for (int i = 0; i < len; ++i)
                cout << "1" << (i + 1 < len ? " " : "");
            cout << "\n";
            continue;
        }

        // --- 2 operations: split into two squares (contiguous) ---
        // Convert to block representation
        vector<int> blocks(N);
        for (int i = 0; i < N; ++i) {
            string b = S.substr(3 * i, 3);
            if (b == "COW") blocks[i] = 0;
            else if (b == "OWC") blocks[i] = 1;
            else blocks[i] = 2;              // WCO
        }

        bool foundTwo = false;
        int splitBlock = -1;

        for (int kblk = 1; 2 * kblk < N; ++kblk) {
            int prefixBlk = 2 * kblk;          // blocks in prefix
            int suffixBlk = N - prefixBlk;     // blocks in suffix
            if (suffixBlk % 2 != 0) continue;
            int m = suffixBlk / 2;

            // Prefix square check: blocks[0..kblk-1] == blocks[kblk..2*kblk-1]
            bool preOk = true;
            for (int i = 0; i < kblk; ++i) {
                if (blocks[i] != blocks[i + kblk]) { preOk = false; break; }
            }
            if (!preOk) continue;

            // Suffix square check: blocks[prefixBlk..prefixBlk+m-1] == blocks[prefixBlk+m..N-1]
            bool sufOk = true;
            for (int i = 0; i < m; ++i) {
                if (blocks[prefixBlk + i] != blocks[prefixBlk + m + i]) {
                    sufOk = false; break;
                }
            }
            if (!sufOk) continue;

            foundTwo = true;
            splitBlock = prefixBlk;
            break;
        }

        if (foundTwo && k == 0) {
            // k=0 requires minimum → 2 ops is better than 3
            int splitPos = splitBlock * 3;
            cout << "2\n";
            for (int i = 0; i < len; ++i)
                cout << (i < splitPos ? "1" : "2") << (i + 1 < len ? " " : "");
            cout << "\n";
            continue;
        }

        // --- 3 operations: by character type (always works for even N) ---
        // Each character type appears N times (even), so the subsequence
        // of all identical characters forms a perfect square: (N/2) + (N/2).
        cout << "3\n";
        for (int i = 0; i < len; ++i) {
            char c = S[i];
            int op = (c == 'C') ? 1 : ((c == 'O') ? 2 : 3);
            cout << op << (i + 1 < len ? " " : "");
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
