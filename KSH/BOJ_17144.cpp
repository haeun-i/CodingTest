//
// Created by Kim So Hee on 2022/08/10.
//

#include <bits/stdc++.h>

using namespace std;

int R, C, T;
int inputs[51][51];
int diff[4][2]{{-1, 0},
               {0,  1},
               {1,  0},
               {0,  -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> T;
    pair<int, int> clock = {-1, -1}, counterClock;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> inputs[i][j];
            if (inputs[i][j] == -1) {
                if (clock.first == -1) clock = {i, j};
                else counterClock = {i, j};
            }
        }
    }

    while (T--) {
        /**
         * 미세 먼지
         *   확산되는 양은 Ar,c/5이고 소수점은 버린다.
         *   (r, c)에 남은 미세 먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
         *
         * 공기 청정기
         *   위쪽은 반시계, 아래 쪽은 시계 방향
         *   미세 먼지는 바람의 방향 대로 한 칸씩 이동
         *   공기 청정기 안으로 들어 가면 정화
         */
        int temp[51][51]{};
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (inputs[i][j] > 0) {
                    int cost = inputs[i][j] / 5, direction = 0;
                    for (const auto [dy, dx]: diff) {
                        int nextY = i + dy, nextX = j + dx;
                        if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
                        if (inputs[nextY][nextX] == -1) continue;
                        direction++;
                        temp[nextY][nextX] += cost;
                    }
                    inputs[i][j] -= cost * direction;
                }
            }
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                inputs[i][j] += temp[i][j];
            }
        }

        // 시계 방향
        for (int i = clock.first - 1; i > 0; i--) inputs[i][0] = inputs[i - 1][0];
        for (int i = 0; i < C - 1; i++) inputs[0][i] = inputs[0][i + 1];
        for (int i = 0; i < clock.first ; i++) inputs[i][C - 1] = inputs[i + 1][C - 1];
        for (int i = C - 1; i > 1; i--) inputs[clock.first][i] = inputs[clock.first][i - 1];
        inputs[clock.first][1] = 0;

        // 반시계 방향
        for (int i = counterClock.first + 1; i < R - 1; i++) inputs[i][0] = inputs[i + 1][0];
        for (int i = 0; i < C - 1; i++) inputs[R - 1][i] = inputs[R - 1][i + 1];
        for (int i = R - 1; i > counterClock.first ; i--) inputs[i][C - 1] = inputs[i - 1][C - 1];
        for (int i = C - 1; i > 1; i--) inputs[counterClock.first][i] = inputs[counterClock.first][i - 1];
        inputs[counterClock.first][1] = 0;

    }
    int answer = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if(inputs[i][j] > 0) answer += inputs[i][j];
        }
    }
    cout<<answer;
}