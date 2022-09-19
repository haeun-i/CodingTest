//
// Created by Kim So Hee on 2022/09/19.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> answer;

        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<>> right;
        int number;

        cin >> number;
        left.push(number);

        for (int i = 1; i <= m; ++i) {
            int mid = left.top();
            if (i % 2) answer.push_back(mid);
            if (i == m)break;

            // logic
            cin >> number;
            if (mid < number) {
                if (left.size() == right.size()) {
                    // insert, right -> left move
                    right.push(number);

                    int swap = right.top();
                    right.pop();
                    left.push(swap);

                } else {
                    right.push(number);
                }

            } else {
                if (left.size() == right.size() + 1) {
                    // insert, left -> right move
                    left.push(number);

                    int swap = left.top();
                    left.pop();
                    right.push(swap);
                } else {
                    left.push(number);
                }
            }
        }

        cout << answer.size() << '\n';

        for (int i = 1; i <= answer.size(); ++i) {
            cout << answer[i - 1];
            if (i % 10 && i != answer.size()) cout << ' ';
            else cout << '\n';
        }

    }

}