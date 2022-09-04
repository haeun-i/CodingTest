#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	vector<int> v2;
	int counter, d, n, k, answer;
	cin >> d >> n;
	for (int i = 0; i < d; i++) {
		cin >> k;
		if (i != 0) {
			if (k > v[i - 1]) k = v[i - 1];
		}
		v.push_back(k);
	}
	for (int i = 0; i < n; i++) {
		cin >> k;
		v2.push_back(k);
	}
	counter = 0;
	answer = 0;
	for (int i = d - 1; i >=0; i--) {
		if (v2[counter] <= v[i]) {
			counter++;
			answer = i;
		}
		if (counter == n) break;
	}
	if (answer <= 0) cout << 0;
	else cout << answer + 1;
}