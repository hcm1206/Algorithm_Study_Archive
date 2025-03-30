#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> lis;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		int l = 0;
		int r = static_cast<int>(lis.size());
		while (l < r) {
			int m = (l + r) / 2;
			if (num < lis[m]) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}
		if (r >= static_cast<int>(lis.size())) {
			lis.push_back(num);
		}
		else {
			lis[r] = num;
		}
	}
	cout << n - static_cast<int>(lis.size());

	return 0;
}