//
// Created by Kim So Hee on 2022/08/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> trace(n + 1);
    queue<int> q;
    q.push(n);
    int depth = -1;
    while (!q.empty()) {
        depth++;
        auto size = q.size();
        for (int i = 0; i < size; ++i) {
            int here = q.front();
            q.pop();
            if (here == 1) {
                cout << depth << '\n';
                vector<int> answer;
                int temp = 1;
                while (trace[temp]) answer.push_back(trace[temp]), temp = trace[temp];
                std::reverse(answer.begin(), answer.end());
                for (const auto &a: answer) {
                    cout << a << ' ';
                }
                cout << 1;
                return 0;
            }
            if (here % 3 == 0 && !trace[here / 3]) {
                trace[here / 3] = here;
                q.push(here / 3);
            }
            if (here % 2 == 0 && !trace[here / 2]) {
                trace[here / 2] = here;
                q.push(here / 2);
            }
            if (!trace[here - 1]) {
                trace[here - 1] = here;
                q.push(here - 1);
            }
        }
    }
}