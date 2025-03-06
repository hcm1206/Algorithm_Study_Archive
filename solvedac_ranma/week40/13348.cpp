#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int k;
	cin >> k;

	map<string, set<int>> cards;
	set<string> faceups;
	int facedown = n;

	for (int i = 0; i < k; ++i) {
		int c1, c2;
		string p1, p2;
		cin >> c1 >> c2 >> p1 >> p2;
		cards[p1].insert(c1);
		cards[p2].insert(c2);
		if (p1 == p2) {
			faceups.insert(p1);
			n -= 2;
		}
	}

	int score = 0;
	int revealed = 0;

	for (auto card : cards) {
		if (card.second.size() >= 2 && faceups.find(card.first) == faceups.end()) {
			score++;
			n -= 2;
		}
		else if (card.second.size() == 1) {
			revealed++;
		}
	}

	if (n == 2) {
		score++;
	}
	else if (n <= revealed * 2) {
		score += revealed;
	}

	cout << score;

	return 0;
}