/*
USACO Bronze: The Bovine Shuffle
Season: 2017-2018
Contest: December
Problem: 2
Tags: SIM, ARRAY

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);          // shuffle permutation (1-indexed input)
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        --a[i];                // convert to 0-indexed
    }
    vector<int> final_ids(N);  // cow IDs after 3 shuffles
    for (int i = 0; i < N; ++i) cin >> final_ids[i];

    // Compute inverse permutation 3 times to undo the shuffle
    vector<int> inv(N);
    iota(inv.begin(), inv.end(), 0);  // identity: inv[i] = i
    for (int t = 0; t < 3; ++t) {
        vector<int> nxt(N);
        for (int i = 0; i < N; ++i) {
            nxt[a[i]] = inv[i];       // reverse the forward shuffle
        }
        inv = nxt;
    }

    // Reconstruct original order
    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        result[inv[i]] = final_ids[i];
    }
    for (int x : result) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
