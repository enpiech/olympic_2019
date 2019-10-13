#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs;
	ifs.open("SEQ.INP");
	int n;
	ifs >> n;
	long arr[n][n];
	long max = 0;
	for (int i = 0; i < n; ++i) {
		ifs >> arr[0][i];
		if (i > 1) {
			arr[1][i] = arr[0][i - 2] + arr[0][i - 1] + arr[0][i];
			if (arr[1][i] > max) {
				max = arr[1][i];
			}
		}
	}
	ifs.close();
	for (int i = 2; i <= n / 3; ++i) {
		if (i % 2 == 0) {
			for (int j = i * 3 - 1; j < n; j++) {
				arr[i][j] = arr[i - 1][j - 3] + arr[i - 1][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}
		else {
			for (int j = i * 3 - 1; j < n; j++) {
				arr[i][j] = arr[i - 2][j - 3] + arr[1][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
					cout << i << " " << j << endl;
				}
			}
		}

	}

	ofstream ofs;
	ofs.open("SEQ.OUT");
	cout << max;
	ofs << max;
	ofs.close();
	return 0;
}
