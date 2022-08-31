//
// Created by Kim So Hee on 2022/08/26.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n; // 5000
    vector<int> inputs(n);
    vector<int> answer;

    for (int i = 0; i < n; ++i) cin >> inputs[i];
    std::sort(inputs.begin(), inputs.end());

    long long temp = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            long long sum = inputs[i] + inputs[j];
            auto right = std::lower_bound(inputs.begin() + i + 1, inputs.begin() + j - 1, -sum);
            auto left = right - 1;
            int select;
            if (*left == inputs[i]) select = *right;
            else if (sum + *right < abs(sum + *left)) select = *right;
            else select = *left;

            if (abs(sum + select) < temp) {
                temp = abs(sum + select);
                answer.clear();
                answer.push_back(select);
                answer.push_back(inputs[i]);
                answer.push_back(inputs[j]);
            }
        }
    }

    std::sort(answer.begin(), answer.end());
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << ' ';

}