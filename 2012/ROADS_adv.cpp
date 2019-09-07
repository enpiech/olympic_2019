#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("ROADS.INP");
	int n, m, k;
	ifs >> n >> m >> k;
	int h[m + 1] = {0}, v[n + 1] = {0};
	for (int i = 0; i < k; ++i) {
		string c;
		ifs >> c;
		int num;
		ifs >> num;
		if (c == "H") {
			h[num] = 1;
		}
		else if (c == "V") {
			v[num] = 1;
		}
	}
	
	int v0 = 0, v1 = 0, v2 = 0, h0 = 0, h1 = 0, h2 = 0;
	for (int i = 1; i <= n; ++i) {
		int sub = h[i] - h[i - 1];
		
		if (sub == 0) {
			++h2;
		} else if (sub == 1 || sub == -1) {
			++h1;
		} else {
			++h0;
		}
	}
	for (int i = 1; i <= m; ++i) {	
		int sub = v[i] - v[i - 1];
		
		if (sub == 0) {
			++v2;
		} else if (sub == 1 || sub == -1) {
			++v1;
		} else {
			++v0;
		}
	}
	
	int a0 = h0 * v0;
	int a1 = h0 * v1 + h1 * v0;
	int a2 = h1 * v1 + h0 * v2 + h2 * v0;
	int a3 = h2 * v1 + h1 * v2;
	int a4 = h2 * v2;
	ofstream ofs;
	ofs.open("ROADS.OUT");
	ofs << a0 << " " << a1 << " " << a2 << " " << a3 << " " << a4;
	ofs.close();
	return 0;
}
