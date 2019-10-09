#include <iostream>
#include <fstream>
using namespace std;

int64_t totalDigit(int64_t num);

int main()
{
	ifstream ifs;
	ifs.open("SNUM.INP");
	int64_t n;
	ifs >> n;
	ifs.close();
		
	ofstream ofs;
	ofs.open("SNUM.OUT");
	if ((n % totalDigit(n)) == 0) {
		ofs << 1;	
	} else {
		ofs << 0;
	}
	ofs.close();
	
	
	return 0;
}

int64_t totalDigit(int64_t num) 
{
	int total = 0;
	while (num > 0) {
		total += num % 10;
		num /= 10;
	}
	return total;
}
