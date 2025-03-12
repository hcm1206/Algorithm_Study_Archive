#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<vector<bool>>& v, int m, int n, int i, int j) {
	v[i][j] = false;
	if (i > 0 && j > 0 && v[i - 1][j - 1]) {
		dfs(v, m, n, i - 1, j - 1);
	}
	if (i > 0 && v[i - 1][j]) {
		dfs(v, m, n, i - 1, j);
	}
	if (i > 0 && j < n - 1 && v[i - 1][j + 1]) {
		dfs(v, m, n, i - 1, j + 1);
	}
	if (j > 0 && v[i][j - 1]) {
		dfs(v, m, n, i, j - 1);
	}
	if (j < n - 1 && v[i][j + 1]) {
		dfs(v, m, n, i, j + 1);
	}
	if (i < m - 1 && j > 0 && v[i + 1][j - 1]) {
		dfs(v, m, n, i + 1, j - 1);
	}
	if (i < m - 1 && v[i + 1][j]) {
		dfs(v, m, n, i + 1, j);
	}
	if (i < m - 1 && j < n - 1 && v[i + 1][j + 1]) {
		dfs(v, m, n, i + 1, j + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	vector<vector<bool>> v(m, vector<bool> (n, false));

	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j) {
			if (str[j] == '#') {
				v[i][j] = true;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j]) {
				cnt++;
				dfs(v, m, n, i, j);
			}
		}
	}

	cout << cnt;

	return 0;
}