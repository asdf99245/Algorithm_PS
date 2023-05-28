#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
vector<int> graph[2001];
bool visited[2001];

bool DFS(int curr, int cnt) {
	if (cnt == 4) {
		return true;
	}

	visited[curr] = true;

	bool ret = false;
	for (int i = 0; i < graph[curr].size(); i++) {
		int next = graph[curr][i];

		if (visited[next]) continue;
		ret = DFS(next, cnt + 1);
		visited[next] = false;
		if (ret) return ret;
	}

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));

		if (DFS(i, 0)) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}