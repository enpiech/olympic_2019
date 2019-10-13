#include <fstream>
#include <iostream>
using namespace std;

int main() {
	int n = 300000;
	ofstream ofs;
	ofs.open("SEQ.INP");
	ofs << n << endl;
	for (int i = 0; i < n; ++i) {
		ofs << 1 << " ";
	}
	ofs.close();
	return 0;
}
