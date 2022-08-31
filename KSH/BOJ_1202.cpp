//
// Created by Kim So Hee on 2022/09/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jewels(n);
    vector<int> backpack(k);
    long long answer = 0;

    for (int i = 0; i < n; ++i) cin >> jewels[i].first >> jewels[i].second;
    for (int i = 0; i < k; ++i) cin >> backpack[i];

    /**
     * 입력
     *  1. 가방이 여러개 (최대 30만개)
     *  2. 보석 무게 최대 100만, 가방 무게 최대 1억
     *  3. 가방에 최대 1개 보석만
     *
     * 구현
     *  1. 가방 오름차순 정렬 후 작은 가방부터 보석 넣기
     *  2. 그 가방이 넣을 수 있는 최대 효율적인 보석 찾기
     *    - 가방 무게 이하인 보석들을 우선순위큐에 삽입
     *    - 로그 복잡도 제한
     *
     */
    std::sort(jewels.rbegin(), jewels.rend());
    std::sort(backpack.begin(), backpack.end());

    priority_queue<int> pq;

    for (const auto &bag: backpack) {
        while (!jewels.empty() && (--jewels.end())->first <= bag)
            pq.push((--jewels.end())->second), jewels.pop_back();

        if(!pq.empty()){
            answer += pq.top(); pq.pop();
        }
    }

    cout << answer;
}