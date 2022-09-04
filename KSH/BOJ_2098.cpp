//
// Created by Kim So Hee on 2022/09/03.
//

#include <bits/stdc++.h>

#define MAX 987654321
using namespace std;

int N;
int inputs[16][16];
int dp[16][1 << 16];

int run(int here, int visited) {
    if (visited == (1 << N) - 1) {
        if (inputs[here][0]) return inputs[here][0];
        else return MAX;
    }

    if (dp[here][visited] != -1) return dp[here][visited];
    int ret = MAX;

    for (int i = 0; i < N; ++i) {
        if (inputs[here][i] && !((visited >> i) & 1)) {
            ret = min(ret, run(i, visited | (1 << i)) + inputs[here][i]);
        }
    }
    return dp[here][visited] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /**
     * naive : 16!
     *
     * dp[n][mmm] = dp[현재 n 번째 도시 방문][현재 방문한 도시들] = min(dp[next][mmm + next] + cost)
     *   = 남아 있는 최소 순회 비용
     *
     * 왜 2차원 인지?
     *   (도시 i -> 나머지 방문, 도시 j -> 나머지 방문)의 비용이 다를 수 있기 때문
     *   도시 방문 상태 만으로 1차원 구성하면, 남은 도시 최소 순회 비용을 제대로 구할 수 없다.
     *
     */

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> inputs[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    // 시작 도시를 0번으로 고정 해도 답은 똑같다.
    cout << run(0, 1);

}