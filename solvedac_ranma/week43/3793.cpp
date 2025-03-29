#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		string str1, str2;
		cin >> str1;
		if (cin.eof()) {
			break;
		}
		cin >> str2;

		int size1 = static_cast<int>(str1.size());
		int size2 = static_cast<int>(str2.size());

		vector<vector<int>> v(size1 + 1, vector<int>(size2 + 1, 0));

		for (int i = 1; i <= size1; ++i) {
			for (int j = 1; j <= size2; ++j) {
				if (str1[i - 1] == str2[j - 1]) {
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				if (v[i][j] < v[i - 1][j]) {
					v[i][j] = v[i - 1][j];
				}
				if (v[i][j] < v[i][j - 1]) {
					v[i][j] = v[i][j - 1];
				}
			}
		}
		cout << v[size1][size2] << "\n";
	}

	return 0;
}