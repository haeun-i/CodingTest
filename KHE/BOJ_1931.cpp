#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v.push_back(make_pair(n2, n1));
	}

	sort(v.begin(), v.end());

	int cnt = 1;
	int last = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= last) {
			cnt++;
			last = v[i].first;
		}
	}
	
	cout << cnt;
}