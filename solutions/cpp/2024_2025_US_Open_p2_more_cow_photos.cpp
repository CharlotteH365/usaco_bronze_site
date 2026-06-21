/*
USACO Bronze: More Cow Photos
Season: 2024-2025
Contest: US Open
Problem: 2
Problem ID: cpid=1516
Tags: GREEDY, COUNTING

Problem: N cows with heights 1..N. Arrange into symmetric "mountain" photo:
heights increase then decrease, no adjacent equals, symmetric. Max cows in photo.
Solution: Each height can appear at most twice (both sides) except peak (once).
For each possible peak i, size = cnt*2+1 where cnt = number of heights <= i
that appear at least twice. Take max. O(N).
*/

#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> frq(n+1);
    for (int i = 1; i <= n; i++) { int x; cin >> x; frq[x]++; }
    int cnt = 0, ans = 1;
    for (int i = 1; i <= n; i++) {
        if (frq[i] > 0) ans = max(ans, cnt * 2 + 1);
        cnt += (frq[i] >= 2);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
