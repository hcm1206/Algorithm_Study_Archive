#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();

	for (int ni = 0; ni < n; ++ni) {
		string str;
		getline(cin, str);

		vector<long long> v;
		string num = "";

		for (int i = 0; i < static_cast<int>(str.size()); ++i) {
			if (str[i] == ' ') {
				v.push_back(stol(num));
				num = "";
			}
			else {
				num += str[i];
			}
		}
		v.push_back(stoi(num));

		long long total = 0;

		for (int i = 1; i < static_cast<int>(v.size()) - 1; ++i) {
			long long lmax = -1000000001;
			long long rmax = -1000000001;
			for (int j = 0; j < i; ++j) {
				if (lmax < v[j]) {
					lmax = v[j];
				}
			}
			for (int j = i + 1; j < static_cast<int>(v.size()); ++j) {
				if (rmax < v[j]) {
					rmax = v[j];
				}
			}
			if (lmax >= v[i] && rmax >= v[i]) {
				long long height = lmax;
				if (height > rmax) {
					height = rmax;
				}
				total += height - v[i];
			}
		}
		cout << total << "\n";
	}

	return 0;
}