// BOJ 1541 ÀÒ¾î¹ö¸° °ıÈ£
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	string s;
	cin >> s;

	string part = "";
	int res = 0;
	bool flag = false;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			if (!flag) {
				res += stoi(part);
				flag = false;
			}
			else if (flag) {
				res -= stoi(part);
				flag = true;
			}

			part = "";
		}
		else if (s[i] == '-') {
			if (!flag) {
				res += stoi(part);
				flag = true;
			}
			else if (flag) {
				res -= stoi(part);
				flag = true;
			}

			part = "";
		}
		else {
			part += s[i];
		}
	
	}

	if (!flag) {
		res += stoi(part);
	}
	else if (flag) {
		res -= stoi(part);
	}

	cout << res << endl;
}