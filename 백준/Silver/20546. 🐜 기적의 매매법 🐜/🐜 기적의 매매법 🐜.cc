#include <iostream>

using namespace std;

int stocks[15];

int _bnp(int amount) {
	int cnt = 0;
	for (int i = 0; i < 14; i++) {
		if (amount < stocks[i]) continue;

		int n = amount / stocks[i];
		cnt += n;
		amount -= n * stocks[i];
	}

	return amount + cnt * stocks[13];
}

int _timing(int amount) {
	int cnt = 0;

	int inc_cnt = 0;
	int dec_cnt = 0;
	for (int i = 1; i < 14; i++) {
		if (stocks[i - 1] < stocks[i]) {
			inc_cnt++;
			dec_cnt = 0;
		}
		else if (stocks[i - 1] > stocks[i]) {
			dec_cnt++;
			inc_cnt = 0;
		}
		else {
			dec_cnt = 0;
			inc_cnt = 0;
		}

		if (inc_cnt >= 3) {
			amount += cnt * stocks[i];
			cnt = 0;
		}

		if (dec_cnt >= 3) {
			int n = amount / stocks[i];
			cnt += n;
			amount -= n * stocks[i];
		}
	}

	return amount + cnt * stocks[13];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int amount;

	cin >> amount;
	for (int i = 0; i < 14; i++) {
		cin >> stocks[i];
	}

	int bnp = _bnp(amount);
	int timing = _timing(amount);

	if (bnp == timing) {
		cout << "SAMESAME";
	}
	else if (bnp > timing) {
		cout << "BNP";
	}
	else {
		cout << "TIMING";
	}

	return 0;
}