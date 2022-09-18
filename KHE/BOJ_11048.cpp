#include <iostream>
#include <algorithm>
using namespace std;

int maze[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + maze[i][j];
		}
	}
	
	cout << dp[n][m];

}