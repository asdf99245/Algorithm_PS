#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, int> umap;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int c = toupper(s[i]);

		if (umap[c]) umap[c]++;
		else umap[c] = 1;
	}

	bool flag = false;
	int maxCnt = 0;
	char maxChar;
	for (auto iter = umap.begin(); iter != umap.end(); iter++) {
		int cnt = iter->second;

		if (cnt == maxCnt) {
			flag = true;
		}

		if (maxCnt < cnt) {
			maxCnt = cnt;
			maxChar = iter->first;

			flag = false;
		}
	}

	if (flag) cout << '?';
	else cout << maxChar;

	return 0;
}