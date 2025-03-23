#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		string str;
		cin >> str;

		string num = "";
		int idx = 0;
		int size = static_cast<int>(str.size());

		bool iscon = true;
		bool plus = true;

		int coef[2] = { 0, 0 };
		int cons[2] = { 0, 0 };
		int eq = 0;

		while (idx < size) {
			if ('0' <= str[idx] && str[idx] <= '9') {
				num += str[idx];
			}
			else if (str[idx] == 'x') {
				iscon = false;
			}
			else {
				if (iscon) {
					if (num != "") {
						if (plus) {
							cons[eq] += stoi(num);
						}
						else {
							cons[eq] -= stoi(num);
						}
					}
				}
				else {
					if (num == "") {
						if (plus) {
							coef[eq]++;
						}
						else {
							coef[eq]--;
						}
					}
					else {
						if (plus) {
							coef[eq] += stoi(num);
						}
						else {
							coef[eq] -= stoi(num);
						}
					}
				}
				if (str[idx] == '+') {
					plus = true;
				}
				else if (str[idx] == '-') {
					plus = false;
				}
				else if (str[idx] == '=') {
					plus = true;
					eq++;
				}
				iscon = true;
				num = "";
			}
			idx++;
		}
		if (iscon) {
			if (num != "") {
				if (plus) {
					cons[eq] += stoi(num);
				}
				else {
					cons[eq] -= stoi(num);
				}
			}
		}
		else {
			if (num == "") {
				if (plus) {
					coef[eq]++;
				}
				else {
					coef[eq]--;
				}
			}
			else {
				if (plus) {
					coef[eq] += stoi(num);
				}
				else {
					coef[eq] -= stoi(num);
				}
			}
		}

		int coefficient = coef[0] - coef[1];
		int constant = cons[1] - cons[0];

		if (!coefficient && !constant) {
			cout << "IDENTITY\n";
		}
		else if (!coefficient) {
			cout << "IMPOSSIBLE\n";
		}
		else if (!constant) {
			cout << 0 << "\n";
		}
		else {
			int result = constant / coefficient;
			if (constant / coefficient < 0 && constant % coefficient) {
				result--;
			}
			cout << result << "\n";
		}
	}

	return 0;
}