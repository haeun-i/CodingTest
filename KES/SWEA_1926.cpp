#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int n, flag;
	cin >> n;
	if (n < 10) {
		for (int i = 1; i <= n; i++) {
			if (i == 3 || i == 6 || i == 9)cout << "- ";
			else cout << i << " ";
		}
	}
	if (n >= 10 && n < 100) {
		for (int i = 1; i <= n; i++) {
			flag = 0;
			if (i / 10 == 3 || i / 10 == 6 || i / 10 == 9) {
				cout << "-"; flag = 1;
			}
			if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9) cout << "- ";
			else if (flag == 0) cout << i << " ";
			else cout << " ";
		}
	}
	if (n >= 100) {
		for (int i = 1; i <= n; i++) {
			flag = 0;
			if (i / 100 == 3 || i / 100 == 6 || i / 100 == 9) {
				cout << "-"; flag = 1;
			}
			if (i % 100 / 10 == 3 || i % 100 / 10 == 6 || i % 100 / 10 == 9) {
				cout << "-"; flag = 1;
			}
			if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9) cout << "- ";
			else if (flag == 0) cout << i << " ";
			else cout << " ";
		}
	}
}