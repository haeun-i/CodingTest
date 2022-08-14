#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> res;
bool visited[101] = { 0, };
int depth[101] = { 0, };
int graph[101][101] = { 0, };
int n, m;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[x][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
				depth[i] = depth[x] + 1;
			}
		}
	}
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = graph[n2][n1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		memset(depth, 0, sizeof(depth));
		bfs(i);
		int kevin = 0;
		for (int j = 1; j <= n; j++) {
			kevin += depth[j];
		}
		res.push_back(make_pair(kevin, i));
	}

	sort(res.begin(), res.end());

	cout << res[0].second << endl;
}