#include <iostream>
#include <string>

using namespace std;

int map[11][11];
char curr[11][11];

int dy[] = { 0,0,-1,1,-1,1,1,-1 };
int dx[] = { -1,1,0,0,-1,1,-1,1 };

void cntMine(int y, int x, int n) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (map[ny][nx] == -1) continue;
		map[ny][nx]++;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;

			if (c == '*') {
				map[i][j] = -1;
				cntMine(i, j, n);
			}
		}
	}

	bool mine = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> curr[i][j];
			if (curr[i][j] == 'x' && map[i][j] == -1) {
				mine = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c = curr[i][j];

			if (c == 'x') {
				if (map[i][j] == -1) cout << '*';
				else cout << map[i][j];
			}
			else {
				if (mine && map[i][j] == -1) cout << '*';
				else cout << c;
			}
		}
		cout << '\n';
	}


	return 0;
}