#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int ti = 1; ti <= t; ++ti) {
		string num;
		cin >> num;

		int idx = static_cast<int>(num.size()) - 1;
		int last = num[idx];

		vector<int> poped;

		while (idx >= 0 && num[idx] >= last) {
			poped.push_back(num[idx] - '0');
			last = num[idx--];
		}


		cout << "Case #" << ti << ": ";

		if (idx >= 0) {
			poped.push_back(num[idx] - '0');
			int val = num[idx] - '0';
			sort(poped.begin(), poped.end());

			int second = val;
			for (auto p : poped) {
				if (p > val) {
					second = p;
					break;
				}
			}

			for (int i = 0; i < idx; ++i) {
				cout << num[i];
			}
			cout << second;

			bool used = false;
			for (auto p : poped) {
				if (p == second) {
					if (used) {
						cout << p;
					}
					used = true;
				}
				else {
					cout << p;
				}
			}
		}
		else {
			sort(poped.begin(), poped.end());
			if (poped[0]) {
				cout << poped[0] << 0;
				for (int i = 1; i < static_cast<int>(num.size()); ++i) {
					cout << poped[i];
				}
			}
			else {
				int v = 0;
				for (auto p : poped) {
					if (v < p) {
						v = p;
						break;
					}
				}
				cout << v << 0;
				bool used = false;
				for (auto p : poped) {
					if (p == v) {
						if (used) {
							cout << p;
						}
						used = true;
					}
					else {
						cout << p;
					}
				}
			}
		}

		cout << "\n";
	}
	return 0;
}