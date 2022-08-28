#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, }; // ī�� i���� ��� ���� �ִ�
int dp[1001] = { 0, };
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		
		}
	}

	cout << dp[n];

}