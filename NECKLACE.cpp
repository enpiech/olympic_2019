#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("NECKLACE.INP");
	string s;
	ifs >> s;
	ifs.close();
	
	int l = s.length();
	int min = 0;
	for (int i = 1; i < l; ++i) {
		if (s[i] < s[min]) {
			min = i;
		}
	}
	ofstream ofs;
	ofs.open("NECKLACE.OUT");
	for (int i = min + 1; i < l; ++i) {
		if (s[i] == s[min]) {
			int jl = 0;
			while (jl < l) {
				int j1 = min + jl;
				int j2 = i + jl;
				if (j1 >= l) {
					j1 = j1 - l;
				}
				if (j2 >= l) {
					j2 = j2 - l;
				}
				if (s[j1] > s[j2]) {
					min = i;
					break;
				} else if (s[j1] < s[j2]) {
					break;
				}
				jl++;
			}
		}
	}
	
	int i = min;
	int il = 0;
	while (il < l) {
		ofs << s[i];
		if (i == l - 1) {
			i = 0;
		} else {
			i++;
		}
		il++;
	}
	ofs.close();
	
	return 0;	
}
