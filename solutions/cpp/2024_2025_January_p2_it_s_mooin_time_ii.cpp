/*
USACO Bronze: It's Mooin' Time II
Season: 2024-2025
Contest: January
Problem: 2
Problem ID: cpid=1468
Tags: COUNT, FREQUENCY, DISTINCT SUBSEQUENCES

Problem: Count distinct "moo" subsequences (a,b,b with a!=b) in array of N integers.
Solution: For each value b, use second-to-last occurrence. When frq2[v[i]]==1,
v[i] is the second-last occurrence. Any distinct value seen before (except v[i])
forms a valid moo. O(N) time.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n+1), frq(n+1), frq2(n+1);
    for (int i = 1; i <= n; i++) { cin >> v[i]; frq2[v[i]]++; }
    long long ans = 0;
    int cntdistinct = 0;
    for (int i = 1; i <= n; i++) {
        frq2[v[i]]--;
        if (frq2[v[i]] == 1) {
            ans += 1LL * (cntdistinct - (frq[v[i]] > 0));
        }
        frq[v[i]]++;
        if (frq[v[i]] == 1) cntdistinct++;
    }
    cout << ans << "\n";
    return 0;
}
