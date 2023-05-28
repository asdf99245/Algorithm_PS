#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct Pos {
	int y;
	int x;
	int z;
};

int m, n, h;

int tomato[101][101][101];
bool visited[101][101][101];

int dy[] = { 0, 0, -1, 1, 0, 0 };
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

Pos getPos(int y, int x, int z) {
	Pos pos;
	pos.y = y;
	pos.x = x;
	pos.z = z;

	return pos;
}

int BFS(vector<Pos> riped, int unriped) {
	queue<Pos> q;
	for (int i = 0; i < riped.size(); i++) {
		Pos ripe = riped[i];
		q.push(ripe);

		visited[ripe.z][ripe.y][ripe.x] = true;
	}

	int time = 0;
	while (!q.empty()) {
		int sz = q.size();

		for (int i = 0; i < sz; i++) {
			Pos fr = q.front();
			int z = fr.z;
			int y = fr.y;
			int x = fr.x;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;
				if (visited[nz][ny][nx] || tomato[nz][ny][nx] == -1) continue;

				visited[nz][ny][nx] = true;
				q.push(getPos(ny, nx, nz));
				unriped--;
			}
		}

		time++;
		if (unriped == 0) break;
	}


	if (unriped > 0) return -1;

	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> h;

	int unriped = 0;

	vector<Pos> riped;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) unriped++;
				else if (tomato[i][j][k] == 1) {
					riped.push_back(getPos(j, k, i));
				}
			}
		}
	}

	if (unriped == 0) {
		cout << 0;

		return 0;
	}

	cout << BFS(riped, unriped);

	return 0;
}