#include<iostream>
#include<algorithm>
using namespace std;
int a, b,answer;
void dfs(int x, int y) {
	if (y >= 10)return;
	if (x > b)return;
	if (x >= a)answer += 1;
	dfs(x * 10 + 4, y + 1);
	dfs(x * 10 + 7, y + 1);
}
int main() {
	cin >> a >> b;
	dfs(0, 0);
	cout << answer;
}