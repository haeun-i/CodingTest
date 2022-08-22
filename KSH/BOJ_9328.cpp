//
// Created by Kim So Hee on 2022/08/22.
//

#include <bits/stdc++.h>

#define DIFF 32

using namespace std;

int h, w;
char inputs[102][102];
string keys;
vector<pair<int, int>> suspend[100], cords[100];
int d[4]{1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        memset(inputs, 0, sizeof(inputs));
        fill(&inputs[0][0], &inputs[101][102], '.');
        for (int i = 0; i < 101; ++i) {
            suspend[i].clear();
            cords[i].clear();
        }

        int answer = 0;

        cin >> h >> w;

        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> inputs[i][j];
                char c = inputs[i][j];
                if (c >= 'A' && c <= 'Z') cords[c].emplace_back(i, j);

            }
        }
        cin >> keys;
        if (keys[0] != '0') {
            for (const auto &key: keys) {
                for (const auto [y, x]: cords[key - DIFF]) {
                    inputs[y][x] = '.';
                }
                cords[key - DIFF].clear();
            }
        }

        /**
         *  . : 빈공간
         *  * : 벽
         *  $ : 문서
         *  대문자 : 문
         *  소문자 : 열쇠 (대문자인 문을 열 수 있다, 여러 번 사용 가능)
         *  입구 : 벽이 아닌 가장자리
         *
         *  1. 입구가 여러 개, 입구를 드나드는 순서가 중요하다
         *   - 바닥에 있는 열쇠를 얻어야 하기 때문이다.
         *   - 바깥에 . 으로 된 layer을 하나 둔다. (0, 0)에서 시작한다.
         *
         *  2. BFS 탐색 시, 문(대문자)에 막히면 suspend 한다.
         *   - vector[대문자].push(좌표)
         *   - queue 에서 제거한다.
         *
         *  3. 열쇠(소문자)를 얻는다면?
         *   - 해당 문을 . 으로 만든다.
         *   - vector[대문자] element를 모두 BFS queue에 삽입한다.
         *
         */
        queue<pair<int, int>> q;
        bool visited[102][102]{};

        q.push({0, 0});
        while (!q.empty()) {
            const auto [hereY, hereX] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextY = hereY + d[i], nextX = hereX + d[(i + 1) % 4];
                if (nextY < 0 || nextY > h + 1 || nextX < 0 || nextX > w + 1) continue;
                if (visited[nextY][nextX]) continue;
                visited[nextY][nextX] = true;

                auto &check = inputs[nextY][nextX];
                if (check == '*') continue;

                if (check >= 'A' && check <= 'Z') {
                    // next 좌표는 suspend 이므로, 큐에 삽입 하면 안된다.
                    suspend[check].emplace_back(nextY, nextX);
                    continue;
                } else if (check >= 'a' && check <= 'z') {
                    /**
                     * 대문자 칸 . 으로 바꾸기
                     * suspend 된 대문자 좌표들 큐에 추가
                     */
                    for (const auto [y, x]: cords[check - DIFF]) {
                        inputs[y][x] = '.';
                    }
                    for (const auto cord: suspend[check - DIFF]) {
                        q.push(cord);
                    }
                    suspend[check - DIFF].clear();
                } else if (check == '$') answer++;

                q.push({nextY, nextX});
            }
        }
        cout << answer << '\n';
    }
}