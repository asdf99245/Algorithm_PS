#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string tree;
	int n = 0;
	while (true) {
		getline(cin, tree);
		if (cin.eof()) break;

		if (!mp[tree]) mp[tree] = 1;
		else mp[tree]++;
		n++;
	}

	cout.precision(4);
	cout << fixed;

	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		string name = iter->first;
		int cnt = iter->second;
		cout << name << ' ' << (double)cnt / n * 100 << '\n';
	}
	return 0;
}