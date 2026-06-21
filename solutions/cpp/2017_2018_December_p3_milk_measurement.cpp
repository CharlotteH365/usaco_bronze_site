/*
USACO Bronze: Milk Measurement
Season: 2017-2018
Contest: December
Problem: 3
Tags: SIM, SORT

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
    vector<tuple<int,int,int>> entries; // day, cow_idx, change
    unordered_map<string,int> mp = {{\"Bessie\",0},{\"Elsie\",1},{\"Mildred\",2}};
    for (int i = 0; i < N; ++i) {
        int day, change;
        string name;
        cin >> day >> name >> change;
        entries.push_back({day, mp[name], change});
    }
    sort(entries.begin(), entries.end());

    vector<int> milk = {7, 7, 7};
    int changes = 0;

    auto leader = [&]() {
        int mx = max({milk[0], milk[1], milk[2]});
        string s;
        for (int i = 0; i < 3; ++i)
            if (milk[i] == mx) s += char('0' + i);
        return s;
    };

    string prev = leader();
    for (int i = 0; i < N; ) {
        int day = get<0>(entries[i]);
        while (i < N && get<0>(entries[i]) == day) {
            int cow = get<1>(entries[i]);
            int delta = get<2>(entries[i]);
            milk[cow] += delta;
            ++i;
        }
        string cur = leader();
        if (cur != prev) { ++changes; prev = cur; }
    }
    cout << changes << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
