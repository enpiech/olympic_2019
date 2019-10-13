#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ifstream ifs;
	ifs.open("SUM.INP");
	double a, b;
	ifs >> a >> b;
	ifs.close();
	
	unsigned long long a1 = ceil(a);
	unsigned long long b1 = floor(b);
	cout << a1 << " " << b1;
//	uint64_t t = (b1 - a1 + 1) * (b1 + a1) / 2;
	unsigned long long t1 = (b1 - a1 + 1) * (b1 + a1) / 2;
	uint64_t x =1000000000000000000;

	ofstream ofs;
	ofs.open("SUM.OUT");
	ofs << t1 << endl << x;
	ofs.close();
	
	return 0;
}
