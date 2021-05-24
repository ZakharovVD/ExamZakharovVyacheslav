#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int do_op(string op, int i1, int i2) {
	if (op == "+") return i1 + i2;
	if (op == "-") return i1 - i2;
	if (op == "*") return i1 * i2;
	if (op == "/") {
		if (i1 * i2 > 0 or i1 % i2 == 0) return i1 / i2;
		else return i1 / i2 - 1;
	}
}

bool f(string crutch) {
	if (crutch == "+" or crutch == "-" or crutch == "/" or crutch == "*") return 1;
	else return 0;
}

int main() {
	ifstream cin; cin.open("input.txt");
	ofstream cout; cout.open("output.txt");
	vector<int> v;
	string tmp;
	while (cin >> tmp) {
		if (!f(tmp)) v.push_back(atoi(tmp.c_str()));
		else {
			if (v.size() < 2) {
				cout << "ERROR";
				return 0;
			}
			int n1 = v[v.size() - 2], n2 = v[v.size() - 1];
			v.erase(v.end() - 2, v.end());
			v.push_back(do_op(tmp, n1, n2));
		}
	}
	if (v.size() != 1) { cout << "ERROR"; }
	else { cout << v[0]; }
	return 0;
}
