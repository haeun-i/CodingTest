//
// Created by Kim So Hee on 2022/08/14.
//

#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> graph[801];

void solve(vector<long long> &visited, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    visited[source] = 0;

    while (!pq.empty()) {
        const auto [cost, here] = pq.top();
        pq.pop();
        if (visited[here] < cost) continue;

        for (const auto [next, distance]: graph[here]) {
            int dd = cost + distance;
            if (visited[next] <= dd) continue;
            visited[next] = dd;
            pq.push({dd, next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<long long> source1(n + 1, INT_MAX), sourceV1(n + 1, INT_MAX), sourceV2(n + 1, INT_MAX);
    solve(source1, 1);
    solve(sourceV1, v1);
    solve(sourceV2, v2);

    long long answer1 = source1[v1] + sourceV1[v2] + sourceV2[n];
    long long answer2 = source1[v2] + sourceV2[v1] + sourceV1[n];
    long long answer = min(answer1, answer2);

    cout << (answer >= INT_MAX ? -1 : answer);
}