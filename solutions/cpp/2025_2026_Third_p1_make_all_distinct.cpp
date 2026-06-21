/*
USACO Bronze: Make All Distinct
Season: 2025-2026
Contest: Third (February)
Problem: 1
Problem ID: cpid=1587
Tags: COUNT, GREEDY, SORT

Problem statement:
Array a[1..N] with elements in [1, N], K ≠ 0 (-N ≤ K ≤ N).
Operation: a_i = a_i + K (can be repeated any number of times).
Find minimum operations to make all elements distinct.

Solution:
Since a_i changes by multiples of K, each element stays in its residue class modulo |K|.
Elements in different residue classes can never collide.

For each residue class r (0 ≤ r < |K|):
  - Collect all a_i with a_i % |K| == r.
  - If K > 0: process in ascending order, assign each the smallest available value ≥ its current value.
    target = max(current, last + K), operations += (target - current) / K.
  - If K < 0: process in descending order, assign each the largest available value ≤ its current value.
    target = min(current, last - |K|), operations += (current - target) / |K|.

Sum operations over all residue classes.
O(N log N) due to sorting within groups.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) cin >> a[i];

        int step = abs(K);
        // Group elements by residue modulo step
        unordered_map<int, vector<int>> groups;
        for (int v : a) {
            int r = (v % step + step) % step;
            groups[r].push_back(v);
        }

        ll total_ops = 0;
        for (auto& [r, vals] : groups) {
            if (K > 0) {
                sort(vals.begin(), vals.end());
                ll last = -1e18;
                for (int v : vals) {
                    ll target = max((ll)v, last + K);
                    total_ops += (target - v) / K;
                    last = target;
                }
            } else {
                sort(vals.begin(), vals.end(), greater<int>());
                ll last = 1e18;
                for (int v : vals) {
                    ll target = min((ll)v, last + K); // K is negative
                    total_ops += (v - target) / step;
                    last = target;
                }
            }
        }
        cout << total_ops << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
