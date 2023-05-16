#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool checkGroupWord(string w) {
	unordered_map<char, bool> umap;

	umap[w[0]] = true;
	for (int i = 1; i < w.length(); i++) {
		if (w[i] == w[i - 1]) continue;
		
		if (umap[w[i]]) return false;
		umap[w[i]] = true;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	string word;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (checkGroupWord(word)) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}