#include<iostream>
#include<algorithm>
using namespace std;

struct point{
	int x, y;
};
bool compare(const point& a, const point& b) {
	return a.x > b.x;
}
int main() {
	int answer = 0;
	struct point arr[8];
	int answerArr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i].x;
		arr[i].y = i + 1;
	}
	sort(arr, arr + 8, compare);
	for (int i = 0; i < 5; i++) {
		answer += arr[i].x;
		answerArr[i] = arr[i].y;
	}
	sort(answerArr, answerArr + 5);
	cout << answer << '\n';
	for (int i = 0; i < 5; i++)
		cout << answerArr[i] << " ";
	
}