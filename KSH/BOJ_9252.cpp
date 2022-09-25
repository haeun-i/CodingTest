//
// Created by Kim So Hee on 2022/09/08.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    /**
     * dp[i][j] = if input[i]==input[j], dp[i][j] + 1
     *            else max dp[i][j-1], dp[i-1][j]
     */

    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= s2.length(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string answer;
    int first = s1.length(), second = s2.length();

    /**
     * 역추적 이해 필요
     *   좌표를 저장하는 게 아니라, 크기 비교로 다음 지점 찾기
     */
    while (dp[first][second]) {
        if (s1[first - 1] == s2[second - 1]) {
            answer.push_back(s1[first - 1]);
            first--;
            second--;
        }
        else if (dp[first - 1][second] > dp[first][second - 1]) first--;
        else second--;
    }

    std::reverse(answer.begin(), answer.end());
    cout << dp[s1.length()][s2.length()] << '\n' << answer;

}