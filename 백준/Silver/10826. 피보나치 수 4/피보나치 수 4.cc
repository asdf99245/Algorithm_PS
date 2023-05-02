#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int ll;

string cache[10001];

string sum(string a, string b) {
	string tmp;

	if (a.length() > b.length()) {
		tmp = a;
	}
	else {
		tmp = b;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < a.length() - tmp.length(); i++) a += '0';
	for (int i = 0; i < b.length() - tmp.length(); i++) b += '0';

	string ret = "";
	int up = 0;
	for (int i = 0; i < tmp.length(); i++) {
		int s = (a[i] - '0' + b[i] - '0' + up);
		ret += to_string(s % 10);
		up = s / 10;
	}

	if (up > 0) {
		ret += to_string(up);
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	cache[0] = "0";
	cache[1] = "1";
	for (int i = 2; i <= n; i++) {
		cache[i] = sum(cache[i - 1], cache[i - 2]);
	}

	cout << cache[n];

	return 0;
}