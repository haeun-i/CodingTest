//
// Created by Kim So Hee on 2022/08/12.
//

#include <bits/stdc++.h>

using namespace std;
int tree[1000001][2];

void post(int number) {
    if (number == 0) return;
    post(tree[number][0]);
    post(tree[number][1]);
    cout << number << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int root, node;
    cin >> root;
    while (cin >> node) {
        int temp = root;
        while (true) {
            if (node < temp) {
                if (!tree[temp][0]) {
                    tree[temp][0] = node;
                    break;
                }
                temp = tree[temp][0];
            } else if (node > temp) {
                if (!tree[temp][1]) {
                    tree[temp][1] = node;
                    break;
                }
                temp = tree[temp][1];
            }
        }
    }

    post(root);
}