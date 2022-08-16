#include <iostream>
#include <string>
#include <queue>
using namespace std;

int graph[101][101] = { 0, };
int depth[101][101] = { 0, };
bool checked[101][101] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	checked[y][x] = 1;
	depth[y][x] = 1;
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!checked[ny][nx] && graph[ny][nx]) {
				q.push(make_pair(ny, nx));
				checked[ny][nx] = 1;
				depth[ny][nx] = depth[y][x] + 1;
			}

		}
	}
	
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string n;
		cin >> n;
		for (int j = 0; j < m; j++) {
			graph[i][j] = n[j] - '0';
		}
	}

	bfs(0, 0);

	

	cout << depth[n - 1][m - 1] << endl;
}