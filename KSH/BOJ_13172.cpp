//
// Created by Kim So Hee on 2022/08/15.
//

#include <bits/stdc++.h>

#define MOD 1'000'000'007

using namespace std;

long long answer;
int m;

long long exp(int e, int num) {
    if (e == 1) return num;
    auto next = exp(e / 2, num);
    if (e % 2) {
        return next * next % MOD * num % MOD;
    } else {
        return next * next % MOD;
    }
}

long long run(int _b, int _a) {
    int gcd = std::gcd(_b, _a);
    int a = _a / gcd, b = _b / gcd;
    long long b_1 = exp(MOD - 2, b);

    return a * b_1 % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int n, s;
        cin >> n >> s;
        answer = (answer + run(n, s)) % MOD;
    }

    cout << answer;

}