#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		int n, m, k;
		cin >> n >> m >> k;

		bool valid = true;
		int prev;
		cin >> prev;

		for (int i = 1; i < n; ++i) {
			int h;
			cin >> h;

			if (prev + k <= h) {
				if (prev + k + m < h) {
					valid = false;
				}
				else {
					m -= h - prev - k;
				}
			}
			else {
				int left = h - k;
				if (left < 0) {
					left = 0;
				}
				m += prev - left;
			}
			prev = h;
		}

		if (valid) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}