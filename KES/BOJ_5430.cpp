#include<iostream>
#include<algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
	int t, n, flagR, flagError;
	cin >> t;
	while (t--) {
		string p;
		string arr, k;
		deque<int> deq;
		cin >> p >> n >> arr;
		for (int i = 0; i < arr.length(); i++) {
			if (i == 0) continue;
			else if (arr[i] >= '0' && arr[i] <= '9') k += arr[i];
			else if (arr[i] == ',' || arr[i] == ']') {
				if (k.empty() != true) {
					deq.push_back(stoi(k));
					k = "";
				}
			}
		}
		flagR = 1;
		flagError = 1;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				flagR *= -1;
			}
			else if (p[i] == 'D') {
				if (deq.empty()) {
					cout << "error\n";
					flagError = 0;
					break;
				}
				else {
					if (flagR == 1) deq.pop_front();
					else deq.pop_back();
				}
			}
		}
		if (flagError == 1) {
			if (flagR == 1) {
				cout << '[';
				while (!deq.empty()) {
					cout << deq.front();
					deq.pop_front();
					if (!deq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!deq.empty()) {
					cout << deq.back();
					deq.pop_back();
					if (!deq.empty())
						cout << ',';
				}
				cout << "]\n";
			}
		}
	}
}