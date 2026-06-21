/*
USACO Bronze: Moo Hunt
Season: 2025-2026
Contest: Second (January-February)
Problem: 2
Problem ID: cpid=1564
Tags: BRUTE FORCE, BITMASK, SOS DP

Problem statement:
N cells in a line (3 ≤ N ≤ 20). Each cell is M or O.
K mooves: moove i taps cells (x_i, y_i, z_i), scores 1 if s[x]=M, s[y]=s[z]=O.
Find max possible score and count of boards (M/O assignments) achieving it.

Solution:
Assign O=1, M=0. For mask (O-cells):
  score[mask] = sum over mooves where y,z in mask AND x not in mask.
Let f[mask] = sum over mooves where y,z in mask (regardless of x).
Let g[mask] = sum over mooves where x,y,z all in mask.
Then score[mask] = f[mask] - g[mask].

Use SOS DP to compute f and g for all masks:
- For each moove, add to pair_sum[pair_mask] and triple_sum[triple_mask].
- SOS DP over subsets to get f[mask] = sum_{sub⊆mask} pair_sum[sub].
- Similarly g[mask] = sum_{sub⊆mask} triple_sum[sub].

O(N * 2^N + K). N ≤ 20, fine.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K; cin >> N >> K;
    int M = 1 << N;
    vector<ll> pair_sum(M, 0), triple_sum(M, 0);

    for (int i = 0; i < K; ++i) {
        int x, y, z; cin >> x >> y >> z;
        --x; --y; --z;
        int pair_mask = (1 << y) | (1 << z);
        int triple_mask = pair_mask | (1 << x);
        pair_sum[pair_mask]++;
        triple_sum[triple_mask]++;
    }

    // SOS DP: sum over subsets
    vector<ll> f = pair_sum, g = triple_sum;
    for (int i = 0; i < N; ++i) {
        for (int mask = 0; mask < M; ++mask) {
            if (mask & (1 << i)) {
                f[mask] += f[mask ^ (1 << i)];
                g[mask] += g[mask ^ (1 << i)];
            }
        }
    }

    // Compute score for each mask
    ll max_score = -1, cnt = 0;
    for (int mask = 0; mask < M; ++mask) {
        ll score = f[mask] - g[mask];
        if (score > max_score) {
            max_score = score;
            cnt = 1;
        } else if (score == max_score) {
            cnt++;
        }
    }

    cout << max_score << " " << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
