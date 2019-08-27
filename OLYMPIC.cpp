#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Exp {
	int a, b;
};

int main() 
{
	ifstream ifs;
	ifs.open("OLYMPIC.INP");
	int n, c;
	ifs >> n >> c;
	ifs.ignore();
	if (n < 1 || n > pow(10, 5) || c < 0 || c > pow(10, 9)) {
		return -1;
	} 
	Exp arr[n];
	for (int i = 0; i < n; ++i) {
		int a, b;
		ifs >> a >> b;
		ifs.ignore();
		arr[i].a = a;
		arr[i].b = b;
	}
	ifs.close();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i].a <= c) {
			cout << arr[i].a << " " << arr[i].b << endl;
			c += arr[i].b;
			n--;
			swap(arr[i], arr[n]);
			i = 0;
			count++;
		}
	}
	ofstream ofs;
	ofs.open("OLYMPIC.OUT");
	ofs << count;
	ofs.close();
	
	return 0;
}
