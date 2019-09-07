#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("SP.INP");
	int m, n, t;
	ifs >> m >> n >>t;
	ifs.close();
	
	ofstream ofs;
	ofs.open("SP.OUT");
	int r = (n / (m + 1)) * m;
	int o = n % (m + 1);
	r += o;
	r *= t;
	ofs << r;
	ofs.close();
	
}
