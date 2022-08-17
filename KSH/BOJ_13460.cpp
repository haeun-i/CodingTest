//
// Created by Kim So Hee on 2022/08/17.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, answer = 11;
vector<vector<int>> inputs;

vector<vector<int>> move(vector<vector<int>> map) {

    int w = map[0].size(), h = map.size();

    for (int i = h - 1; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            if (map[i][j] >= 10) {
                int nextY = i + 1;

                // 빈 칸 구슬 이동
                while (nextY < h && map[nextY][j] == 0) nextY++;
                swap(map[nextY - 1][j], map[i][j]);
            }
        }
    }

    return map;
}

void generate(int count, vector<vector<int>> map) {
    if (count > 10) return;

    for (int i = 0; i < 4; ++i) {
        auto w = map[0].size(), h = map.size();
        vector<vector<int>> rotated(w, vector<int>(h));

        for (int k = 0; k < h; ++k) {
            for (int j = 0; j < w; ++j) {
                rotated[j][h - k - 1] = map[k][j];
            }
        }
        map = rotated;

        auto ret = move(map);

        bool diff = false, success = false, blue = false;
        for (int j = 0; j < map.size(); ++j) {
            for (int k = 0; k < map[0].size(); ++k) {
                if (map[j][k] != ret[j][k]) diff = true;
                else if (ret[j][k] == -1 && ret[j - 1][k] == 10) {
                    if (j - 2 >= 0 && ret[j - 2][k] == 11) continue;
                    success = true;
                    answer = min(answer, count);
                } else if (ret[j][k] == -1 && ret[j - 1][k] == 11) {
                    blue = true;
                }
            }
        }
        if (diff && !success && !blue) generate(count + 1, ret);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    inputs = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            int value;
            switch (c) {
                case '.':value = 0;
                    break;
                case '#':value = 1;
                    break;
                case 'O':value = -1;
                    break;
                case 'R':value = 10;
                    break;
                case 'B':value = 11;
                    break;
                default :value = 0;
            }
            inputs[i][j] = value;
        }
    }

    /**
     * 파란 구슬 X, 빨간 구슬 빼내기, 동시에 빠져도 실패
     * 상하좌우 최대 10번 이동 가능
     */

    generate(1, inputs);

    cout << (answer == 11 ? -1 : answer);
}