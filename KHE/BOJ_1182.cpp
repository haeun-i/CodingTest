#include <iostream>
using namespace std;

int n, s;
int cnt = 0;
int arr[21] = { 0, };

void find(int k, int sum) {

	if (k == n) {
		if (sum == s) cnt++;
		return;
	}

	find(k + 1, sum);
	find(k + 1, sum + arr[k]);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	find(0, 0);
	
	if (s == 0) cnt--;
	cout << cnt << '\n';
}