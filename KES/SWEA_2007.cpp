#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv)
{
	int t, n;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		string s, k, j;
		cin >> s;
		n = 0;
		k = s.substr(0, 2);
		j = "";
		for (int i = 2; i <= 10; i++) {
			if (k == s.substr(i, k.length())) {
				if (k.length() % 2 == 0 && j == k.substr(0, k.length() / 2)) continue;
				else {
					j = k;
					n = i;
				}
			}
			k += s[i];
		}
		int flag = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[0] == s[i]) flag++;
		}
		if (flag == 31) n = 1;
		cout << "#" << test << " " << n << '\n';
	}

	return 0;
}