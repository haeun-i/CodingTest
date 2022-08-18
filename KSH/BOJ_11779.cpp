//
// Created by Kim So Hee on 2022/08/11.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> trace(n + 1), visited(n + 1, INT_MAX);
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int start, end, time;
        cin >> start >> end >> time;
        graph[start].push_back({end, time});
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    visited[start] = 0;

    while (!pq.empty()) {
        const auto [cost, here] = pq.top();
        pq.pop();
        if (visited[here] < cost) continue;

        for (const auto [next, distance]: graph[here]) {
            int dd = cost + distance;
            if (visited[next] <= dd) continue;
            visited[next] = dd;
            trace[next] = here;
            pq.push({dd, next});
        }
    }

    cout << visited[end] << '\n';

    vector<int> answer;
    answer.push_back(end);
    while ((end = trace[end]) != 0) answer.push_back(end);

    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; --i) {
        cout << answer[i] << ' ';
    }
}