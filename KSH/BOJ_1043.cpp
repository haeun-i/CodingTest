//
// Created by Kim So Hee on 2022/08/13.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M>>T;
    unordered_set<int> us;
    vector<vector<int>> party;

    for (int i = 0; i < T; ++i) {
        int p; cin>>p;
        us.insert(p);
    }
    for (int i = 0; i < M; ++i) {
        int m; cin>>m;
        vector<int> p(m);
        for (int j = 0; j < m; ++j) {
            cin >> p[j];
        }
        party.push_back(p);
    }
    for (int i = 0; i < M; ++i) {
        for (const auto &p: party) {
            bool insert = false;
            for (const auto &person: p) {
                if(us.count(person)) insert = true;
            }
            if(insert){
                for (const auto &person: p) {
                    us.insert(person);
                }
            }
        }
    }
    int answer = 0;
    for (const auto &p: party) {
        bool fail = false;
        for (const auto &person: p) {
            if(us.count(person)) fail = true;
        }
        if(!fail) answer++;
    }
    cout<<answer;
}