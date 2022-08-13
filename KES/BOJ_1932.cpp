#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int dp[501][501] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) dp[i][j] += dp[i - 1][j];
			else if (j == n) dp[i][j] += dp[i - 1][j - 1];
			else  dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int max = dp[n][1];
	for (int j = 1; j <= n; j++) {
		if (max < dp[n][j]) max = dp[n][j];
	}
	cout << max;
}