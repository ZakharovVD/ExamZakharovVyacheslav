#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int m[100];

void solve(int a, int b, int c) {
	if (!c) {
		cout << m[0];
		for (int i = 1; i < a; i++) {
			cout << " " << m[i];
		}
		cout << endl;
	}

	else for (int i = 1; i <= min(b, c); i++) {
		m[a] = i;
		solve(a + 1, i, c - i);
	}
}

int main() {
	int f; cin >> f;
	solve(0, f, f);
	return 0;
}
