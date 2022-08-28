#include<iostream>
#include<algorithm>
using namespace std;
long long f(int a, int b, int c) {
	if (b == 1)return a % c;
	if (b % 2 == 0)return (f(a, b / 2, c) * f(a, b / 2, c)) % c;
	else return ((f(a, b / 2, c) * f(a, b / 2, c)) % c) * a % c;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << f(a, b, c);
}
