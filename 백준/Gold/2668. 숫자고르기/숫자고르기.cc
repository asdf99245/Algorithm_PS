#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int n;
int arr[101];
bool visited[101];
vector<int> ans;

void dfs(int curr, int start) {
	if (visited[curr]) {
		if(curr == start) ans.push_back(curr);
	}
	else {
		visited[curr] = true;
		dfs(arr[curr], start);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, i);
	}

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}