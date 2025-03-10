#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int ti = 0; ti < n; ++ti) {
		int m;
		cin >> m;

		int sr, sc, dr, dc;

		int** field = new int* [m];
		for (int i = 0; i < m; ++i) {
			string str;
			cin >> str;
			field[i] = new int[m];
			for (int j = 0; j < m; ++j) {
				if (str[j] == '*') {
					field[i][j] = -1;
				}
				else {
					field[i][j] = 0;
					if (str[j] == 's') {
						sr = i;
						sc = j;
					}
					else if (str[j] == 'd') {
						dr = i;
						dc = j;
					}
				}
			}
		}

		queue<pair<int, int>> q;
		q.push({ sr, sc });
		field[sr][sc] = 1;

		while (!q.empty()) {
			int nowr = q.front().first;
			int nowc = q.front().second;
			q.pop();
			if (nowr > 0 && !field[nowr - 1][nowc]) {
				field[nowr - 1][nowc] = field[nowr][nowc] + 1;
				q.push({ nowr - 1, nowc });
			}
			if (nowc > 0 && !field[nowr][nowc - 1]) {
				field[nowr][nowc - 1] = field[nowr][nowc] + 1;
				q.push({ nowr, nowc - 1 });
			}
			if (nowr < m - 1 && !field[nowr + 1][nowc]) {
				field[nowr + 1][nowc] = field[nowr][nowc] + 1;
				q.push({ nowr + 1, nowc });
			}
			if (nowc < m - 1 && !field[nowr][nowc + 1]) {
				field[nowr][nowc + 1] = field[nowr][nowc] + 1;
				q.push({ nowr, nowc + 1 });
			}
		}

		if (field[dr][dc]) {
			cout << field[dr][dc] - 1 << "\n";
		}
		else {
			cout << -1 << "\n";
		}

		for (int i = 0; i < m; ++i) {
			delete[] field[i];
		}
		delete[] field;
	}

	return 0;
}