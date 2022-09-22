//
// Created by Kim So Hee on 2022/09/22.
//

#include <bits/stdc++.h>

using namespace std;

int n, s;
long long answer;
vector<int> inputs;
vector<int> sums[2];

void gen(int end, int index, int sum) {
    if (index == end) return;

    int next = sum + inputs[index];
    if (next == s) answer++;

    if (end == n) sums[1].push_back(next);
    else sums[0].push_back(next);

    gen(end, index + 1, next);
    gen(end, index + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;

    inputs.resize(n);

    for (int i = 0; i < n; ++i) cin >> inputs[i];

    /**
     * N의 범위의 절반 값으로 문제를 해결 할 수 있을 때, Meet in the middle 기법을 고려해볼 수 있다.
     *  - 한 개의 그룹으로 완전 탐색을 하지 못하는 경우 두 개의 그룹으로 나누어 탐색
     *
     * mid 값을 기준으로 [0~mid), [mid, N) 로 두 개의 문제로 쪼개보자.
     * 우리가 찾고자 하는 합이 S가 되는 부분수열은 3가지 case 에 속한다.
        1. 부분 수열이 [0~mid) 에만 속한다.
        2. 부분 수열이 [mid~N) 에만 속한다.
        3. 부분 수열이 left, right에 걸쳐 존재한다.
     */
    gen(n / 2, 0, 0);
    gen(n, n / 2, 0);

    std::sort(sums[1].begin(), sums[1].end());

    /**
     * 개선 사항
     *  - gen 함수에서 집합의 합을 map으로 저장해서(sum:count) 체크할 수 있음
     *  - 굳이 이분 탐색 추가로 안해도 됨
     */
    for (const auto &sum: sums[0]) {
        auto lower = std::lower_bound(sums[1].begin(), sums[1].end(), s - sum) - sums[1].begin();
        auto upper = std::upper_bound(sums[1].begin(), sums[1].end(), s - sum) - sums[1].begin();
        answer += upper - lower;
    }

    cout << answer;
}