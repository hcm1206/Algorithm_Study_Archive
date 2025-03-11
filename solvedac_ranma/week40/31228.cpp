#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	while (a % b) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, k;
	cin >> n >> k;

	if (n / k <= 1) {
		k = n - k;
	}

	long long r = gcd(n, k);

	n /= r;
	k /= r;

	if (n % k == 0) {
		cout << 0;
	}
	else {
		cout << n * (k - 1);
	}

	return 0;
}