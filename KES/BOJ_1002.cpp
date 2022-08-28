#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2, r1, r2, x, y, r, R;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		x = (x1 - x2) * (x1 - x2);
		y = (y1 - y2) * (y1 - y2);
		r = (r1 + r2) * (r1 + r2);
		R = (r1 - r2) * (r1 - r2);
		
		if (x == 0 && y == 0) {
			if (R == 0) cout << "-1" << '\n';
			else  cout << "0" << '\n';
		}
		else if (x + y == r || R == x + y)cout << "1" << '\n';
		else if (x + y < r && x + y > R) cout << "2" << '\n';
		else cout << "0" << '\n';
	}
}
