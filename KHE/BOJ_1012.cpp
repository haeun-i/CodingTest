// BOJ 1012 ����� ����
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

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue; // �𼭸��� ��� continue�� ���� ����ó��
		if (graph[ny][nx] && !checked[ny][nx]) { // ���� ���ǿ� ���� ��� ��� Ž��
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

		// test case���� �迭 �ʱ�ȭ
		memset(graph, 0, sizeof(graph));
		memset(checked, 0, sizeof(checked));
	
		// ������ �°� �׷��� ����
		for (int p = 0; p < k; p++) {
			int n1, n2;
			cin >> n1 >> n2;
			graph[n1][n2] = 1;
		}

		// �湮���� �ʰ� ���߰� �ִ� ������ dfs
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