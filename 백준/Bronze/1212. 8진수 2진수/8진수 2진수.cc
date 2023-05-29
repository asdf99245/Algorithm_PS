#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<int> v;

int main() {
	string n;
	cin >> n;

	if (n == "0") {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n.length(); i++) {
		int num = n[i] - '0';

		int mod = 4;

		while (mod != 0) {
			v.push_back(num / mod);

			num %= mod;
			mod /= 2; 
		}
	}

	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		if (!flag && v[i] == 0) continue;
		else if(!flag && v[i] == 1) flag = true;

		cout << v[i];
	}

	return 0;
}