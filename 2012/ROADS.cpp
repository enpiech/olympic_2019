#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("ROADS.INP");
	int n, m, k;
	ifs >> n >> m >> k;
	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < k; ++i) {
		string c;
		ifs >> c;
		int so;
		ifs >> so;
		cout << c << " " << so << endl;
		if (c == "H") {
			for (int j = 0; j < m; ++j) {
				if (so >= 0) arr[so - 1][j]++;
				if (so < m) arr[so][j]++;
			}
		}
		else if (c == "V"){
			for (int j = 0; j < m; ++j) {
				if (so >= 0) arr[j][so - 1]++;
				if (so < n) arr[j][so]++;
			}
		}
	}
	int s[5] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << " ";
			s[arr[i][j]]++;
		}
		cout << endl;
	}
	ofstream ofs;
	ofs.open("ROADS.OUT");
	for (int i = 0; i < 5; ++i) {
		ofs << s[i] << " ";
	}
	ofs.close();
}
