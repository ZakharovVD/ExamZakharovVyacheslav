#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string conv(int n) {
        ostringstream ss; ss << n;
        return ss.str();
}

string do_op(string op, string n1, string n2) {
        int i1 = atoi(n1.c_str()), i2 = atoi(n2.c_str());
        if (op == "+") return conv(i1 + i2);
        if (op == "-") return conv(i1 - i2);
        if (op == "*") return conv(i1 * i2);
        if (op == "/") {
                if (i1 * i2 > 0 or i1 % i2 == 0) return conv(i1 / i2);
                else return conv(i1 / i2 - 1);
        }
        return "";
}

int operation_priority(char c) {
        if (c == '+' or c == '-') return 0;
        if (c == '*' or c == '/') return 1;
        return -1;
}

bool f(string crutch) {
        if (crutch == "+" or crutch == "-" or crutch == "/" or crutch == "*") return 1;
        else return 0;
}

string strip_brackets(string s) {
        while (true) {
                if (s[0] != '(' || s[s.size() - 1] != ')')
                        return s;

                int br = 1;
                for (int i = 0; i < s.size(); i++) {
                        char c = s[i];
                        if (c == '(')
                                br++;
                        else if (c == ')') {
                                br--;
                                if (br == 1 && i != s.size() - 1) {
                                        return s;
                                }
                        }
                }
                s = s.substr(1, s.size() - 2);
        }
}

string convert(string s) {
        s = strip_brackets(s);
        int n = -1, n_priority = -1, br = 1;
        for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '(') {
                        br++;
                        continue;
                }
                if (c == ')') {
                        br--;
                        continue;
                }
                if (br != 1)
                        continue;

                int priority = operation_priority(c);
                if (priority == -1)
                        continue;

                if (n == -1 || priority <= n_priority) {
                        n = i;
                        n_priority = priority;
                }
        }
        return ((n == -1) ? s : convert(s.substr(0, n)) + " " + convert(s.substr(n + 1, s.size())) + " " + s.substr(n, 1));
}

void solve() {
        ifstream cin; cin.open("input.txt");
        ofstream cout; cout.open("output.txt");
        vector<string> v; string s;     getline(cin, s);
        s = convert(s) + " ";

        while (true) {
                if (s.find(' ') == -1) break;
                else {
                        v.push_back(s.substr(0, s.find(' ')));
                        s = s.substr(s.find(' ') + 1);
                }
        }

        while (true) {
                int i = -1;
                for (int j = 0; j < v.size(); j++) {
                        if (f(v[j])) {
                                i = j; break;
                        }
                }
                if (i != -1) {
                        string ans = do_op(v[i], v[i - 2], v[i - 1]);
                        v.insert(v.begin() + i + 1, ans);
                        v.erase(v.begin() + i - 2, v.begin() + i + 1);
                }
                else break;
        };
        cout << v[0];
        return;
}

int main() {
        solve();
        return 0;
}
