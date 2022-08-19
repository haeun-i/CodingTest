#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> word_map;
string word_arr[100001];

bool isNumber(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) return false;
	}
	return true;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		word_arr[i] = s;
		word_map.insert(make_pair(s, i));
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (isNumber(s)) {
			cout << word_arr[stoi(s)] << '\n';
		}
		else {
			cout << word_map.find(s)->second << '\n';
		}
	}

}