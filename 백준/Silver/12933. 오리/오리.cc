#include <iostream>
#include <string>

using namespace std;

char sounds[] = { 'q','u','a','c','k' };
bool check[2501];

int main() {
	string s;
	cin >> s;

	int num = 0;
	int cnt = s.length();
	for (int i = 0; i < s.length() - 4; i++) {
		if (check[i]) continue;
		int idx = 0;
		bool flag = false;
		for (int j = i; j < s.length(); j++) {
			if (check[j]) continue;

			if (s[j] == sounds[idx]) {
				if (idx == 4) {
					idx = 0;
					flag = true;
				}
				else idx++;
				check[j] = true;
				cnt--;
			}
		}

		if (idx != 0) {
			cout << -1;
			return 0;
		}

		if (flag) num++;
	}

	if (cnt > 0) {
		cout << -1;
	}
	else {
		cout << num;
	}

	return 0;
}