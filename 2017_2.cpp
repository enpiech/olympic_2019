#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("WLOOP.INP");
	int n = 0;
	inFile >> n;

	int count = 0;
	for (int line = 0; line < n ; ++line) {
		string s;
		getline(inFile, s);
			
		int l = s.length();
		
		for (int i = 1; i <= l / 2; ++i) {
			// Neu do dai cua xau con khong phai la uoc cua do dai sau cha thi khong khong the la xau lap
			if (l % i != 0) {
				break;
			}
			
			// Tim vi tri bat dau cua xau con dau tien
			if (s[0] == s[i]) {			
				// So sanh do dai cua tung cap xau con
				int k = i;
				for (int j = 0; k < l - 1; ++j, ++k) {
					if (s[k] != s[j]) {
						cout << s[k] << k << ": " << s[j] << j << endl;
						break;
					}
				}
				// Neu lap den ki tu cuoi cung cua xau cha thi do la xau con
				if (k == l - 1) {
					count++;
					break;
				}
			}
		}
	}	
	inFile.close();
	
	ofstream outFile;
	outFile.open("WLOOP.OUT");
	outFile << count;
	outFile.close();
	
	return 0;
}
