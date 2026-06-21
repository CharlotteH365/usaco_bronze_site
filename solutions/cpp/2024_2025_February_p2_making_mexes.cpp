/*
USACO Bronze: Making Mexes
Season: 2024-2025
Contest: February
Problem: 2
Problem ID: cpid=1492
Tags: COUNT, MATH, FREQUENCY

Problem: Array a of N elements. Can change any element to anything.
For each i=0..N, min operations to make mex = i.
Solution: To make mex=i, need all 0..i-1 present (fill missing) and i absent
(remove all i). answer[i] = max(missing_count[i], freq[i]). O(N).
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> freq(N+2, 0);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x <= N) freq[x]++;
    }
    int missing = 0;
    for (int i = 0; i <= N; i++) {
        cout << max(missing, freq[i]) << "\n";
        if (freq[i] == 0) missing++;
    }
    return 0;
}
