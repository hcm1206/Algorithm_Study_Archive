#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int* rows = new int[n];
	for (int i = 0; i < n; ++i) {
		rows[i] = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		int temp = rows[i];
		for (int j = 1; j <= num; ++j) {
			rows[i - j + 1] = rows[i - j];
		}
		rows[i - num] = temp;
	}
	for (int i = 0; i < n; ++i) {
		cout << rows[i] << " ";
	}

	return 0;
}