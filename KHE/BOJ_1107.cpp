#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool broken[10] = { 0, };

bool check(int x){
	if (to_string(x).length() == 1) {
		if (broken[x]) return false;
	} 

	while (x != 0) {
		int p = x % 10;
		if (broken[p]) return false;
		x /= 10;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		broken[num] = true;
		cnt++;
	}

	int cnt1 = 0, cnt2 = 0;
	cnt1 = abs(n - 100); // 100에서 +-만 하는거
	
	int less = 0;
	for (int i = 0; i < 1000001; i++) {
		if (n-i >= 0 && check(n - i)) {
			less = n - i;
			break;
		}
		if (check(n + i)) {
			less = n + i;
			break;
		}
		
	}

	if (cnt == 0) {
		cout << min((int)(to_string(less).length()), cnt1);
	}
	else if(cnt == 10){
		cout << cnt1;
	}
	else {
		cnt2 = abs(less - n) + to_string(less).length();
		cout << min(cnt1, cnt2);
	}
	

}