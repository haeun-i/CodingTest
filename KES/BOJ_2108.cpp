#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n, k, sum, mean, middle, mode, scope;
	cin >> n;
	sum = 0;
	int arr[500000] = {0,};
	for (int i = 0; i < n; i++) {
		cin >> k;
		sum += k;
		arr[i] = k;
	}
	sort(arr, arr + n);

	mean = round(double(sum) / n);
	middle = arr[(n - 1) / 2];
	int modeArr[8001] = { 0, };
	k = 0;
	mode = 0;
	for (int i = 0; i < n; i++) {
		modeArr[arr[i]+4000]++;
	}
	for (int i = 0; i <= 8000; i++) {
		if (modeArr[i] > k) {
			k = modeArr[i];
			mode = i;
		}
	}
	for (int i = mode + 1; i <= 8000; i++) {
		if (modeArr[i] == k) {
			mode = i;
			break;
		}
	}
	scope = arr[n-1] - arr[0];
	
	cout << mean <<'\n' << middle << '\n' << mode-4000 << '\n' << scope;
	return 0;
}