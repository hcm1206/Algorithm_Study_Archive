#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, int> moleculars;
	while (1) {
		string m;
		cin >> m;
		if (m == "END_OF_FIRST_PART") {
			break;
		}
		int w;
		cin >> w;
		moleculars[m] = w;
	}

	while (1) {
		string mf;
		cin >> mf;

		if (mf == "0") {
			break;
		}

		int sum = 0;
		int idx = 0;

		stack<int> st;
		int size = static_cast<int>(mf.size());
		bool valid = true;

		while (idx < size) {
			if (mf[idx] == '(') {
				st.push(sum);
				sum = 0;
				idx++;
			}
			else if (mf[idx] == ')') {
				string mul = "";
				idx++;
				while (idx < size && '0' <= mf[idx] && mf[idx] <= '9') {
					mul += mf[idx++];
				}
				if (mul != "") {
					sum *= stoi(mul);
				}
				sum += st.top();
				st.pop();
			}
			else if ('A' <= mf[idx] && mf[idx] <= 'Z') {
				string mc = "";
				mc += mf[idx++];
				if (idx < size && 'a' <= mf[idx] && mf[idx] <= 'z') {
					mc += mf[idx++];
				}
				if (moleculars.find(mc) == moleculars.end()) {
					valid = false;
					break;
				}

				int mw = moleculars[mc];
				string mul = "";
				while (idx < size && '0' <= mf[idx] && mf[idx] <= '9') {
					mul += mf[idx++];
				}
				if (mul != "") {
					mw *= stoi(mul);
				}

				sum += mw;
			}
		}

		if (valid) {
			cout << sum << "\n";
		}
		else {
			cout << "UNKNOWN\n";
		}
	}
	return 0;
}