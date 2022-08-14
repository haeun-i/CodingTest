#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string> str;
	vector<string> res;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.insert(make_pair(s, ""));
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (str.find(s) != str.end()) {
			res.push_back(s);
			cnt++;
		}
	}

	sort(res.begin(), res.end());
	cout << cnt << endl;

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}