#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int max = 0;
	string seminar = "";

	for (int i = 0; i < 7; ++i) {
		string s;
		int num;
		cin >> s >> num;

		if (num > max) {
			max = num;
			seminar = s;
		}
	}

	cout << seminar;

	return 0;
}