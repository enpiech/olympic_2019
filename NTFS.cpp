#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("NTFS.INP");
	int n;
	ifs >> n;
	ifs.close();
	
	if (n > pow(10, 9)) {
		cout << "Max value is 10^9";
		return -1;
	}	
	
	int kb = n / 4096;
	if (kb % 4096 > 0) {
		++kb;
	}
	
	ofstream ofs;
	ofs.open("NTFS.OUT");
	ofs << kb;
	ofs.close();
	
	return 0;
}
