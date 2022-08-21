#include <iostream>
#include <cstring>
using namespace std;

int graph[101][101] = { 0, };
bool visited[101][101] = { 0, };
int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void color(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] == 0 && graph[ny][nx] == graph[y][x]) {
			color(ny, nx);
		}
	}
}


void notcolor(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] == 0 && graph[ny][nx] == graph[y][x]) {
			notcolor(ny, nx);
		}else if (visited[ny][nx] == 0 && graph[y][x] == 1 && graph[ny][nx] == 0) {
			notcolor(ny, nx);
		}else if (visited[ny][nx] == 0 && graph[y][x] == 0 && graph[ny][nx] == 1) {
			notcolor(ny, nx);
		}
	}
}

int main() {

	cin >> n;
	int cnt_color = 0, cnt_notcolor = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char s;
			cin >> s;

			if (s == 'R') graph[i][j] = 0;
			else if (s == 'G') graph[i][j] = 1;
			else if (s == 'B') graph[i][j] = 2;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				color(i, j);
				cnt_color++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				notcolor(i, j);
				cnt_notcolor++;
			}
		}
	}

	cout << cnt_color << " " << cnt_notcolor;
}