#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("CLOCK.INP");
	int h, p, s;
	ifs >> h >> p >> s;
	ifs.close();
	
	s++;
	if (s > 59) {
		s = 0;
		p++;
	}
	if (p > 59) {
		p = 0;
		h++;
	}
	if (h > 23) {
		h = 0;
	}
	
	ofstream ofs;
	ofs.open("CLOCK.OUT");
	ofs << h << " " << p << " " << s;
	ofs.close();
	return 0;
}
