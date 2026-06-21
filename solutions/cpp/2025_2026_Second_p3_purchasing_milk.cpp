/*
USACO Bronze: Purchasing Milk
Season: 2025-2026
Contest: Second (January-February)
Problem: 3
Problem ID: cpid=1565
Tags: DP, GREEDY, PREFIX

Problem statement:
Farmer John offers N deals. Deal i gives 2^(i-1) buckets of milk for a_i moonies.
Each deal can be taken any number of times.
Q queries: minimum cost to purchase at least x buckets (x up to 1e9).

Solution:
Precompute best[i] = minimum cost to obtain exactly 2^i buckets.
  best[0] = a_1
  For i >= 1: best[i] = min(a_{i+1} if i+1 <= N, 2 * best[i-1])
Since x <= 1e9 < 2^30, we only need indices up to 60 (to handle overbuying).

For each query x:
  Process bits of x from low to high.
  Keep current cost 'ans'. At each bit i:
    - If bit i of x is set: ans += best[i]
    - Consider replacing all current purchases with best[i+1] (which covers all bits 0..i)
      ans = min(ans, best[i+1])
  This handles the "overbuy" case where a single larger deal is cheaper
  than multiple smaller ones.

O(N + Q*log(max_x)). Use 64-bit integers, cap best[i] at ~2e18 to avoid overflow.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2'000'000'000'000'000'000LL; // 2e18

void solve() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    const int B = 60; // enough for 2^60 > 1e18
    vector<ll> best(B + 2, INF);
    for (int i = 0; i <= B; ++i) {
        if (i < N) best[i] = a[i];
        if (i > 0) best[i] = min(best[i], min(INF / 2, best[i-1] * 2));
    }
    best[B + 1] = min(INF, best[B] * 2); // for round-up at highest bit

    while (Q--) {
        ll x; cin >> x;
        ll ans = 0;
        for (int i = 0; i <= B; ++i) {
            if ((x >> i) & 1) {
                ans = min(INF, ans + best[i]);
            }
            ans = min(ans, best[i + 1]);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
