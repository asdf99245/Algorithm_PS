#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <cmath>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

typedef struct Pos {
	int y;
	int x;
	int time;

	Pos(int _y, int _x, int _time):y(_y), x(_x), time(_time) {}
};

int n, m, t;
int map[101][101];
bool visited[101][101];

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int bfs(int y, int x, int destY, int destX) {
	memset(visited, false, sizeof(visited));
	visited[y][x] = true;
	queue<Pos> q;
	q.push(Pos(y,x,0));

	while (!q.empty()) {
		Pos fr = q.front();
		y = fr.y;
		x = fr.x;
		int time = fr.time;
		q.pop();

		if (y == destY && x == destX) return time;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || map[ny][nx] == 1) continue;

			visited[ny][nx] = true;
			q.push(Pos(ny,nx, time + 1));
		}
	}

	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> t;

	int gy, gx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				gy = i;
				gx = j;
			}
		}
	}

	int first = bfs(0, 0, n - 1, m - 1);

	int distToGram = bfs(0, 0, gy, gx);
	int second = (distToGram == INF ? INF : distToGram + abs(gy - n + 1) + abs(gx - m + 1));

	int minv = min(first, second);

	if (minv >= INF) {
		cout << "Fail";
		return 0;
	}
	
	if (minv > t) cout << "Fail";
	else cout << minv;

	return 0;
}