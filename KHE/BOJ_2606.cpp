#include <iostream>
using namespace std;
int n;
int graph[101][101] = { 0, };
bool checked[101] = { 0, };
int cnt = 0;

void dfs(int x) {
	checked[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (!checked[i] && graph[x][i]) {
			cnt++;
			dfs(i);
		}
	}
}
int main() {
	int e;
	cin >> n >> e;


	for (int i = 0; i < e; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		graph[n1][n2] = graph[n2][n1] = 1;
	}

	dfs(1);
	cout << cnt << endl;
}