#include <fstream>
#include <iostream>
using namespace std;

int mag(int xA, int yA, int xB, int yB) {
	return (xB - xA) * (xB - xA) + (yB - yA) * (yB - yA);
}

bool isSquare(int xA, int yA, int xB, int yB, int xC, int yC) {
	return (xB - xA) * (xC - xB) + (yB - yA) * (yC - yB) == 0; 
}

int main()
{
	ifstream ifs;
	ifs.open("TETRAGON.INP");
	int xA, yA, xB, yB, xC, yC, xD, yD;
	ifs >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD;
	ifs.close();
	
	int AB = mag(xA, yA, xB, yB);
	int BC = mag(xB, yB, xC, yC);
	int CD = mag(xC, yC, xD, yD);
	bool square = isSquare(xA, yA, xB, yB, xC, yC);
	
	ofstream ofs;
	ofs.open("TETRAGON.OUT");
	if (AB == BC && AB == CD) {
		if (square) ofs << 1; 
		else ofs << 3;
	} else if (AB == CD) {
		if (square) ofs << 2; 
		else ofs << 4;
	} else {
		ofs << 5;
	}
	return 0;
}
