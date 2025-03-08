#include <iostream>
#include <vector>
#include <set>
using namespace std;

void backtrack(vector<bool>& valid, const set<pair<int, int>>& friends, int n, int idx, int onstage, int& max) {
	bool notpaired = true;
	bool noleft = true;
	for (int i = idx; i <= n; ++i) {
		if (!valid[i]) {
			continue;
		}
		noleft = false;
		for (int j = i + 1; j <= n; ++j) {
			if (valid[j] && friends.find({ i, j }) != friends.end()) {
				valid[i] = false;
				valid[j] = false;
				backtrack(valid, friends, n, i + 1, onstage + 2, max);
				valid[i] = true;
				valid[j] = true;
				notpaired = false;
			}
		}
	}

	if (notpaired) {
		if (!noleft) {
			onstage++;
		}
		if (max < onstage) {
			max = onstage;
		}

	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	set<pair<int, int>> friends;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		friends.insert({ u, v });
		friends.insert({ v, u });
	}

	vector<bool> valid(n + 1, true);

	int max = 0;

	backtrack(valid, friends, n, 1, 0, max);

	cout << max;

	return 0;
}