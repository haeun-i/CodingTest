//
// Created by Kim So Hee on 2022/08/14.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int items[101], answer;
int visited[101];
int graph[101][101];

void dfs(int i, int cost) {
    if (cost > m) return;
    if (visited[i] != -1 && visited[i] <= cost) return;
    visited[i] = cost;
    for (int j = 1; j <= n; ++j) {
        if (graph[i][j]) dfs(j, cost + graph[i][j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
    }
    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a][b] = graph[b][a] = l;
    }
    for (int i = 1; i <= n; ++i) {
        memset(visited, -1, sizeof(visited));
        dfs(i, 0);
        int temp = 0;
        for (int j = 1; j <= n; ++j) {
            if(visited[j] != -1) temp += items[j];
        }
        answer = max(answer, temp);
    }
    cout << answer;
}