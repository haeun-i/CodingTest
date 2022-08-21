#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = { 0, };
int depth[100001] = { 0, };
int n, k;

void bfs() {
	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) break;
		
		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			q.push(x + 1);
			visited[x + 1] = 1;
			depth[x + 1] = depth[x] + 1;
		}
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			q.push(x - 1);
			visited[x - 1] = 1;
			depth[x - 1] = depth[x] + 1;
		}
		if (2 * x <= 100000 && visited[2 * x] == 0) {
			q.push(2 * x);
			visited[2 * x] = 1;
			depth[2 * x] = depth[x] + 1;
		}
	}
}

int main() {
	cin >> n >> k;
	bfs();
	cout << depth[k] << endl;
}