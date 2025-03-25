#include <iostream>
#include <vector>
#include <map>
using namespace std;

void find_route(const vector<map<int, int>>& routes, int* money, bool* visited, int d, int now, int& max, bool& inf) {
	for (auto r : routes[now]) {
		if (visited[r.first]) {
			if (money[now] - r.second + d > money[r.first]) {
				inf = true;
			}
		}
		else {
			visited[r.first] = true;
			money[r.first] += money[now] - r.second + d;
			if (max < money[r.first]) {
				max = money[r.first];
			}
			find_route(routes, money, visited, d, r.first, max, inf);
			money[r.first] -= money[now] - r.second + d;
			visited[r.first] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d, p, c, f, s;
	cin >> d >> p >> c >> f >> s;

	int* money = new int[c + 1] {0};
	bool* visited = new bool[c + 1] {false};

	vector<map<int, int>> routes(c + 1);

	for (int i = 0; i < p; ++i) {
		int ai, bi;
		cin >> ai >> bi;
		routes[ai][bi] = 0;
	}
	for (int i = 0; i < f; ++i) {
		int ji, ki, ti;
		cin >> ji >> ki >> ti;
		if (routes[ji].find(ki) == routes[ji].end() || routes[ji][ki] > ti) {
			routes[ji][ki] = ti;
		}
	}

	visited[s] = true;
	money[s] = d;
	int max = d;
	bool inf = false;

	find_route(routes, money, visited, d, s, max, inf);

	if (inf) {
		cout << -1;
	}
	else {
		cout << max;
	}

	delete[] money;
	delete[] visited;

	return 0;
}