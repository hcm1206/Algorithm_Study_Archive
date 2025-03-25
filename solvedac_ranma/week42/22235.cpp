#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string moran_str;
	cin >> moran_str;

	string tmp_str = "";
	int now_time = 0;

	int mul = 3600;
	for (int i = 0; i < 8; ++i) {
		if (moran_str[i] == ':') {
			now_time += stoi(tmp_str) * mul;
			mul /= 60;
			tmp_str = "";
		}
		else {
			tmp_str += moran_str[i];
		}
	}
	now_time += stoi(tmp_str);
	tmp_str = "";

	int g_station = 225;

	int n;
	cin >> n;

	vector<int> op_time = { 0, 2440, 1160, 1980, 2080, 2020 };

	vector<int> idx_to_station = { 210, 225, 233, 246, 258, 272 };
	map<int, int> station_to_idx;
	station_to_idx[210] = 0;
	station_to_idx[225] = 1;
	station_to_idx[233] = 2;
	station_to_idx[246] = 3;
	station_to_idx[258] = 4;
	station_to_idx[272] = 5;

	vector<vector<pair<int, int>>> timetable(6);

	for (int i = 0; i < n; ++i) {
		string ds, ts, dt;
		cin >> ds >> ts >> dt;

		string ds_str = "";
		for (int j = 1; j < 4; ++j) {
			ds_str += ds[j];
		}
		int d_station = stoi(ds_str);

		string ts_str = "";
		for (int j = 1; j < 4; ++j) {
			ts_str += ts[j];
		}
		int t_station = stoi(ts_str);

		int train_time = 0;
		mul = 3600;

		for (int j = 0; j < 2; ++j) {
			tmp_str += dt[3 * j];
			tmp_str += dt[3 * j + 1];
			train_time += stoi(tmp_str) * mul;
			mul /= 60;
			tmp_str = "";
		}

		int idx = station_to_idx[d_station];
		while (idx < station_to_idx[t_station]) {
			timetable[idx].push_back({ train_time, station_to_idx[t_station] });
			train_time += op_time[++idx] + 20;
		}
	}

	for (int i = 0; i < 6; ++i) {
		sort(timetable[i].begin(), timetable[i].end());
	}

	int now_station = 1;

	while (now_station < 5) {
		bool onboard = false;
		for (auto train : timetable[now_station]) {
			if (now_time < train.first) {
				now_time = train.first;
				while (now_station < train.second) {
					now_time += op_time[++now_station];
					now_time += 20;
				}
				now_time -= 40;
				onboard = true;
				break;
			}
		}
		if (!onboard) {
			break;
		}
	}

	if (now_station == 5 && now_time < 86400) {
		if (now_time / 3600 < 10) {
			cout << 0;
		}
		cout << now_time / 3600;
		cout << ":";
		if (now_time % 3600 / 60 < 10) {
			cout << 0;
		}
		cout << now_time % 3600 / 60;
		cout << ":";
		if (now_time % 60 < 10) {
			cout << 0;
		}
		cout << now_time % 60;
	}
	else {
		cout << -1;
	}

	return 0;
}