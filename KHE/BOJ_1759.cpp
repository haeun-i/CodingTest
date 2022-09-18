#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string arr[16]; 
string print_arr[16];
int checked[16];

int l, c;

void bt(int p, int x) {
	if (x == l) {

		bool flag = false;
		int cnt = 0;
		for (int i = 0; i < l; i++) {
			if (print_arr[i] == "a" || print_arr[i] == "e" || print_arr[i] == "i" || print_arr[i] == "o" || print_arr[i] == "u") {
				flag = true;
			}else{
				cnt++;
			}
		}

		if (flag && cnt >= 2) {
			for (int i = 0; i < l; i++) {
				cout << print_arr[i];
			}
			cout << '\n';
		}
		
		return;
	}

	for (int i = p; i < c; i++) {
		if (!checked[i]) {
			print_arr[x] = arr[i];
			checked[i] = 1;
			bt(i+1, x + 1);
			checked[i] = 0;
		}

	}
}


int main() {
	
	cin >> l >> c;

	
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + c);

	bt(0, 0);

}