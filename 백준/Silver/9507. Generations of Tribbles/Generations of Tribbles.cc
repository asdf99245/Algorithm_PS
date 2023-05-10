#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

typedef long long ll;
ll cache[68];

ll koong(int n) {
	if (cache[n] != -1) return cache[n];

	return cache[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main() {
	int t;
	cin >> t;

	fill(cache, cache + 68, -1);

	cache[0] = cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	
	int n;
	while (t--) {
		cin >> n;
		cout << koong(n) << endl;
	}

	return 0;
}