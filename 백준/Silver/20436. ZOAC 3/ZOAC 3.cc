#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
unordered_map<char, pii> umap;
unordered_set<char> leftKeys { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v' };
unordered_set<char> rightKeys { 'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm' };

string keyboard[3] = {
	"qwertyuiop", "asdfghjkl", "zxcvbnm"
};

int getDistance(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < keyboard[i].length(); j++) {
			char key = keyboard[i][j];
			umap[key] = { i,j };
		}
	}

	char leftKey, rightKey;
	cin >> leftKey >> rightKey;

	pii leftPos = umap[leftKey];
	pii rightPos = umap[rightKey];

	string word;
	cin >> word;

	int answer = 0;
	for (int i = 0; i < word.length(); i++) {
		char c = word[i];
		if (leftKeys.count(c) == 1) {
			answer += getDistance(leftPos, umap[c]);
			leftPos = umap[c];
			continue;
		}

		answer += getDistance(rightPos, umap[c]);
		rightPos = umap[c];
	}

	cout << answer + word.length();
	return 0;
}