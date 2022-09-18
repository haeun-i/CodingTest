#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[101][71];
bool visited[101][71] = { false };
bool flag = true;
int answer = 0;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void dfs(int a, int b) {
	visited[a][b] = true;
	for (int i = 0; i < 8; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		if (x < 0 || y < 0 || x >= n || y >= m) continue;
		if (arr[a][b] < arr[x][y]) flag = false;
		if (visited[x][y] == true)continue;
		if (arr[a][b] == arr[x][y]) dfs(x, y);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false) {
				flag = true;
				dfs(i, j);
				if (flag == true) answer++;
			}
		}
	}
	cout << answer;
}