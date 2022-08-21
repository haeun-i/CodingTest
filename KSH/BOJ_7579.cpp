//
// Created by Kim So Hee on 2022/08/21.
//

#include <bits/stdc++.h>

#define MAX 10'000'000

using namespace std;

int N, M;
int active[101], cost[101];
int dp[10001]; // dp[cost] = max memory

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> active[i];
    for (int i = 0; i < N; ++i) cin >> cost[i];

    /**
     * 메모리 M 이상 확보, cost 최소 비용
     * 냅색
     *   dp[i] = max dp[i - cost[j]] + active[j]
     */

    for (int j = 0; j < N; ++j) {
        for (int i = 10000; i >= cost[j]; --i) {
            dp[i] = max(dp[i], dp[i - cost[j]] + active[j]);
        }
    }

    for (int i = 0; i < 10001; ++i) {
        if (dp[i] >= M) {
            cout << i;
            return 0;
        }
    }
}