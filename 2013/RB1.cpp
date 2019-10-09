#include <fstream>
using namespace std;

int main() {
	ifstream docFile;
	docFile.open("ROBOT.INP");

	int T;
	docFile >> T;

	int n, a, b, k;
	int count;
	int pos;
	ofstream ghiFile;
	ghiFile.open("ROBOT.OUT");
	for (int i = 0; i < T; i++) {
		docFile >> n >> a >> b >> k;
		count = 1;
		pos = 1;
		while (pos + a <= n && k--) {
			//ghiFile << pos;
			pos += a;
			count++;
		}
		//ghiFile << endl << k;
		while (pos - b > 1 && k--) {
			//ghiFile << pos;
			pos -= b;
			if ((pos - 1) % a != 0) count++;
		}
		ghiFile << n - count;
		if (i != T - 1) ghiFile << endl;
	}
	ghiFile.close();

	return 0;
}
