#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int N;
int cache1[MAX + 1];
int cache2[MAX + 1];
int arr[MAX + 1];

void bottomUp() {
	int maxLen = 1;
	fill(cache1, cache1 + N + 1, 1);
	fill(cache2, cache2 + N + 1, 1);

	for (int i = 1; i < N; i++) {
		if (arr[i] >= arr[i - 1]) {
			cache1[i] = cache1[i - 1] + 1;
		}

		if(arr[i] <= arr[i - 1]) {
			cache2[i] = cache2[i - 1] + 1;
		}

		maxLen = max(maxLen, max(cache1[i], cache2[i]));
	}

	cout << maxLen;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bottomUp();

	return 0;
}