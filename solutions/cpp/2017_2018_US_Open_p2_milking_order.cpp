/*
USACO Bronze: Milking Order
Season: 2017-2018
Contest: US Open
Problem: 2
Tags: SIM, ORDERING

Approach note:
Primary pattern: Simulation / Implementation (模拟 / 实现). Model state explicitly, then update it exactly as the statement says. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> order(M);
    for (int i = 0; i < M; ++i) cin >> order[i];
    map<int,int> fixed;
    for (int i = 0; i < K; ++i) {
        int cow, pos;
        cin >> cow >> pos;
        fixed[cow] = pos - 1;
    }

    if (fixed.count(1)) {
        cout << fixed[1] + 1 << "\n";
        return;
    }

    // Try earliest position for cow 1
    for (int p1 = 0; p1 < N; ++p1) {
        vector<int> pos(N, -1);
        pos[p1] = 1;
        bool ok = true;
        for (auto& [cow, p] : fixed) {
            if (pos[p] != -1 && pos[p] != cow) { ok = false; break; }
            pos[p] = cow;
        }
        if (!ok) continue;

        int cur = 0;
        for (int cow : order) {
            if (cow == 1) continue;
            int placed = -1;
            for (int j = 0; j < N; ++j)
                if (pos[j] == cow) { placed = j; break; }
            if (placed != -1) continue;
            while (cur < N && pos[cur] != -1) cur++;
            if (cur == N) { ok = false; break; }
            pos[cur] = cow;
            cur++;
        }
        if (ok) { cout << p1 + 1 << "\n"; return; }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
