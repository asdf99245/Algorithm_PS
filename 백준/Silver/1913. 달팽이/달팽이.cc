#include <iostream>

using namespace std;

int arr[1000][1000];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int ty, tx;

int rotateDir(int dir) {
	if (dir == 3) return 0;
	else return dir + 1;
}

void f(int curr, int n, int target) {
	int y = 0, x = 0;
	int dir = 0;
	while (curr > 0) {
		if (curr == target) {
			ty = y;
			tx = x;
		}

		arr[y][x] = curr--;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] > 0) {
			dir = rotateDir(dir);
			ny = y + dy[dir];
			nx = x + dx[dir];
		}

		y = ny;
		x = nx;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int n, num;
	cin >> n >> num;

	f(n * n, n, num);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << ty + 1 << ' ' << tx + 1;

	return 0;
}