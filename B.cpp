#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b, d, k;
	bool f = 1;
	cin >> a >> b;
	for (int i = a; i <= b; i++){
		if ((i % 2) == 0){
			d = 1;
			int tmp = round(sqrtf(i));
			for (int j = 2; j < tmp; j++){
				if ((i % j) == 0){
					if ((j % 2) == 0){
						d++;
					}
					k = i / j;
					if (((k % 2) == 0) && (j != k)){
						d++;
					}
					if (d > 3) break;
				}
			}
			if (d == 3)	{
				f = 0;
				cout << i << endl;
			}
		}
	}
	if (f) cout << 0;
	return 0;
}
