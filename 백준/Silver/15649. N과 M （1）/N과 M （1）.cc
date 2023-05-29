#include <iostream>
#include <vector>

using namespace std;

bool visited[9];

void dfs(vector<int> acc, int n, int m) {
	if (acc.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << acc[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		acc.push_back(i);
		dfs(acc, n, m);
		visited[i] = false;
		acc.pop_back();
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	vector<int> v;
	dfs(v, n, m);
	return 0;
}