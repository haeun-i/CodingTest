#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, ans;
	vector<string> answer;
	vector<string> unknown;
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n + m; i++) {
		cin >> temp;
		unknown.push_back(temp);
	}
	sort(unknown.begin(), unknown.end());
	ans = 0;
	for (int i = 0; i < n + m - 1; i++) {
		if (unknown[i] == unknown[i + 1]) {
			temp = unknown[i];
			ans++;
			answer.push_back(temp);
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}