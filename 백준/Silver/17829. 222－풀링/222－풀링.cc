#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1025][1025];

int getSecondLargestNumber(vector<int> v) {
	sort(v.begin(), v.end());

	return v[2];
}

int d_and_c(int sx, int sy, int len) {
	if (len == 2) {
		vector<int> v;
		for (int i = sy; i < sy + 2; i++) {
			for (int j = sx; j < sx + 2; j++) {
				v.push_back(arr[i][j]);
			}
		}

		return getSecondLargestNumber(v);
	}

	vector<int> v;
	int half = len / 2;
	v.push_back(d_and_c(sx, sy, half));
	v.push_back(d_and_c(sx, sy + half, half));
	v.push_back(d_and_c(sx + half, sy, half));
	v.push_back(d_and_c(sx + half, sy + half, half));

	return getSecondLargestNumber(v);
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

	cout << d_and_c(0, 0, n);

	return 0;
}