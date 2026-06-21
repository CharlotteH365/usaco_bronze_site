/*
USACO Bronze: It's Mooin' Time
Season: 2024-2025
Contest: December
Problem: 3
Problem ID: cpid=1445
Tags: STR, COUNT, BRUTE FORCE

Problem:
String S of length N (lowercase a-z). A "moo" is a 3-char substring "abb" where a≠b.
Given frequency threshold F, find all possible moos that could appear ≥ F times
if Bessie changes AT MOST ONE character in S (or leaves it unchanged).
Output the count and the moos in alphabetical order.

Solution:
For each position i (0..N-1):
  - Temporarily remove contributions of windows containing i
  - Try changing s[i] to each letter 'a'..'z'
  - For each, add contributions of affected windows
  - If any moo reaches frequency ≥ F, add to answer set
  - Restore original

Track frequencies of each "abb" pattern using a map.
Only 3 windows are affected when changing s[i]: [i-2,i], [i-1,i+1], [i,i+2].
O(N * 26 * 3) = O(78N) ≈ 1.5e6, very fast.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, F; cin >> N >> F;
    string s; cin >> s;

    map<string, int> freq;
    set<string> valid;

    // Initial frequency count
    for (int i = 0; i + 2 < N; ++i) {
        if (s[i] != s[i+1] && s[i+1] == s[i+2]) {
            string moo = {s[i], s[i+1], s[i+2]};
            freq[moo]++;
            if (freq[moo] >= F) valid.insert(moo);
        }
    }

    // Try changing each position
    for (int i = 0; i < N; ++i) {
        // Remove contributions of affected windows
        for (int start = i - 2; start <= i; ++start) {
            if (start < 0 || start + 2 >= N) continue;
            if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                string moo = {s[start], s[start+1], s[start+2]};
                freq[moo]--;
            }
        }

        char orig = s[i];
        // Try each possible new letter
        for (char c = 'a'; c <= 'z'; ++c) {
            s[i] = c;
            // Add contributions of affected windows
            for (int start = i - 2; start <= i; ++start) {
                if (start < 0 || start + 2 >= N) continue;
                if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                    string moo = {s[start], s[start+1], s[start+2]};
                    freq[moo]++;
                    if (freq[moo] >= F) valid.insert(moo);
                }
            }
            // Revert additions
            for (int start = i - 2; start <= i; ++start) {
                if (start < 0 || start + 2 >= N) continue;
                if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                    string moo = {s[start], s[start+1], s[start+2]};
                    freq[moo]--;
                }
            }
        }
        s[i] = orig;

        // Restore original contributions
        for (int start = i - 2; start <= i; ++start) {
            if (start < 0 || start + 2 >= N) continue;
            if (s[start] != s[start+1] && s[start+1] == s[start+2]) {
                string moo = {s[start], s[start+1], s[start+2]};
                freq[moo]++;
            }
        }
    }

    cout << valid.size() << "\n";
    for (auto& m : valid) cout << m << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
