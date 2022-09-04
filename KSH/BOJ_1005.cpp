//
// Created by Kim So Hee on 2022/08/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> times(n + 1);
        vector<int> indegree(n + 1), visited(n + 1);
        vector<vector<int>> graph(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> times[i];
        }
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        int w;
        cin >> w;

        queue<int> q;
        for (int i = 1; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                visited[i] = times[i];
            }
        }

        while (!q.empty()) {
            int here = q.front();
            q.pop();
            for (const auto &child: graph[here]) {
                indegree[child]--;
                visited[child] = max(visited[child], visited[here] + times[child]);
                if (indegree[child] == 0) q.push(child);
            }
        }
        cout << visited[w] << '\n';
    }
}