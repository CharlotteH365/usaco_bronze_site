/*
USACO Bronze: It's Mooin' Time III
Season: 2024-2025
Contest: US Open
Problem: 3
Problem ID: cpid=1517
Tags: STR, BINARY SEARCH, GREEDY

Problem: String s of length N. A "moo" is substring abb (a!=b). Value = (j-i)*(k-j).
Q queries [L,R]: max moo value with i>=L, k<=R. Output -1 if none.
Solution: For each of 26 letters as "o", binary search on position lists for:
leftmost m (letter != o, >= L), rightmost o (<= R), and middle o closest to
midpoint of [posm, poso2]. Check floor and ceil. O(N + Q*26*log N).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) pos[s[i]-'a'].push_back(i);
    while (q--) {
        int L, R; cin >> L >> R; L--; R--;
        ll ans = -1;
        for (int last = 0; last < 26; last++) {
            if (pos[last].empty()) continue;
            // leftmost m (letter != last) >= L
            int posm = -1;
            if ((s[L]-'a') != last) posm = L;
            else {
                for (int cand = 0; cand < 26; cand++) {
                    if (cand == last) continue;
                    auto it = lower_bound(pos[cand].begin(), pos[cand].end(), L);
                    if (it != pos[cand].end() && (posm == -1 || *it < posm))
                        posm = *it;
                }
            }
            if (posm == -1) continue;
            // rightmost o (== last) <= R
            auto it2 = upper_bound(pos[last].begin(), pos[last].end(), R);
            if (it2 == pos[last].begin()) continue;
            int poso2 = *(--it2);
            if (poso2 <= posm) continue;
            // middle o closest to (posm+poso2)/2
            int mid = (posm + poso2) / 2;
            auto it = upper_bound(pos[last].begin(), pos[last].end(), mid);
            // check floor
            if (it != pos[last].begin()) {
                int p = *(--it);
                if (p > posm && p < poso2)
                    ans = max(ans, 1LL * (p - posm) * (poso2 - p));
                it++;
            }
            // check ceil
            if (it != pos[last].end() && *it < poso2) {
                int p = *it;
                if (p > posm)
                    ans = max(ans, 1LL * (p - posm) * (poso2 - p));
            }
        }
        cout << (ans == 0 ? -1 : ans) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
