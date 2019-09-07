#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int compare(const void * a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	ifstream ifs;
	ifs.open("DEL.INP");
	int n;
	ifs >> n;
	int arr[n];
	int t = 0;
	for (int i = 0; i < n; ++i) {
		ifs >> arr[i];
		t += arr[i];
	}
	ifs.close();
	qsort(arr, n, sizeof(int), compare);

	int c = 0;
	int s = 0;
	if (t % 2 != 0) s = 1;
	int li;
	for (int i = 0; i < n - 1; ++i) {
		int	ci = 1;
			while (arr[i] == arr[i + 1]) {
				++ci;
				++i;
			}
		
		int cj = 0;
		for (int j = i + 1; j < n; ++j) {
			li++;
			int cs = arr[i]  + arr[j];
			if ((t - cs) % 2 == 0) {
				cout << arr[i] << " " << arr[j] << " " << cs << endl;
				++cj;
			}
		}
		
		c += (ci * cj);
	}
	cout << c << " " << li;
	ofstream ofs;
	ofs.open("DEL.OUT");
	ofs << c;
	ofs.close();
}
