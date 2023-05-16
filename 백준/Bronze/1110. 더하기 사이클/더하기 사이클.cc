#include <iostream>

using namespace std;

int oper(int n) {
	int first = (n % 10) * 10;

	int second = 0;
	while (n != 0) {
		second += n % 10;
		n /= 10;
	}
	second %= 10;

	return first + second;
}

int getCycleLen(int n) {
	int init = n;

	int len = 1;
	while (true) {
		n = oper(n);
		if (n == init) return len;
		len++;
	}
}

int main() {
	int n;
	cin >> n;

	cout << getCycleLen(n);

	return 0;
}