#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {

		vector<pair<int, int>> people;
		int cnt = 0;
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			people.push_back(make_pair(n1, n2));
		}

		sort(people.begin(), people.end()); // 서류면접 점수대로 정렬

		int min = INT_MAX;

		for (int i = 0; i < n; i++) {
			if (people[i].second < min) {
				cnt++;
				min = people[i].second;
			}
		
		}

		cout << cnt << endl;

	}
}
