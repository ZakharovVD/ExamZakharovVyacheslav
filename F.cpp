#include <iostream>
#include <queue>
using namespace std;

/*
6
0 2 4 0 0 0
2 0 9 7 0 0
4 9 0 8 1 0
0 7 8 0 3 1
0 0 1 3 0 2
0 0 0 1 2 0

4
0 0 0 0
0 0 2 1
0 2 0 4
0 1 4 0
*/

int** w;
int** h;
int n;

void print_r(int u, int v) {
	if (h[u][v] == 0) {
		return;
	}
	else {
		print_r(u, h[u][v] - 1);
		cout << h[u][v] << " ";
	}
}

void print_mat(int** m, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int tmp; cin >> n;
	w = new int* [n];
	h = new int* [n];

	for (int i = 0; i < n; i++) {
		w[i] = new int[n];
		h[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
			h[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (w[i][j] == 0) w[i][j] = 1e8;
				else h[i][j] = i + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (w[i][k] > w[i][j] + w[j][k]) {
					w[i][k] = w[i][j] + w[j][k];
					h[i][k] = j + 1;
				}
	//print_mat(w, n);
	//print_mat(h, n);

	//print_r(0, 5);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << "(" << i + 1 << "," << j + 1 << "): ";
			if (w[i][j] >= 1e8) cout << "0\n";
			else {
				print_r(i, j);
				cout << j + 1 << " (" << w[i][j] << ")\n";
			}
		}
	}
	return 0;
}
