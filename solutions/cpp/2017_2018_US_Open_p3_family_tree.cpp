/*
USACO Bronze: Family Tree
Season: 2017-2018
Contest: US Open
Problem: 3
Tags: GRAPH, SEARCH

Approach note:
Primary pattern: Graph-lite / Connectivity (轻量图论). Use adjacency, reachability, indegree/outdegree, or simple DFS/BFS when needed. For this problem, first restate the input as state, constraints, and target output. Then implement the smallest algorithm matching the constraints.

Study use:
Fill solve() after reading the official statement. Keep the same structure as the Python file
so the two versions can be compared line by line.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    map<string,string> mom;
    for (int i = 0; i < N; ++i) {
        string m, d;
        cin >> m >> d;
        mom[d] = m;
    }

    auto ancestry = [&](string cow) {
        vector<string> path;
        path.push_back(cow);
        while (mom.count(path.back()))
            path.push_back(mom[path.back()]);
        return path;
    };

    vector<string> pa = ancestry(A), pb = ancestry(B);

    // Check direct ancestor relationships
    auto check_direct = [&](const vector<string>& p, const string& who, const string& other) {
        auto it = find(p.begin(), p.end(), other);
        if (it != p.end()) {
            int idx = it - p.begin();
            if (idx == 0) cout << "SIBLINGS\n";
            else if (idx == 1) cout << other << " is the mother of " << who << "\n";
            else if (idx == 2) cout << other << " is the grand-mother of " << who << "\n";
            else cout << other << " is the great-grand-mother of " << who << "\n";
            return true;
        }
        return false;
    };

    if (check_direct(pa, A, B)) return;
    if (check_direct(pb, B, A)) return;

    // Find LCA
    string lca;
    bool found = false;
    for (auto& c : pa) {
        if (find(pb.begin(), pb.end(), c) != pb.end()) {
            lca = c; found = true; break;
        }
    }
    if (!found) { cout << "NOT RELATED\n"; return; }

    int da = find(pa.begin(), pa.end(), lca) - pa.begin();
    int db = find(pb.begin(), pb.end(), lca) - pb.begin();

    if (da == 1 && db == 1) cout << "SIBLINGS\n";
    else if (da == 1 && db == 2) cout << A << " is the aunt of " << B << "\n";
    else if (da == 2 && db == 1) cout << B << " is the aunt of " << A << "\n";
    else cout << "COUSINS\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
