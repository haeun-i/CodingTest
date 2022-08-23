//
// Created by Kim So Hee on 2022/08/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) cin >> inputs[i];
    std::sort(inputs.begin(), inputs.end());
    int temp = INT_MAX, answer1, answer2;

    /**
     * two pointer
     *
     * inputs[left] + inputs[right] = temp
     * temp > 0, 감소시켜야 하므로 right--
     * abs(temp) 갱신 시 left, right pointer 저장
     *
     */

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = inputs[left] + inputs[right];
        if (abs(sum) < temp) temp = abs(sum), answer1 = inputs[left], answer2 = inputs[right];

        if (sum < 0) left++;
        else right--;
    }

    cout << answer1 << ' ' << answer2;
}