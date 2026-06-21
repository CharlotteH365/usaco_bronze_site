/*
USACO Bronze: It's Mooin' Time IV
Season: 2025-2026
Contest: Second (January-February)
Problem: 1
Problem ID: cpid=1563
Tags: STR, CONSTRUCTIVE, ADHOC

Problem statement:
Bessie types on a keyboard with only M and O.
- Typing M: appends M to the string.
- Typing O: flips ALL previously typed characters (M→O, O→M), then appends O.
Given target string S (M/O), determine if it's possible to type it.
If k=1, also provide the sequence of keystrokes.

Solution:
Work backwards from S. Maintain a 'flipped' flag.
For each character from right to left:
  - Interpret the character considering the flip flag.
  - If interpreted as 'O': record 'O' operation, toggle flip flag.
  - If interpreted as 'M': record 'M' operation.
After processing all chars, reverse the operations to get the forward sequence.
Always possible (the backward simulation always gives a valid construction).
O(N) per test case.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T, k; cin >> T >> k;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;

        // Work backwards
        string ops;
        bool flipped = false;
        for (int i = N - 1; i >= 0; --i) {
            char c = S[i];
            if (flipped) c = (c == 'M' ? 'O' : 'M');
            if (c == 'O') {
                ops.push_back('O');
                flipped = !flipped;
            } else {
                ops.push_back('M');
            }
        }
        reverse(ops.begin(), ops.end());

        cout << "YES\n";
        if (k == 1) cout << ops << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
