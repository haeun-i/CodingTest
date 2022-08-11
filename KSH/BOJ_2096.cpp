//
// Created by Kim So Hee on 2022/08/11.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int minDp[2][3]{}, maxDp[2][3]{};

    for (int i = 1; i <= n; ++i) {
        int prev = (i - 1) % 2, cur = i % 2;
        int left, middle, right;
        cin >> left >> middle >> right;
        minDp[cur][0] = min(minDp[prev][0], minDp[prev][1]) + left;
        minDp[cur][1] = min({minDp[prev][0], minDp[prev][1], minDp[prev][2]}) + middle;
        minDp[cur][2] = min(minDp[prev][1], minDp[prev][2]) + right;

        maxDp[cur][0] = max(maxDp[prev][0], maxDp[prev][1]) + left;
        maxDp[cur][1] = max({maxDp[prev][0], maxDp[prev][1], maxDp[prev][2]}) + middle;
        maxDp[cur][2] = max(maxDp[prev][1], maxDp[prev][2]) + right;
    }

    cout << *max_element(maxDp[n % 2], maxDp[n % 2] + 3) << ' ';
    cout << *min_element(minDp[n % 2], minDp[n % 2] + 3) << ' ';
}