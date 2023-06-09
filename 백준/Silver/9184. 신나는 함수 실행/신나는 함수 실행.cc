#include <cstdio>
#include <memory.h>

using namespace std;

int cache[51][51][51];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (cache[a][b][c] != -1) return cache[a][b][c];

	if (a > 20 || b > 20 || c > 20) return cache[a][b][c] = w(20, 20, 20);

	if (a < b && b < c) return cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	int a, b, c;
	
	memset(cache, -1, sizeof(cache));
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}