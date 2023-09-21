#include <iostream>
using namespace std;

char arr[500][500];

void drawStars(int start, int end, int len, int cnt) {
	if (len < 1) return;

	int pad = cnt * 2;
	for (int i = start; i <= end; i++) {
		if (i == start || i == end) {
			for (int j = pad; j < pad + len; j++) {
				arr[i][j] = '*';
			}
			continue;
		}

		arr[i][pad] = arr[i][pad + len - 1] = '*';
	}

	drawStars(start + 2, end - 2, len - 4, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int w = (n - 1) * 4 + 1;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			arr[i][j] = ' ';
		}
	}

	drawStars(0, w - 1, w, 0);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}