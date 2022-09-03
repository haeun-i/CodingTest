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
	}//리프 노드인 경우
	if (v[a].size() == 1 && v[a][0] == k) {
		answer++; return;
	}//자식 노드가 1개 있는데 그 노드가 삭제되는 경우
	for (int i = 0; i < v[a].size(); i++) {//자식이 존재하는 경우
		int t = v[a][i];//존재하는 자식 노드를 순서대로.
		if (visit[t] == false && t != k) {
			//방문하지도 않았고, 지워야할 노드도 아닐때
			visit[t] = true;//방문 처리
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