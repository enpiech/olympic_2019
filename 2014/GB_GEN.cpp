#include <fstream>
using namespace std;

int main() {
	ofstream ofi;
	ofi.open("FAIRPLAY.INP");
	ofi << 10000 << endl;
	for (int i = 0; i < 10000; ++i) {
		ofi << 1 << " ";
	}
	ofi << endl;
	for (int i = 0; i < 10000; ++i) {
		ofi << 2 << " ";
	}
	ofi.close();
}
