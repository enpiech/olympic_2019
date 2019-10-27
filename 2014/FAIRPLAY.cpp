#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int compare(const void * a, const void * b) {
	return (*(int*)b - * (int*)a);
}

int main() {
	ifstream ifs;
	ifs.open("FAIRPLAY.INP");
	int n;
	ifs >> n;
	int *arrA = new int[n];
	int *arrB = new int[n];
	for (int i = 0; i < n; ++i) {
		ifs >> arrA[i];
	} 
	for (int i = 0; i < n; ++i) {
		ifs >> arrB[i];
	}
	ifs.close();
	
	qsort(arrA, n, sizeof(int), compare);
	qsort(arrB, n, sizeof(int), compare);
	int maxA = arrA[0];
	int maxB = arrB[0];
	int min = 0;
	int p = 0;
	int cA = 0;
	int cB = 0;
	
	while (cA <= n - 1) {
		if (maxA >= maxB) {
			cA++;
			maxA = arrA[cA];
			min++;
		} else {
			cA++;
			cB++;
			maxA = arrA[cA];
			maxB = arrB[cB];
			p++;
		}
	}

	ofstream ofs;
	ofs.open("FAIRPLAY.OUT");
	ofs << p;
	ofs.close();
	delete(arrA);
	delete(arrB);
}
