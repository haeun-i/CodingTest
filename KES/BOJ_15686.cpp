#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n, m, k, numC;
int finalAnswer = 100000000;
struct spot {
	int x, y;
};
vector<spot> arrH;
vector<spot> arrC;
vector<spot> temp;
bool answerC[13];
void find(int a, int b) {
	if (b == m) {
		int result = 0;
		for (int i = 0; i < arrH.size(); i++) {
			int answer = 1000000000;
			for (int j = 0; j < temp.size(); j++) {
				answer = min(answer,
					(abs(arrH[i].x - temp[j].x) + abs(arrH[i].y - temp[j].y)));
			}
			result += answer;
		}
		finalAnswer = min(finalAnswer, result);
	}
	for (int i = a; i < arrC.size(); i++) {
		if (answerC[i] == true) continue;
		answerC[i] = true;
		temp.push_back({ arrC[i].x,arrC[i].y });
		find(i, b + 1);
		answerC[i] = false;
		temp.pop_back();
	}
}
int main() {
	cin >> n >> m;
	numC = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> k;
			if (k == 1) arrH.push_back({ i, j });
			else if (k == 2) arrC.push_back({ i, j });
		}
	}
	find(0, 0);
	cout << finalAnswer;
}