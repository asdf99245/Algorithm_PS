#include <iostream>

using namespace std;

typedef pair<int, int> pii;
bool check[6][6];

pii map[26];

int checkBingo(int y, int x) {
	int bingo = 0;

	for (int i = 0; i < 5; i++) {
		int r = 0, c = 0;
		for (int j = 0; j < 5; j++) {
			r += check[i][j];
			c += check[j][i];
		}
		if (r == 5) bingo++;
		if (c == 5) bingo++;
	}

	int crossL = 0, crossR = 0;
	for (int i = 0; i < 5; i++) {
		crossL += check[i][i];
		crossR += check[4 - i][i];
	}
	if (crossL == 5) bingo++;
	if (crossR == 5) bingo++;

	return bingo;
}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			map[num] = { i, j };
		}
	}

	for (int i = 0; i < 25; i++) {
		int num;
		cin >> num;

		pii coord = map[num];
		check[coord.first][coord.second] = true;

		int bingo = checkBingo(coord.first, coord.second);

		if (bingo >= 3) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}