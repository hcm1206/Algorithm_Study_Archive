#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d, p, c, f, s;
	cin >> d >> p >> c >> f >> s;

	vector<tuple<int, int, int>> routes;

	for (int i = 0; i < p; ++i) {
		int ai, bi;
		cin >> ai >> bi;
		routes.push_back({ ai, bi, 0 });
	}
	for (int i = 0; i < f; ++i) {
		int ji, ki, ti;
		cin >> ji >> ki >> ti;
		routes.push_back({ ji, ki, ti });
	}

	vector<int> money(c + 1, -100000000);

	money[s] = d;
	int max = d;

	for (int i = 1; i < c; ++i) {
		for (auto r : routes) {
			if (money[get<0>(r)] > -100000000 && money[get<1>(r)] < money[get<0>(r)] + d - get<2>(r)) {
				money[get<1>(r)] = money[get<0>(r)] + d - get<2>(r);
				if (max < money[get<1>(r)]) {
					max = money[get<1>(r)];
				}
			}
		}
	}

	bool inf = false;
	for (auto r : routes) {
		if (money[get<1>(r)] < money[get<0>(r)] + d - get<2>(r)) {
			inf = true;
		}
	}

	if (inf) {
		cout << -1;
	}
	else {
		cout << max;
	}

	return 0;
}