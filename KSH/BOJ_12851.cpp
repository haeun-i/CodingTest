//
// Created by Kim So Hee on 2022/08/09.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int visited[100001]{}, time = -1;
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    if (n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    }


    while (!q.empty()) {
        auto size = q.size();
        time++;
        for (int i = 0; i < size; ++i) {
            int here = q.front();
            q.pop();
            visited[here]++;

            int diff[3]{1, -1, here};
            for (const auto &d: diff) {
                int next = here + d;
                if (next < 0 || next > 100000) continue;

                /**
                 * queue 원소 중복 문제
                 *   - depth, count 배열로 분리 하는 것이 낫다
                 *   - time < depth[next]
                 *   - count[next] += count[here]
                 */
                if (!visited[next]) q.push(next);
            }
        }
        if (visited[k]) break;
    }
    cout << time << '\n' << visited[k];
}