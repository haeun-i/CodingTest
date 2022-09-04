#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long answer = 1;
	for (int i = 1; i <= n; i++) {
		answer *= i;
		while (answer % 10 == 0)answer /= 10;
		answer %= 1000000000000;
	}
	answer %= 100000;
	if (0 <= answer && answer < 10)
		cout << "0000" << answer;
	else if (10 <= answer && answer < 100)
		cout << "000" << answer;
	else if (100 <= answer && answer < 1000)
		cout << "00" << answer;
	else if (1000 <= answer && answer < 10000)
		cout << "0" << answer;
	else cout << answer;
}