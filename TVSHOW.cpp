#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Prog {
	int s;
	int t;
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
	clock_t tStart = clock();
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
	
	int r = 0;
	int l = 0; 
	qsort(arr, n, sizeof(Prog), compare);
	for (int i = 0; i < n - 1; ++i) {
//		int ci = 1;
//		while (arr[i].s == arr[i + 1].s) {
//			ci++;
//			i++;
//		}
//		if (ci > 1) {
//			r += ci / 2 * (ci - 1);
//		}	

		for (int j = i + 1; j < n; ++j) {
			l++; 
			if (arr[i].t > arr[j].s) {
				++r;
			} else {
				break;
			}
		} 

//		int match = 0;
//		for (int j = i + 1; j < n; ++j) {
//			if (arr[i].t <= arr[j].s) {
//				match++;
//			}
//		} 
//		r += n - 1 - i - match;	
	}

//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			
//			if (arr[i].s >= arr[j].s && arr[i].s <= arr[j].t || arr[j].s >= arr[i].s && arr[j].s <= arr[i].t) {
//				r++;
//			}
//		}
//	}
	
	ofstream ofs;
	ofs.open("TVSHOW.OUT");
	ofs << r;
	ofs.close();
	cout << l;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
