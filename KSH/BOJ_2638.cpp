//
// Created by Kim So Hee on 2022/08/12.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
bool inputs[101][101];
int diff[4]{1, 0, -1, 0};

/**
 * 2 방향 이상 접촉 하면 1시간 후 사라진다.
 * 치즈 내부의 공간은 제외 한다.
 * 맨 가장 자리는 치즈가 없다.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> inputs[i][j];
        }
    }

    int answer = 0;
    while (++answer) {
        /**
         * 1. (0,0) BFS
         * 2. cheese hits count
         * 3. hits[i][j] >= 2, inputs[i][j] = 0
         * 4. all hits count == 0, break;
         */
        vector<vector<int>> visited(N, vector<int>(M));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            const auto [hereY, hereX] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextY = hereY + diff[i], nextX = hereX + diff[(i + 3) % 4];
                if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
                if (visited[nextY][nextX]++) continue;
                if (inputs[nextY][nextX]) continue;

                q.push({nextY, nextX});
            }
        }
        bool finish = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j] >= 2 && inputs[i][j]) inputs[i][j] = finish = false;
            }
        }
        if (finish) break;
    }
    cout << answer - 1;
}