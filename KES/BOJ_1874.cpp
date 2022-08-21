#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int n, k, counter;
	cin >> n;
	stack<int> myStack;
	string answer = "";
	counter = 1;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k >= counter) {
			for (int j = counter; j <= k; j++) {
				myStack.push(j);
				answer += "+\n";
				counter++;
			}
			myStack.pop();
			answer += "-\n";
		}
		else {
			if (myStack.top() == k) {
				myStack.pop();
				answer += "-\n";
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << answer;
}
	