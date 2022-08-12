#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, b, c;
	long long answer;
	int a[1000000];
	cin >> n;
	answer = n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> b >> c;
	for (int i = 1; i <= n; i++) {
		a[i] -= b;
		if (a[i] > 0) {
			if (a[i] % c > 0)
				answer += a[i] / c + 1;
			else
				answer += a[i] / c;
			a[i] /= c;
		}
	}
	cout << answer;

	return 0;
}