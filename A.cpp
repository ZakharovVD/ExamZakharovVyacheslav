#include <iostream>

using namespace std;

int main(){
	int a, b;
	int ans = 0, max = -1e9, k, m;
	cin >> a >> b;
	for (int i = b; i >= a; i--){
		(i < 0) ? k = -1 * i : k = i;
		m = 0;
		if (k % 10!= 0){
			if (k % 2 == 0)	{
				while (k > 0){
					m += k % 2;
					k /= 2;
				}
				if (m == 5){
					if (i > max)max = i;
					ans++;
				}
			}
		}
	}
	(ans == 0) ? cout << "0 0" : cout << ans << " " << max;
	return 0;
}

