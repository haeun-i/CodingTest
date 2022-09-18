#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m, k, answer;
	cin >> n >> m;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k < 0) v1.push_back(k);
		else v2.push_back(k);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	answer = 0;
	for (int i = 0; i < v1.size(); i += m)
		answer += abs(v1[i] * 2);
	for (int i = v2.size() - 1; i >= 0; i -= m)
		answer += v2[i] * 2; 
	if (!v1.empty() && !v2.empty())answer -= max(abs(v1[0]), v2[v2.size() - 1]);
	else if (v1.empty() && !v2.empty())answer -= v2[v2.size() - 1];
	else if (!v1.empty() && v2.empty())answer -= abs(v1[0]);
	cout << answer;
}