#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int graph[1025][1025];

int div(int y, int x, int dist) {
	
	if (dist == 1) {
		return graph[y][x];
	}
	else {
		vector<int> find_max;
		find_max.push_back(div(y, x, dist / 2));
		find_max.push_back(div(y + dist / 2, x, dist / 2));
		find_max.push_back(div(y , x + dist / 2, dist / 2));
		find_max.push_back(div(y + dist / 2, x + dist / 2, dist / 2));
		sort(find_max.begin(), find_max.end());
		return find_max[2];
	}
	
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	cout << div(0, 0, n) << endl;
}