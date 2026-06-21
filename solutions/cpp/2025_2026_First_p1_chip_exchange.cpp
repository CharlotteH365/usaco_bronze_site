/*
USACO Bronze: Chip Exchange
Season: 2025-2026
Contest: First (January)
Problem: 1
Problem ID: cpid=1539
Tags: MATH, ADHOC, BINARY SEARCH

Problem statement:
Bessie has A chips of type A and B chips of type B.
Operation: exchange cB chips of type B for cA chips of type A (repeatable).
She receives x additional random chips (unknown split of type A/B).
Find minimum x such that she is GUARANTEED to end up with at least fA type-A chips,
regardless of how the x chips are split between types.

Solution approach:
The adversary splits x chips into aA type-A and aB type-B to minimize our final A:
  total = A + aA + floor((B + aB) / cB) * cA
Let y = B + aB (total B after split), y in [B, B+x].
  total = A + B + x + floor(y/cB)*cA - y
Adversary minimizes g(y) = floor(y/cB)*cA - y (sawtooth function).
Within each period [k*cB, (k+1)*cB), g decreases, so candidates are:
  - y = B (all A chips)
  - y = B + x (all B chips)
  - y = (k+1)*cB - 1 (period right-ends, if reachable)
Binary search on x to find minimum satisfying min_total(x) >= fA.
O(T * log(2e18)) ≈ 60 iterations per test case.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Minimum achievable A-chips when adversary gives x chips in worst split.
ll min_total(ll A, ll B, ll cA, ll cB, ll x) {
    // Candidate 1: all A chips (y = B)
    ll cand1 = A + x + (B / cB) * cA;
    // Candidate 2: all B chips (y = B + x)
    ll cand2 = A + ((B + x) / cB) * cA;
    ll best = min(cand1, cand2);

    // Candidate 3: period right-ends y = (k+1)*cB - 1 within [B, B+x]
    ll k0 = B / cB;
    ll first_end = (k0 + 1) * cB - 1;
    if (first_end <= B + x) {
        ll k_max = (B + x + 1) / cB - 1;
        // total = A + B + x + 1 - cB + k*(cA - cB)
        if (cA <= cB) {
            // decreasing in k → best at k_max
            ll tot = A + B + x + 1 - cB + k_max * (cA - cB);
            best = min(best, tot);
        } else {
            // increasing in k → best at k0
            ll tot = A + B + x + 1 - cB + k0 * (cA - cB);
            best = min(best, tot);
        }
    }
    return best;
}

void solve() {
    int T; cin >> T;
    while (T--) {
        ll A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;

        // Binary search for minimum x
        ll lo = 0, hi = 2000000000000000000LL; // 2e18 upper bound
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (min_total(A, B, cA, cB, mid) >= fA)
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
