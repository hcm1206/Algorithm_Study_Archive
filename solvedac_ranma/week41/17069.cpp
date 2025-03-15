#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<bool>> house(n + 1, vector<bool>(n + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			bool state;
			cin >> state;
			house[i][j] = state;
		}
	}

	vector<vector<vector<long long>>> cnt(n + 1, vector<vector<long long>>(n + 1, vector<long long>(3, 0)));

	cnt[1][1][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cnt[i][j][0]) {
				if (j < n - 1 && !house[i][j + 2]) {
					cnt[i][j + 1][0] += cnt[i][j][0];
				}
				if (i < n && j < n - 1 && !house[i + 1][j + 1] && !house[i + 1][j + 2] && !house[i][j + 2]) {
					cnt[i][j + 1][2] += cnt[i][j][0];
				}
			}
			if (cnt[i][j][1]) {
				if (i < n - 1 && !house[i + 2][j]) {
					cnt[i + 1][j][1] += cnt[i][j][1];
				}
				if (i < n - 1 && j < n && !house[i + 2][j] && !house[i + 2][j + 1] && !house[i + 1][j + 1]) {
					cnt[i + 1][j][2] += cnt[i][j][1];
				}
			}
			if (cnt[i][j][2]) {
				if (j < n - 1 && !house[i + 1][j + 2]) {
					cnt[i + 1][j + 1][0] += cnt[i][j][2];
				}
				if (i < n - 1 && !house[i + 2][j + 1]) {
					cnt[i + 1][j + 1][1] += cnt[i][j][2];
				}
				if (i < n - 1 && j < n - 1 && !house[i + 2][j + 1] && !house[i + 2][j + 2] && !house[i + 1][j + 2]) {
					cnt[i + 1][j + 1][2] += cnt[i][j][2];
				}
			}
		}
	}

	cout << cnt[n][n - 1][0] + cnt[n - 1][n][1] + cnt[n - 1][n - 1][2];

	return 0;
}