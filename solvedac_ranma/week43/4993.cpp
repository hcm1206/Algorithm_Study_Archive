#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		int w, h;
		cin >> w >> h;

		if ((w | h) == 0) {
			break;
		}

		int sw, sh;

		bool** tiles = new bool* [h];
		
		for (int i = 0; i < h; ++i) {
			tiles[i] = new bool[w] {0};
			string str;
			cin >> str;
			for (int j = 0; j < w; ++j) {
				if (str[j] == '#') {
					tiles[i][j] = 0;
				}
				else {
					tiles[i][j] = 1;
					if (str[j] == '@') {
						sh = i;
						sw = j;
					}
				}
			}	
		}

		queue<pair<int, int>> q;

		q.push({ sh, sw });
		tiles[sh][sw] = 0;

		int cnt = 1;

		while (!q.empty()) {
			int nowh = q.front().first;
			int noww = q.front().second;
			q.pop();

			if (nowh > 0 && tiles[nowh - 1][noww]) {
				cnt++;
				tiles[nowh - 1][noww] = 0;
				q.push({ nowh - 1, noww });
			}
			if (noww > 0 && tiles[nowh][noww - 1]) {
				cnt++;
				tiles[nowh][noww - 1] = 0;
				q.push({ nowh, noww - 1 });
			}
			if (nowh < h - 1 && tiles[nowh + 1][noww]) {
				cnt++;
				tiles[nowh + 1][noww] = 0;
				q.push({ nowh + 1, noww });
			}
			if (noww < w - 1 && tiles[nowh][noww + 1]) {
				cnt++;
				tiles[nowh][noww + 1] = 0;
				q.push({ nowh, noww + 1 });
			}
		}

		cout << cnt << "\n";

		for (int i = 0; i < h; ++i) {
			delete[] tiles[i];
		}
		delete[] tiles;
	}

	return 0;
}