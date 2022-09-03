#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k, root, answer = 0;
vector<int> v[51];
bool visit[51] = { false };
void dfs(int a) {
	if (a == k) {
		answer = 0;
		return;
	}
	if (v[a].size() == 0) {
		answer++; return;
	}//���� ����� ���
	if (v[a].size() == 1 && v[a][0] == k) {
		answer++; return;
	}//�ڽ� ��尡 1�� �ִµ� �� ��尡 �����Ǵ� ���
	for (int i = 0; i < v[a].size(); i++) {//�ڽ��� �����ϴ� ���
		int t = v[a][i];//�����ϴ� �ڽ� ��带 �������.
		if (visit[t] == false && t != k) {
			//�湮������ �ʾҰ�, �������� ��嵵 �ƴҶ�
			visit[t] = true;//�湮 ó��
			dfs(t);
		}
	}
	
}

int main() {
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else v[temp].push_back(i);
	}
	cin >> k;
	visit[k] = true;
	dfs(root);
	cout << answer;
}