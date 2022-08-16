#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count2 = 0, count5 = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			int num = i;
			while (num % 2 == 0) {
				num /= 2;
				count2++;
			}
		}
		if (i % 5 == 0) {
			int num = i;
			while (num % 5 == 0) {
				num /= 5;
				count5++;
			}
		}
	}
	
	cout << min(count2, count5) << endl;
}