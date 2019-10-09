#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs;
	ifs.open("ROBOT.INP");
	ofstream ofs;
	int t;
	ifs >> t;
	int n, a, b, k;
	
	ofs.open("ROBOT.OUT");	
	for (int i = 0; i < t; ++i) {
		ifs >> n >> a >> b >> k;
	
		if (a == b && a > n / 2) {
			ofs << 1 << endl;
			continue;
		} else if (a + b <= n) {
			int arr[n + 1];
			arr[1] = a;
		
			for (int j = 2; j <= n; ++j) {
				arr[j] = 0;
			}
			int v = 1;
			for (k; k >= 0; --k) {
				if (a / 2 != b) {
					while (v + a <= n && arr[v + a] != a && arr[v + a] != (a + b)) {
						v += a;
						if (arr[v] == b) {
							arr[v] = a + b;
						} else {
							arr[v] = a;
						}
						--k;
					}
				}
				
				if (a != b / 2) {
					while (v - b > 1 && arr[v - b] != b && arr[v - b] != (a + b)) {
						v -= b;
						if (arr[v] == a) {
							arr[v] = a + b;
						} else {
							arr[v] = b;
						}
						--k;
					}
				}
			}
			int c = 0;
			for (int j = 1; j <= n; ++j) {
				if (arr[j] != 0) {
					++c;
				}
			}
			ofs << n - c << endl;
			cout << n - c << endl;
		}	
	}
	
	
	ifs.close();
	ofs.close();
}
