//
// Created by Kim So Hee on 2022/08/09.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;

/**
 * 0 : 빈칸
 * 1 : 집
 * 2 : 치킨집
 */
int inputs[51][51], answer = 987654321;
vector<pair<int, int>> source, dest;

void cal(vector<int>& chosen){
    int solve = 0;
    for (const auto &s: source) {
        int distance = 987654321;
        for (const auto &chicken: chosen) {
            distance = min(distance, abs(dest[chicken].first - s.first) + abs(dest[chicken].second - s.second));
        }
        solve += distance;
    }
    answer = min(answer, solve);
}

void bt(int idx, vector<int> chicken) {
    if (chicken.size() == M) {
        cal(chicken);
        return;
    }
    for (int i = idx + 1; i < dest.size(); ++i) {
        chicken.push_back(i);
        bt(i, chicken);
        chicken.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> inputs[i][j];
            if (inputs[i][j] == 1) source.emplace_back(i, j);
            else if (inputs[i][j] == 2) dest.emplace_back(i, j);
        }
    }

    bt(-1, {});
    cout << answer;
}