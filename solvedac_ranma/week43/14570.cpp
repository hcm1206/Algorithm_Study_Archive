#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> bt(n + 1, { -1, -1 });

	for (int i = 1; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		bt[i].first = u;
		bt[i].second = v;
	}

	long long k;
	cin >> k;

	int node = 1;
	long long mod = 0;
	long long div = 1;

	while (bt[node].first > 0 || bt[node].second > 0) {
		if (bt[node].first > 0 && bt[node].second > 0) {
			if ((k - 1) % (div * 2) == mod) {
				node = bt[node].first;
			}
			else {
				node = bt[node].second;
				mod += div;
			}
			div *= 2;
		}
		else if (bt[node].first > 0) {
			node = bt[node].first;
		}
		else {
			node = bt[node].second;
		}
	}

	cout << node;

	return 0;
}