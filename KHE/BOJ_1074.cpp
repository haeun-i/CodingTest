#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;

void check(int x, int y, int n) {
	if (n == 1) return;

	int half = n / 2;
	if (r < y + half && c < x + half) {
		check(x, y, half);
	}
	else if (r < y + half && c >= x + half) {
		cnt += half * half;
		check(x + half, y, half);
	}
	else if (r >= y + half && c < x + half) {
		cnt += half * half * 2;
		check(x, y + half, half);
	}
	else if (r >= y + half && c >= x + half) {
		cnt += half * half * 3;
		check(x + half, y + half, half);
	}
}

int main() {
	cin >> n >> r >> c;
	check(0, 0, pow(2, n));
	cout << cnt << endl;
}