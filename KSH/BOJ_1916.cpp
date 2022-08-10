//
// Created by Kim So Hee on 2022/08/10.
//

#include <bits/stdc++.h>

#define MAX INT_MAX

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int start, end, time;
        cin >> start >> end >> time;
        graph[start].push_back({end, time});
    }

    int start, end;
    cin >> start >> end;

    vector<int> visited(n + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, start});
    visited[start] = 0;

    while (!pq.empty()) {
        const auto [cost, here] = pq.top();
        pq.pop();

        /**
         * s --> e 간선 중복 문제
         *   1. 최적 경로만 계산 하도록 분기 추가
         *   2. 간선 비용 오름차 순 정렬
         */
        if(visited[here] < cost) continue;

        for (const auto [next, distance]: graph[here]) {
            if (visited[next] <= cost + distance) continue;
            visited[next] = cost + distance;
            pq.push({cost + distance, next});
        }
    }
    cout << visited[end];
}