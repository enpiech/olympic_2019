#include <iostream>
#include <fstream>
using namespace std;

struct Point {
	int x, y;
};

int isRight(Point a, Point b, Point c) {
	return ((b.x - a.x) * (c.y - a.y)) < ((b.y - a.y) * (c.x - a.x));
}

int main() 
{
	ifstream ifs;
	ifs.open("ROBOT.INP");
	int n;
	ifs >> n;
	if (n < 2 || n > 10000) {
		return -1;
	}
	Point arr[n];
	for (int i = 0; i < n; ++i) {
		int x, y;
		ifs >> x >> y;
		ifs.ignore();
		arr[i].x = x;
		arr[i].y = y;		
	}
	ifs.close();

	int count = 0;
	for (int i = 2; i < n; ++ i) {
		if (isRight(arr[i - 2], arr[i - 1], arr[i])) {
			count++;
		}
	}
	
	ofstream ofs;
	ofs.open("ROBOT.OUT");
	ofs << count;
	ofs.close();
	
	
	return 0;
} 
