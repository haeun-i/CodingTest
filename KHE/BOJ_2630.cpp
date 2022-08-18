#include <iostream>
using namespace std;

int n, cnt_w, cnt_b;
int paper[129][129];

bool check(int x, int y, int dist) {
	for (int i = y; i < y+dist; i++) {
		for (int j = x; j < x+dist; j++) {
			if (paper[y][x] != paper[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void cal(int x, int y, int dist) {
	if (check(x, y, dist)) {
		if (paper[y][x]) cnt_b++;
		else cnt_w++;
	}
	else {
		cal(x, y, dist / 2);
		cal(x + dist / 2, y , dist / 2);
		cal(x, y + dist / 2, dist / 2);
		cal(x + dist / 2, y + dist / 2, dist / 2);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	cal(0, 0, n);
	cout << cnt_w << endl << cnt_b;
}