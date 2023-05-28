#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

typedef struct Info {
	int y;
	int x;
	int cnt;
}Info;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int ans[1001][1001];

Info getInfo(int y, int x, int cnt) {
	Info info;
	info.y = y;
	info.x = x;
	info.cnt = cnt;

	return info;
}

void BFS(int y, int x, int n, int m) {
	visited[y][x] = true;
	queue<Info> q;
	q.push(getInfo(y, x, 0));
	int cnt;

	while (!q.empty()) {
		Info fr = q.front();
		y = fr.y;
		x = fr.x;
		cnt = fr.cnt;
		q.pop();

		ans[y][x] = cnt;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || map[ny][nx] == 0) continue;

			visited[ny][nx] = true;
			q.push(getInfo(ny, nx, cnt + 1));
		}
	}
}

int main() {
	cin >> n >> m;
	
	int destY, destX;

	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				destY = i;
				destX = j;
			}
			else if (map[i][j] == 0) {
				ans[i][j] = 0;
			}
		}
	}

	BFS(destY, destX, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}