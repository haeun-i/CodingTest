//
// Created by Kim So Hee on 2022/08/16.
//

#include <bits/stdc++.h>

using namespace std;

int N, answer;
int inputs[21][21];
vector<int> trace;

void solve() {
    int temp[21][21]{};
    memcpy(temp, inputs, sizeof(inputs));

    for (const auto &move: trace) {
        /**
         * 0 : up
         * 1 : down
         * 2 : left
         * 3 : right
         *
         * 1. 각 방향 따라 블록을 빈 칸 없이 옮긴다
         * 2. 인접한 블록이 동일 하다면, 합치고 0으로 만든다
         * 3. 다시 빈 칸 없이 블록을 옮긴다
         *
         * 옮기는 로직을 임시 vector로 작성 하면 더 깔끔 할 듯
         *   element > 0, vector.push
         *
         * 상하좌우 (4 연산) --> 상,회전 (2 연산) 압축 가능
         */
        if (move == 0) {
            for (int i = 0; i < N; ++i) {
                vector<int> v;
                for (int j = 0; j < N; ++j) {
                    if (temp[j][i] > 0) v.push_back(temp[j][i]);
                }
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j] == v[j - 1]) v[j - 1] *= 2, v[j] = 0;
                }
                v.erase(std::remove_if(v.begin(), v.end(), [](int num) { return num == 0; }), v.end());

                for (int j = 0; j < N; ++j) {
                    temp[j][i] = (j < v.size() ? v[j] : 0);
                }
            }
        } else if (move == 1) {
            for (int i = N - 1; i >= 0; --i) {
                vector<int> v;
                for (int j = N - 1; j >= 0; --j) {
                    if (temp[j][i] > 0) v.push_back(temp[j][i]);
                }
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j] == v[j - 1]) v[j - 1] *= 2, v[j] = 0;
                }
                v.erase(std::remove_if(v.begin(), v.end(), [](int num) { return num == 0; }), v.end());

                for (int j = 0; j < N; ++j) {
                    temp[N - j - 1][i] = (j < v.size() ? v[j] : 0);
                }

            }
        } else if (move == 2) {
            for (int i = 0; i < N; ++i) {
                vector<int> v;

                for (int j = 0; j < N; ++j) {
                    if (temp[i][j] > 0) v.push_back(temp[i][j]);
                }
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j] == v[j - 1]) v[j - 1] *= 2, v[j] = 0;
                }
                v.erase(std::remove_if(v.begin(), v.end(), [](int num) { return num == 0; }), v.end());

                for (int j = 0; j < N; ++j) {
                    temp[i][j] = (j < v.size() ? v[j] : 0);
                }
            }
        } else if (move == 3) {
            for (int i = N - 1; i >= 0; --i) {
                vector<int> v;

                for (int j = N - 1; j >= 0; --j) {
                    if (temp[i][j] > 0) v.push_back(temp[i][j]);
                }
                for (int j = 1; j < v.size(); ++j) {
                    if (v[j] == v[j - 1]) v[j - 1] *= 2, v[j] = 0;
                }
                v.erase(std::remove_if(v.begin(), v.end(), [](int num) { return num == 0; }), v.end());

                for (int j = 0; j < N; ++j) {
                    temp[i][N - 1 - j] = (j < v.size() ? v[j] : 0);
                }
            }
        }
    }
    answer = max(answer, *max_element(&temp[0][0], &temp[20][21]));
}

void generate(int count) {
      if (count == 5) {
          solve();
          return;
      }
      for (int i = 0; i < 4; ++i) {
          trace.push_back(i);
          generate(count + 1);
          trace.pop_back();
      }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> inputs[i][j];
        }
    }

    generate(0);

    cout << answer;
}