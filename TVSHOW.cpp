#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Prog {
	int s, t;
};

int compare(const void * a, const void * b) {
	Prog *a1 = (Prog*)a;
	Prog *b1 = (Prog*)b;
	if (a1->s > b1->s) {
		return 1;
	} else if (a1->s < b1->s) {
		return -1;
	} else {
		return a1->t - b1->t;
	}
}

int main()
{
	ifstream ifs;
	ifs.open("TVSHOW.INP");
	int n;
	ifs >> n;
	ifs.ignore();
	if (n < 1 || n > 50000) {
		return -1;
	}
	Prog arr[n];
	for (int i = 0; i < n; ++i) {
		int s, t;
		ifs >> s >> t;
		ifs.ignore();
		arr[i].s = s;
		arr[i].t = t;
	}
	ifs.close();
	
	qsort(arr, n, sizeof(Prog), compare);
	
	int r = 0;
	for (int i = 0; i < n; ++i) {
//		int ci = 1;
//		while (arr[i].s == arr[i + 1].s) {
//			ci++;
//			i++;
//		}
//		if (ci > 1) {
//			r += (ci * (ci - 1) / 2);
//		}
		int match = 0;
		for (int j = i + 1; j < n; ++j) {
			if (arr[i].t <= arr[j].s) {
				match++;
			}
		} 
		cout << match << endl;
		r += n - 1 - i - match;
	}
	
	ofstream ofs;
	ofs.open("TVSHOW.OUT");
	ofs << r;
	ofs.close();
	cout << r;
	
	return 0;
}
