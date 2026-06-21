/*
USACO Bronze: Cow Checkups
Season: 2024-2025
Contest: January
Problem: 3
Problem ID: cpid=1469
Tags: DP, PREFIX, INTERVAL

Problem: N cows, species a[i]. Vet checks if a[i]==b[i]. FJ reverses subarray
(l,r) exactly once. For each c=0..N, count (l,r) pairs giving c matches.
Solution: Prefix/suffix match counts + DP for internal matches after reversal.
cnt[l][r] = edge_matches + cnt[l+1][r-1]. O(N^2) time & memory.
*/

#include <iostream>
#include <vector>
using namespace std;

int cnt[7502][7502];
int goodprefix[7502], goodsuffix[7502], frq[7502];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n+1), v2(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        cin >> v2[i];
        if (v[i] == v2[i]) { goodprefix[i]++; goodsuffix[i]++; }
    }
    for (int i = 1; i <= n; i++) goodprefix[i] += goodprefix[i-1];
    for (int i = n; i >= 1; i--) goodsuffix[i] += goodsuffix[i+1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cnt[i][j] = (v[i]==v2[j]) + (i!=j ? (v[j]==v2[i]) : 0);
    for (int len = 1; len <= n; len++)
        for (int L = 1; L + len - 1 <= n; L++)
            cnt[L-1][L+len] += cnt[L][L+len-1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            frq[cnt[i][j] + goodprefix[i-1] + goodsuffix[j+1]]++;
    for (int i = 0; i <= n; i++) cout << frq[i] << "\n";
    return 0;
}
