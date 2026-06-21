/*
USACO Bronze: Strange Function
Season: 2025-2026
Contest: Third (February)
Problem: 2
Problem ID: cpid=1588
Tags: MATH, STRING, MODULAR

Problem statement:
f(x):
  - If x has any digit not 0 or 1: replace each digit with 1 if odd, 0 if even.
  - Otherwise (all digits 0/1): return x-1.
Count applications of f until x reaches 0. Output mod 1e9+7.
x can have up to 2e5 digits.

Solution:
Let B = binary value of the 0/1 string (after mapping if needed).
For a 0/1 number y, total steps to 0 = B + floor(B/2).
(Where B is the integer whose binary representation equals y's decimal digits.)

If x is already 0/1: ans = B + B//2.
Otherwise: one mapping step first, then f(x) is a 0/1 number.
  Let B = binary value of f(x). ans = 1 + B + B//2.

Compute B mod (2*MOD) by processing the string, then derive B mod MOD and B//2 mod MOD.
O(total digits) time.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;
const ll MOD2 = 2 * MOD;

void solve() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int L = (int)s.size();

        // Check if already 0/1
        bool is_01 = true;
        for (char c : s) {
            if (c != '0' && c != '1') { is_01 = false; break; }
        }

        string t;
        if (is_01) {
            t = s;
        } else {
            // Map: odd -> '1', even -> '0'
            for (char c : s) t.push_back((c - '0') % 2 ? '1' : '0');
        }

        // Compute binary value of t mod 2*MOD
        ll B_mod = 0;
        for (char c : t)
            B_mod = (B_mod * 2 + (c - '0')) % MOD2;

        ll B = B_mod % MOD;
        // floor(B/2) mod MOD
        ll B_half = (B_mod - (B_mod & 1)) / 2 % MOD;

        ll ans = (B + B_half) % MOD;
        if (!is_01) ans = (ans + 1) % MOD;

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
