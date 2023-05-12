#include <iostream>
#include <algorithm>

using namespace std;

int n;
double cache[10001];
double arr[10001];

double bottomUp() {
	cache[0] = arr[0];
	double ret = cache[0];

	for (int i = 1; i < n; i++) {
		cache[i] = max(cache[i - 1] * arr[i], arr[i]);
		ret = max(cache[i], ret);
	}

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << fixed;
	cout.precision(3);
	cout << bottomUp();
	return 0;
}