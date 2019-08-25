#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Exp {
	unsigned int a, b, c, d;
};

int main()
{
	ifstream ifs;
	ifs.open("SVOI.INP");
	int n, t, p;
	ifs >> n >> t >> p;
	ifs.ignore();
	if (n <= 0 || n > 1000) {
		return -1;
	}
	if (t < 0 || t > pow(10, 6) || p < 0 || p > pow(10, 6)) {
		return -1;
	}
	
	Exp arr[n];
	for (int i = 0; i < n; ++i) {
		ifs >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
		ifs.ignore();
	}
		
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i].a <= t && arr[i].b <= p) {
			t += arr[i].c;
			p += arr[i].d;
			n--;
			swap(arr[i], arr[n]);
			i = -1;
			
			count++;
		}
	}
	
	ofstream ofs;
	ofs.open("SVOI.OUT");
	ofs << count;
	ofs.close();
	
	return 0;
}
