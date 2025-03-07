#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void check(const vector<int>& population, const vector<vector<int>>& neighbors, vector<bool>& districts, int n, int idx, int& min) {
	if (idx > n) {
		int tcnt = 0;
		int fcnt = 0;

		int tstart = 0;
		int fstart = 0;

		for (int i = 1; i <= n; ++i) {
			if (districts[i]) {
				if (!tstart) {
					tstart = i;
				}
				tcnt += population[i];
			}
			else {
				if (!fstart) {
					fstart = i;
				}
				fcnt += population[i];
			}
		}

		if (!(tstart && fstart)) {
			return;
		}

		vector<bool> connected(n + 1, 0);
		queue<int> q;

		connected[tstart] = 1;
		connected[fstart] = 1;
		q.push(tstart);
		q.push(fstart);

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto neighbor : neighbors[now]) {
				if (districts[now] == districts[neighbor] && !connected[neighbor]) {
					connected[neighbor] = 1;
					q.push(neighbor);
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (!connected[i]) {
				return;
			}
		}

		int diff = tcnt - fcnt;
		if (diff < 0) {
			diff *= -1;
		}
		if (min < 0 || min > diff) {
			min = diff;
		}

	}
	else {
		districts[idx] = true;
		check(population, neighbors, districts, n, idx + 1, min);
		districts[idx] = false;
		check(population, neighbors, districts, n, idx + 1, min);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> population(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> population[i];
	}

	vector<vector<int>> neighbors(n + 1, vector<int>());

	for (int i = 1; i <= n; ++i) {
		int neighbor_cnt;
		cin >> neighbor_cnt;
		for (int j = 0; j < neighbor_cnt; ++j) {
			int neighbor;
			cin >> neighbor;
			neighbors[i].push_back(neighbor);
		}
	}

	vector<bool> districts(n + 1);
	int min = -1;

	check(population, neighbors, districts, n, 1, min);

	cout << min;

	return 0;
}