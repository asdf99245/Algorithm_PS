#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
int cache[16][16][2];
bool visited[16][16][2];

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

bool isOut(int y, int x, int sy, int sx, int ey, int ex) {
	return y < sy || x < sx || y > ey || x > ex;
}

void dp(int sy, int sx, int ey, int ex) {
	queue<pii> q;
	q.push({ sy, sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isOut(ny, nx, sy, sx, ey, ex)) continue;
			if (visited[ny][nx][i]) continue;

			cache[ny][nx][i] += cache[y][x][0] + cache[y][x][1];
			q.push({ ny, nx });
			visited[ny][nx][i] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	cache[0][0][0] = 1;
	int ey = (K - 1) / M;
	int ex = (K - 1) % M;

	if (K == 0 || (ey == N - 1 && ex == M - 1)) {
		dp(0, 0, N - 1, M - 1);
	}
	else {
		dp(0, 0, ey, ex);
		dp(ey, ex, N - 1, M - 1);
	}

	cout << cache[N - 1][M - 1][0] + cache[N - 1][M - 1][1];

	return 0;
}