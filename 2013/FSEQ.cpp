	#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("FSEQ.INP");
	int n;
	ifs >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		ifs >> arr[i];
//		cout << arr[i] << " ";
	}
	ifs.close();
	
//	int minI = 0;
//	int maxf = 0;
//	bool isf = true;
//	for (int i = 2; i < n; ++i){
//		if (arr[i] == arr[i - 1] + arr[i - 2]) {
//			isf = true;
//		} else {
//			if (isf) {
//				int l = i - minI;
//				if (l > maxf && l > 2) {
//					maxf = l;
//					
//				}
//			}
//			isf = false;
//			minI = i - 1;
//		}
//		if (minI == 0 && i == n - 1 && ifs) {
//			maxf = n;
//		}
////		if (i == n - 1) {
////			if (!ifs && minI <= n - 3) {
////				int l = n - minI;
////				if (l > maxf) {
////					maxf = l;
////				}
////			}
////		}
//	}
	int count = 0;
	int maxf = 0;
	for (int i = 2; i < n; i++) {
		if (arr[i] == arr[i - 1] + arr[i - 2]) {
			count++;
		}
		else {
			if (count > maxf) {
				maxf = count;
			}
			count = 0;
		}
	}
	if (count > maxf) {
		maxf = count;
	}	
	
	ofstream ofs;
	ofs.open("FSEQ.OUT");
	ofs << maxf + 2;
	ofs.close();
	
	return 0;
}
