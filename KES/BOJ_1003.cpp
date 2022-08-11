#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	int dp[41] = { 0,1, };
	while (t--) {
		cin >> n;
		for (int i = 2; i <= n;i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		if (n == 0) {
			cout << 1 << " " << 0 << '\n';
		}
		else {
			cout << dp[n-1] << " " << dp[n] << '\n';
		}
	}
	return 0;
}