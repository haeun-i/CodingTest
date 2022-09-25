//
// Created by Kim So Hee on 2022/09/14.
//

#include <bits/stdc++.h>

using namespace std;

int A;
vector<int> inputs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A;
    inputs.resize(A);

    for (int i = 0; i < A; ++i) cin >> inputs[i];

    /**
     * O(n logn) LIS
     * key : LIS 의 마지막 원소가 가능한 작을 수록, 더 긴 LIS 를 생성할 수 있다.
     *
     * 원소가 현재 생성된 LIS 마지막 값보다 작을 경우, 이분 탐색으로 LIS 원소를 대체한다.
     *
     * 주의 : 길이만 구할 수 있고, 실제 LIS 수열은 구할 수 없다.
     * ex) 3, 5, 2, 6, 1
     *     실제 LIS : 3, 5, 6
     *     LIS 배열 : 1, 5, 6
     *
     *
     * +) 수열 모두 구하기
     * LIS 배열에 들어가는 원소의 index를 별도 저장한다.
     *
     * 그 후 마지막 원소 부터 LIS 길이를 감소 시켜 가면서,
     * 처음으로 해당 길이의 index가 나오는 원소를 뽑는다
     *
     * ex) [3, 5, 2, 6, 1]
     *    LIS: [1, 5, 6]
     *    index: [1, 2, 1, 3, 1]
     *
     *    뒤에서 부터 처음 3이 나오는 원소 : 6  // [3, 5, 2, 6]
     *    그 후 처음 2가 나오는 원소 : 5  // [3, 5]
     *    그 후 처음 1이 나오는 원소 : 1  // [3]
     */
    vector<int> answer;
    answer.push_back(inputs[0]);
    for (int i = 1; i < A; ++i) {
        int here = inputs[i];
        if (here > answer[answer.size() - 1]) answer.push_back(here);
        else {
            auto swap = std::lower_bound(answer.begin(), answer.end(),here);
            answer[swap - answer.begin()] = here;
        }
    }

    cout<<answer.size();
}