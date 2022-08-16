#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num[11];
int oper[4];
int m = -1000000001;
int M = 1000000001;
void cal(int a, int b) {
	if (b == n) {
		if (a > m) m = a;
		if (a < M) M = a;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0) cal(a + num[b], b + 1);
			else if (i == 1) cal(a - num[b], b + 1);
			else if (i == 2) cal(a * num[b], b + 1);
			else if (i == 3) cal(a / num[b], b + 1);
			oper[i]++;
		}
	}
	return;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];
	cal(num[0], 1);
	cout << m << '\n' << M;
}