#include <iostream>
using namespace std;

int graph[65][65];

bool check(int y, int x, int dist) {
	int num = graph[y][x];
	for (int i = y; i < y + dist; i++) {
		for (int j = x; j < x + dist; j++) {
			if (graph[i][j] != num) return false;
		}
	}
	return true;
}
void tree(int y, int x, int n) {

	if (check(y, x, n)) {
		cout << graph[y][x];
	}
	else {
		cout << "(";
		tree(y, x, n / 2);
		tree(y, x+ n / 2, n / 2);
		tree(y + n / 2, x, n / 2);
		tree(y + n / 2, x + n / 2, n / 2);
		cout << ")";
	}

}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j] = s[j] -'0';
		}
	}

	tree(0, 0, n);
}

