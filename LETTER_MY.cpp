#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	ifstream ifs;
	ifs.open("LETTER.INP");
	string s;
	getline(ifs, s);
	int k;
	ifs >> k;
	ifs.close();
	
	int l = s.length();
	
	string r = "";
	for (int i = k - 1; i >= 0; --i) {
		r += s[i];
	}
	for (int i = l - 1; i >= k; --i) {
		r += s[i];
	}
	
	ofstream ofs;
	ofs.open("LETTER.OUT");
	ofs << r;
	ofs.close();
	
	return 0;
}
