#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> bridges(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		bridges[a].push_back({ b, c });
		bridges[b].push_back({ a, c });
	}

	int s, e;
	cin >> s >> e;

	vector<int> max(n + 1, 0);

	priority_queue<pair<int, int>> pq;

	max[s] = 1000000000;
	pq.push({ 1000000000, s });

	while (!pq.empty()) {

		int noww = pq.top().first;
		int nowp = pq.top().second;
		pq.pop();
		if (noww == max[nowp]) {
			for (auto b : bridges[nowp]) {
				int bw = noww;
				if (bw > b.second) {
					bw = b.second;
				}
				if (max[b.first] < bw) {
					max[b.first] = bw;
					pq.push({ bw, b.first });
				}
			}
		}
	}

	cout << max[e] << endl;

	return 0;
}