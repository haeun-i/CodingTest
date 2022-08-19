#include <iostream>
#include <queue>
#include <string>
using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {

		queue<int> q;
		bool checked[10001] = { 0, };
		string depth[10001];
		fill_n(depth, 10001, "");

		int n1, n2;
		cin >> n1 >> n2;

		checked[n1] = 1;
		q.push(n1);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			if (x == n2) break;

			if (!checked[(2 * x)%10000]) { // D : °öÇÏ±â 2
				checked[(2 * x) % 10000] = 1;
				q.push((2 * x) % 10000);
				depth[(2 * x) % 10000] = depth[x] + "D";
			}
			if (!checked[x-1] &&  x != 0) { // S : »©±â 1
				checked[x - 1] = 1;
				q.push(x - 1);
				depth[x - 1] = depth[x] + "S";
			}
			if (x == 0 && !checked[9999]) {
				checked[9999] = 1;
				q.push(9999);
				depth[9999] = depth[x] + "S";
			}

			
			int nx = ((x % 1000) * 10) + (x / 1000);
			if (!checked[nx]) { // L : 2341
				checked[nx] = 1;
				q.push(nx);
				depth[nx] = depth[x] + "L";
			}

			nx = (x % 10) * 1000 + (x / 10);
			if (!checked[nx]) { // R : 4123
				checked[nx] = 1;
				q.push(nx);
				depth[nx] = depth[x] + "R";
			}
		}
	
		cout << depth[n2] << '\n';
	}

}