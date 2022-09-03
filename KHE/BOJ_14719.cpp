#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	int road[501];

	for (int i = 0; i < w; i++) {
		cin >> road[i];
	}

	int cnt = 0;
	
	int left_max = 0;
	int right_max = 0;
	for (int i = 1; i < w-1; i++) {
		left_max = *max_element(&road[0], &road[i]);
		right_max = *max_element(&road[i + 1], &road[w]);

		if (left_max > road[i] && right_max > road[i]) {
			int height = min(left_max, right_max);
			cnt += height - road[i];
		}
	}

	cout << cnt << endl;
}