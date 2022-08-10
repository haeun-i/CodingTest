// BOJ 1012 유기농 배추
#include <iostream>
#include <string>
using namespace std;

int graph[51][51] = { 0, };
int checked[51][51] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int m, n, k;

void dfs(int y, int x) {
	checked[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue; // 모서리의 경우 continue를 통해 예외처리
		if (graph[ny][nx] && !checked[ny][nx]) { // 옆이 조건에 맞을 경우 계속 탐색
			dfs(ny, nx);
		}
	}
	
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> m >> n >> k;

		// test case마다 배열 초기화
		memset(graph, 0, sizeof(graph));
		memset(checked, 0, sizeof(checked));
	
		// 문제에 맞게 그래프 설정
		for (int p = 0; p < k; p++) {
			int n1, n2;
			cin >> n1 >> n2;
			graph[n1][n2] = 1;
		}

		// 방문하지 않고 배추가 있는 곳에서 dfs
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!checked[i][j] && graph[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;
	}

}