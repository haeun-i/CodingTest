#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	int arr[1001][4];
	int dp[1001][4];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= 3; i++) {
		dp[0][i] = arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
	}
	int m = min(dp[n - 1][1], dp[n - 1][2]);
	cout << min(m, dp[n - 1][3]);
}
