#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("DEL.INP");
	int n;
	ifs >> n;
	int arr[n];
	int le = 0, chan = 0;
	for (int i = 0; i < n; ++i) {
		ifs >> arr[i];
		if (arr[i] % 2 == 0)
		{
			chan++;
		}
		else 
		{
			le++;
		}
	}
	ifs.close();

	int c;
	if (le % 2 == 0) {
		c = (chan * (chan - 1) / 2) + (le * (le - 1) / 2);
	}
	else {
		c = chan * le;
	}
	
	cout << c;
	ofstream ofs;
	ofs.open("DEL.OUT");
	ofs << c;
	ofs.close();	
}
