#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
vector<int> graph[1001];
bool visited[1001];

void DFS(int start) {
	visited[start] = true;
	cout << start << ' ';

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next]) continue;

		DFS(next);
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];
			if (visited[next]) continue;

			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	cout << '\n';
	fill(visited, visited + n + 1, false);
	BFS(v);

	return 0;
}