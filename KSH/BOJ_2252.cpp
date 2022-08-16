//
// Created by Kim So Hee on 2022/08/16.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> tree[32001];
int parent[32001];
bool visited[32001];

void post(int e) {
    visited[e] = true;
    for (const auto &child: tree[e]) {
        if (!visited[child]) post(child);
    }
    cout << e << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    /**
     * tree[right].push_back(left)
     * parent[left] = right
     *
     * parent[e] == 0, tree post order
     */

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        tree[b].push_back(a);
        parent[a] = b;
    }
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == 0) {
            post(i);
        }
    }
}