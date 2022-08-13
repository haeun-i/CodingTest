//
// Created by Kim So Hee on 2022/08/14.
//

#include <bits/stdc++.h>

using namespace std;

int n;
long long b;
vector<vector<int>> inputs(5, vector<int>(5));

vector<vector<int>> multi(vector<vector<int>> left, vector<vector<int>> right) {
    vector<vector<int>> ret(5, vector<int>(5));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ret[i][j] += (left[i][k] * right[k][j]) % 1000;
            }
        }
    }

    return ret;
}

vector<vector<int>> solve(long long exp) {
    if (exp == 1) {
        return inputs;
    }

    auto divide = solve(exp / 2);

    if (exp % 2) {
        return multi(multi(divide, divide), inputs);
    } else {
        return multi(divide, divide);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> inputs[i][j];
        }
    }

    auto answer = solve(b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << answer[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }
}