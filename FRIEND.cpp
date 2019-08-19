#include <iostream>
#include <fstream>
#include <array>
#include "math.h"
#include <map>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("FRIEND.INP");
	int n, b;
	ifs >> n >> b;
	ifs.ignore();
	long long int s[n];
	for (int i = 0; i < n; ++i) {
		ifs >> s[i];
	}
	ifs.close();
		
	map <long long int, int> cnt;

	for (int i = 0; i < n; ++i) {
		cnt[s[i]]++;
	}
	
	int count = 0;
	for (auto it: cnt) {
		int req = b - it.first;
		cout << req << ":" << cnt.count(req) << endl;
		if (cnt.count(req) > 0) {
			cout << it.first << ":" << it.second << " * " << cnt[req] << endl;
			count += it.second * cnt[req];
			cnt.erase(req);
		}
	}
	cout << count;
	return 0;
}
