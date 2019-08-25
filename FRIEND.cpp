#include <iostream>
#include <array>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main() 
{
	ifstream ifs;
	ifs.open("FRIEND.INP");
	int n, b;
	ifs >> n >> b;
	ifs.ignore();
	
	if (n < 2 || n > pow(10, 5) || abs(b) > pow(10, 9)) {
		return -1;
	}
	
	int s[n];
	for (int i = 0 ; i < n; ++i) {
		ifs >> s[i];
		
//		if (s[i] > pow(2, 15)) {
//			return -1;
//		}
	}
	ifs.close();
	
	qsort(s, n, sizeof(int), compare);
	
	ofstream ofs;
	ofs.open("FRIEND.OUT");
	
	int count = 0;
	int li = 0;
	int lj = 0;
	for (int i = 0; i < n; ++i) {
		int ci = 1;
		while (s[i + 1] == s[i]) {
			ci++;
			i++;
			li++;
		}
		
		int cj = 0;
		for (int j = i + 1; j < n; ++j) {
			lj++;
			int t = s[i] + s[j];
			if (t == b) {
				cj++;
			} else if (t > b) {
				n = j;
				break;
			}
		}
		
		if (b == s[i] * 2) {
			count += (ci * (ci - 1) / 2);
			break;
		}
		
		count += (ci * cj);
	}
	ofs << count << endl << li << endl << lj;
	ofs.close();
	return 0;
}
