#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int ti = 1; ti <= t; ++ti) {
		int n;
		cin >> n;

		int* pancakes = new int[n];

		for (int i = 0; i < n; ++i) {
			cin >> pancakes[i];
		}

		int left = 0;
		int right = n - 1;
		int max = 0;
		int pay = 0;

		for (int i = 0; i < n; ++i) {
			if (pancakes[left] < pancakes[right]) {
				if (max <= pancakes[left]) {
					max = pancakes[left];
					pay++;
				}
				left++;
			}
			else {
				if (max <= pancakes[right]) {
					max = pancakes[right];
					pay++;
				}
				right--;
			}
		}

		cout << "Case #" << ti << ": " << pay << "\n";
		
		delete[] pancakes;
	}

	return 0;
}