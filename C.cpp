#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream cin; cin.open("input.txt");
	ofstream cout; cout.open("output.txt");
	string s; getline(cin, s);
	int ans = 1, tmpa = 1;
	char a = s[0];

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) tmpa++;
		if (tmpa > ans) {
			ans = tmpa;
			a = s[i];
		}
		if (s[i] != s[i + 1]) {
			tmpa = 1;
		}
	}
	cout << a << " " << ans;
	
}
