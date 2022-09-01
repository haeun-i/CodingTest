//
// Created by Kim So Hee on 2022/09/01.
//

#include <bits/stdc++.h>

using namespace std;

int dp[501][501];
pair<int, int> inputs[501];

int run(int start, int end) {
    if (dp[start][end] != INT_MAX) return dp[start][end];
    if (start == end) return 0;

    int ret = INT_MAX;
    for (int i = start; i < end; ++i) {
        ret = min(ret, run(start, i) + run(i + 1, end) + inputs[start].first * inputs[i].second * inputs[end].second);
    }

    return dp[start][end] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(&dp[0][0], &dp[500][501], INT_MAX);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> inputs[i].first >> inputs[i].second;


    /**
     * A B C D E
     *
     * for i A to E
     * dp[A][E] = dp[A][i] + dp[i+1][E] + A.first * i.second * E.second
     */

    cout << run(0, n - 1);

}