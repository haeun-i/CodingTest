//
// Created by Kim So Hee on 2022/08/31.
//

#include <bits/stdc++.h>

using namespace std;

int inputs[9][9];
bool check[3][9][10]; // 정사각형, 행, 열 번호

bool solve(int cord) {
    if (cord == 90) return true;
    int y = cord / 10, x = cord % 10, rect = 3 * (y/3) + x/3, next = x == 8 ? (y + 1) * 10 : cord + 1;
    if (inputs[y][x]) return solve(next);

    bool exist[10]{};
    for (int i = 1; i <= 9; ++i) {
        if(check[0][rect][i]) exist[i] = true;
    }
    for (int i = 1; i <= 9; ++i) {
        if(check[1][y][i]) exist[i] = true;
    }
    for (int i = 1; i <= 9; ++i) {
        if(check[2][x][i]) exist[i] = true;
    }

    for (int i = 1; i <= 9; ++i) {
        if (!exist[i]) {
            /**
             * 숫자 놓기
             *  1. 잘 놓아 지면 next 호출
             *  2. next 호출이 false 이면 다음 숫자 놓기
             *  3. next 호출이 true 이면 return true
             */
            check[0][rect][i] = true;
            check[1][y][i] = true;
            check[2][x][i] = true;
            inputs[y][x] = i;

            if (solve(next)) return true;

            check[0][rect][i] = false;
            check[1][y][i] = false;
            check[2][x][i] = false;
            inputs[y][x] = 0;

        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i=0; i<9; i++) {
        for (int j = 0; j<9 ;j++) {
            char c;
            cin >> c;
            inputs[i][j] = c - '0';
            check[0][3 * (i/3) + j/3][inputs[i][j]] = true;
            check[1][i][inputs[i][j]] = true;
            check[2][j][inputs[i][j]] = true;
        }
    }

    solve(0);
    for (auto &input: inputs) {
        for (int &j: input) {
            cout << j;
        }
        cout << '\n';
    }
}