//
// Created by Kim So Hee on 2022/09/04.
//

#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<pair<int, int>> inputs[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;

    /**
     * MST
     *  - 트리의 특수한 형태
     *  - 사이클 없음
     *  - (n - 1)개의 간선
     *
     * 음수 간선 가능
     * 절댓값 최대 백만
     *
     * 1. 크루스칼
     *   (탐욕법) 간선 선택 기반
     *   - 간선을 오름차순으로 정렬한다.
     *   - 가장 낮은 가중치, 사이클이 아닌 간선을 먼저 선택한다
     *   - 해당 간선을 MST 집합에 추가한다.
     *   - 양 끝 정점이 같은 집합에 속해있다면, 사이클 형성이다. (union find)
     *
     *   시간 복잡도 : O(E log V)
     *
     * 2. 프림
     *   (탐욕법) 단계적 확장, 정점 선택 기반
     *   - 처음엔 시작 정점 만 MST 집합에 포함된다.
     *   - MST 집합에 인접한 정점들 중, 최소 간선을 선택하여 트리를 확장한다.
     *   - 선택한 정점이 N개가 될 때까지 반복한다.
     *
     *   시간 복잡도 : O(E log V)
     */
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        inputs[a].emplace_back(b, c);
        inputs[b].emplace_back(a, c);
    }

    vector<bool> selected(V + 1);
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    for (int i = 0; i < V ; ++i) {
        while (!pq.empty()) {
            auto const [cost, here] = pq.top();
            if (!selected[here]) {
                selected[here] = true;
                for (const auto [next, distance]: inputs[here]) {
                    pq.push({distance, next});
                }
                answer += cost;
                break;
            }
            pq.pop();
        }
    }
    cout << answer;
}