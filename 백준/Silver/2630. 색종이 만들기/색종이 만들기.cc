#include <iostream>

using namespace std;

int n;
int arr[129][129];

int blue = 0;
int white = 0;

bool isMixed(int xs, int xe, int ys, int ye) {
	int col = arr[xs][ys];
	for (int i = xs; i <= xe; i++) {
		for (int j = ys; j <= ye; j++) {
			if (col != arr[i][j]) return false;
		}
	}

	return true;
}

void d_and_c(int xs, int xe, int ys, int ye) {
	if (isMixed(xs, xe, ys, ye)) {
		if (arr[xs][ys] == 1) blue++;
		else white++;
		return;
	}

	int xmid = (xs + xe) / 2;
	int ymid = (ys + ye) / 2;

	d_and_c(xs, xmid, ys, ymid);
	d_and_c(xs, xmid, ymid + 1, ye);
	d_and_c(xmid + 1, xe, ys, ymid);
	d_and_c(xmid + 1, xe, ymid + 1, ye);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	d_and_c(0, n - 1, 0, n - 1);

	cout << white << '\n';
	cout << blue;

	return 0;
}