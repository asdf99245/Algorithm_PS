#include <iostream>

using namespace std;

int n, m;
bool switches[101];

void _switch(int gender, int num) {
	if (gender == 1) {
		for (int i = 1; i <= n; i++) {
			if (i % num == 0) switches[i] = !switches[i];
		}
	}
	else {
		int s = num, e = num;

		while (s >= 1 && e <= n && switches[s] == switches[e]) {
			if (s == e) switches[s] = !switches[s];
			else {
				switches[s] = !switches[s];
				switches[e] = !switches[e];
			}
			s--;
			e++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> switches[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int gender, num;
		cin >> gender >> num;

		_switch(gender, num);
	}

	for (int i = 1; i <= n; i++) {
		cout << switches[i] << ' ';

		if (i % 20 == 0) {
			cout << '\n';
		}
	}

	return 0;
}