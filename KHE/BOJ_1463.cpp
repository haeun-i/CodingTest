// BOJ 1463 1로 만들기

#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001] = { 0, };
int n;
int cnt = 0;

int main() {
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {

		if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else dp[i] = dp[i - 1] + 1;
		
	}

	cout << dp[n] << endl;

}