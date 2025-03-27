#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	int* arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int l = 0;
	int r = n - 1;

	int cnt = 0;

	while (l < r) {
		if (arr[l] + arr[r] < s) {
			l++;
		}
		else if (arr[l] + arr[r] > s) {
			r--;
		}
		else {
			cnt++;
			l++;
		}
	}
	cout << cnt;

	delete[] arr;

	return 0;
}