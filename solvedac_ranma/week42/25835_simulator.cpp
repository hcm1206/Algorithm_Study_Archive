#include <iostream>
#include <windows.h>
using namespace std;

void print_tower(int** grid, int k, int n, int e) {
	system("cls");
	cout << "     |" << endl;
	for (int i = 0; i < k; ++i) {
		if (i + 1 == e) {
			cout << " * ";
		}
		else {
			cout << "   ";
		}
		cout << i + 1 << " | ";
		for (int j = 1; j <= grid[i][0]; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl << "     |" << endl;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, s, e;
	cin >> k >> s >> e;

	int n = k * (k - 1) / 2;

	int** grid = new int* [k];
	for (int i = 0; i < k; ++i) {
		grid[i] = new int[n + 1] {0};
	}
	grid[s - 1][0] = n;
	for (int i = 0; i < n; ++i) {
		grid[s - 1][i + 1] = n - i;
	}
	
	bool complete = false;
	int ci = 1;

	while (ci <= 2 * (k - 1) * (k - 1)) {

		print_tower(grid, k, n, e);
		cout << "============================" << endl;
		cout << "tries : " << ci << endl;
		cout << "input number of tower to take disk and put disk (ex: 1 2) : " << endl;
		int from, to;
		try {
			cin >> from >> to;
		}
		catch(const char* exception)  {
			cout << "Invalid input. try again." << endl;
			Sleep(1500);
			continue;
		}
		if (from <= 0 || n < from || to <= 0 || n < to) {
			cout << "Invalid disk number." << endl;
			Sleep(1500);
			continue;
		}
		else if (!grid[from - 1][0]) {
			cout << "No disk at tower #" << from << endl;
			Sleep(1500);
			continue;
		}
		else if (grid[to - 1][0] && grid[from - 1][grid[from - 1][0]] > grid[to - 1][grid[to - 1][0]]) {
			cout << "Selected disk is too big for tower #" << to << endl;
			Sleep(1500);
			continue;
		}
		else {
			grid[to - 1][++grid[to - 1][0]] = grid[from - 1][grid[from - 1][0]];
			grid[from - 1][grid[from - 1][0]--] = 0;
		}
		if (grid[e - 1][0] >= n) {
			complete = true;
			break;
		}
		ci++;
	}
	
	print_tower(grid, k, n, e);
	if (complete) {
		cout << "Task Success!" << endl;
	}
	else {
		cout << "Your try count is over. Failed!" << endl;
	}

	return 0;
}