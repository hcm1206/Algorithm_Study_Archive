#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int k, c;
	cin >> k >> c;

	vector<vector<char>> grid(n, vector<char>(m));

	int si = 0, sj = 0;
	int ei = 0, ej = 0;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j) {
			grid[i][j] = str[j];
			if (str[j] == 'S') {
				si = i;
				sj = j;
			}
			else if (str[j] == 'E') {
				ei = i;
				ej = j;
			}
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 100));

	int elapsed = 0;

	queue<tuple<int, int, int>> q;

	dp[si][sj] = 0;
	q.push({ si, sj, 0 });

	bool notfound = true;

	while (notfound && !q.empty()) {
		elapsed++;
		q.push({ -1, -1, -1 });
		while (get<0>(q.front()) >= 0) {
			int nowi = get<0>(q.front());
			int nowj = get<1>(q.front());
			int value = get<2>(q.front());
			q.pop();

			if (value && grid[nowi][nowj] == 'H') {
				int newvalue = value - k;
				if (newvalue < 0) {
					newvalue = 0;
				}
				if (dp[nowi][nowj] > newvalue) {
					dp[nowi][nowj] = newvalue;
					q.push({ nowi, nowj, newvalue });
				}
			}
			if (nowi > 0 && grid[nowi - 1][nowj] != '#') {
				if (grid[nowi - 1][nowj] == 'H') {
					int newvalue = value - k;
					if (newvalue < 0) {
						newvalue = 0;
					}
					if (dp[nowi - 1][nowj] > newvalue) {
						dp[nowi - 1][nowj] = newvalue;
						q.push({ nowi - 1, nowj, newvalue });
					}
				}
				else {
					if (dp[nowi - 1][nowj] > value + c) {
						dp[nowi - 1][nowj] = value + c;
						q.push({ nowi - 1, nowj, dp[nowi - 1][nowj] });
					}
				}
			}
			if (nowi < n - 1 && grid[nowi + 1][nowj] != '#') {
				if (grid[nowi + 1][nowj] == 'H') {
					int newvalue = value - k;
					if (newvalue < 0) {
						newvalue = 0;
					}
					if (dp[nowi + 1][nowj] > newvalue) {
						dp[nowi + 1][nowj] = newvalue;
						q.push({ nowi + 1, nowj, dp[nowi + 1][nowj] });
					}
				}
				else {
					if (dp[nowi + 1][nowj] > value + c) {
						dp[nowi + 1][nowj] = value + c;
						q.push({ nowi + 1, nowj, dp[nowi + 1][nowj] });
					}
				}
			}
			if (nowj > 0 && grid[nowi][nowj - 1] != '#') {
				if (grid[nowi][nowj - 1] == 'H') {
					int newvalue = value - k;
					if (newvalue < 0) {
						newvalue = 0;
					}
					if (dp[nowi][nowj - 1] > newvalue) {
						dp[nowi][nowj - 1] = newvalue;
						q.push({ nowi, nowj - 1, dp[nowi][nowj - 1] });
					}
				}
				else {
					if (dp[nowi][nowj - 1] > value + c) {
						dp[nowi][nowj - 1] = value + c;
						q.push({ nowi, nowj - 1, dp[nowi][nowj - 1] });
					}
				}
			}
			if (nowj < m - 1 && grid[nowi][nowj + 1] != '#') {
				if (grid[nowi][nowj + 1] == 'H') {
					int newvalue = value - k;
					if (newvalue < 0) {
						newvalue = 0;
					}
					if (dp[nowi][nowj + 1] > newvalue) {
						dp[nowi][nowj + 1] = newvalue;
						q.push({ nowi, nowj + 1, dp[nowi][nowj + 1] });
					}
				}
				else {
					if (dp[nowi][nowj + 1] > value + c) {
						dp[nowi][nowj + 1] = value + c;
						q.push({ nowi, nowj + 1, dp[nowi][nowj + 1] });
					}
				}
			}

			if (dp[ei][ej] < 100) {
				notfound = false;
				break;
			}
		}
		q.pop();
	}

	if (notfound) {
		cout << -1;
	}
	else {
		cout << elapsed;
	}

	return 0;
}