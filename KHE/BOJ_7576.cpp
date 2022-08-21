#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int tomato[1001][1001] = { 0, };
int checked[1001][1001] = { 0, };
queue<pair<int, int>> q;
int n, m;
int cnt = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 0 && checked[i][j] == 0) {
				return false;
			}
		}
	}
	return true;

}

bool firstcheck() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 0) {
				return false;
			}
		}
	}
	return true;

}

void bfs() {
	while (!q.empty()) {
		pair<int, int> num = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = num.first + dy[i];
			int nx = num.second + dx[i];

			
			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (tomato[ny][nx] == 0 && checked[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				checked[ny][nx] = checked[num.first][num.second] + 1;
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];

			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				checked[i][j] = 0;
			}
		}
	}

	if (firstcheck()) {
		cout << 0 << endl;
		return 0;
	}

	bfs();

	vector<int> find_max;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			find_max.push_back(checked[i][j]);
		}
	}
	sort(find_max.begin(), find_max.end());
	reverse(find_max.begin(), find_max.end());

	if (!check()) cout << -1 << endl;
	else cout << find_max[0] << endl;

}