#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	vector<int> psum(m + 1, 0);

	for (int i = 1; i <= m; ++i) {
		int ai;
		cin >> ai;
		psum[i] = psum[i - 1] + ai;
	}

	for (int qi = 0; qi < n; ++qi) {
		int q;
		cin >> q;

		int lidx = 0;
		int ridx = m;

		while (lidx < ridx) {
			int middle = (lidx + ridx) / 2;
			if (psum[middle] == q) {
				ridx = middle;
				break;
			}
			else if (psum[middle] < q) {
				lidx = middle + 1;
			}
			else {
				ridx = middle;
			}
		}

		bool found = false;
		lidx = 0;
		while (ridx >= 0 && ridx <= m - lidx) {
			int nowsum = psum[m] - psum[m - lidx] + psum[ridx];
			if (nowsum == q) {
				found = true;
				break;
			}
			else if (nowsum < q) {
				lidx++;
			}
			else {
				ridx--;
			}
		}
		if (found) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}