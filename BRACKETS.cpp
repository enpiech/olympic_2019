#include <iostream>
#include <fstream>
#include <stack>
#include <map>
using namespace std;

bool isRightBracket(string s) {
	stack <char> open;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
			open.push(s[i]);
		} else  if (!open.empty()) {
			if (s[i] == ']' && open.top() != '[') {
				return false;
			} else if (s[i] == '}' && open.top() != '{') {
				return false;
			} else if (s[i] == ')' && open.top() != '(') {
				return false;
			} else {
				open.pop();
			}
		}
	}
	if (!open.empty()) {
		return false;
	}
	return true;
}

int main()
{
	ifstream ifs;
	ifs.open("BRACKETS.INP");
	string s;
	ifs >> s;
	ifs.close();
	
	ofstream ofs;
	ofs.open("BRACKETS.OUT");
	int l = s.length();
	for (int i = 0; i < l; ++i) {
		string ls = s.substr(i, l - i) + s.substr(0, i);
		if (isRightBracket(ls)) {
			ofs << i + 1;
			return 1;
		}
	}
	ofs << -1;
	
	return 0;
}
