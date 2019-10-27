#include <iostream>
#include <fstream>
using namespace std;

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "
        << max_so_far << endl; 
    cout << "Starting index "<< start 
        << endl << "Ending index "<< end << endl; 
}

int main() {
	ifstream ifs;
	ifs.open("SEQ.INP");
	int n;
	ifs >> n;
	int arr[n];
	
	for (int i = 0; i < n; ++i) {
		ifs >> arr[i];
//		if (i > 1) {
//			arr[1][i] = arr[0][i - 2] + arr[0][i - 1] + arr[0][i];
//			if (arr[1][i] > max) {
//				max = arr[1][i];
//			}
//		}
	}
	int max = maxSubArraySum(arr, n);
////	arr[1][2] = arr[0][0] + arr[0][1] + arr[0][2];
//	for (int i = 3; i <= n; i+=3) {
//		int t = 0;
////		cout << i << ":";
//		for (int j = 0; j < i; ++j) {
//			t += arr[j];
//		}
//		if (t > max) {
//			max = t;
//		}
//		for (int j = i; j < n; ++j) {
//			t = t - arr[j - i] + arr[j];
////			cout << t << "-";
//			if (t > max) {
//				max = t;
//			}
//		}
////		cout << endl;
//	}
//	for (int i = 3; i < n; ++i) {
//		arr[1][i] = arr[1][i - 1] - arr[0][i - 3] + arr[0][i];
//		if (arr[1][i] > max) {
//			max = arr[1][i];
//		}
//	}
	
	ifs.close();
//	for (int i = 2; i <= n / 3; ++i) {
//		if (i % 2 == 0) {
//			for (int j = i * 3 - 1; j < n; j++) {
//				arr[i][j] = arr[i - 1][j - 3] + arr[i - 1][j];
//				if (arr[i][j] > max) {
//					max = arr[i][j];
//				}
//			}
//		}
//		else {
//			for (int j = i * 3 - 1; j < n; j++) {
//				arr[i][j] = arr[i - 2][j - 3] + arr[1][j];
//				if (arr[i][j] > max) {
//					max = arr[i][j];
//					cout << i << " " << j << endl;
//				}
//			}
//		}
//
//	}

	ofstream ofs;
	ofs.open("SEQ.OUT");
	ofs << max;
	ofs.close();
	system("pause");
	return 0;
}
