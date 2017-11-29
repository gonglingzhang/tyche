#include <iostream>
#include <time.h>
using namespace std;
int main() {
	clock_t start,finish;
	double totaltime;
	start=clock();
	int n,m=-1;
	int num[2];
	cin >> n;
	int a,b[n];
	for (int i = 0; i < n; ++i) {
		b[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = 0; j < n; ++j) {
		    if (a == b[j]) {
				b[j] = -2;
				break;
			}
		}
	}


	for (int i = 0; i < n; ++i) {
		if (b[i] != -2) {
			++m;
			num[m] = b[i];
			if(m == 1) {
				break;
			}
		}
	}
	if (num[0] > num[1]) {
		cout << num[1] << endl << num[0] << endl;
	} else {
		cout << num[0] << endl << num[1] << endl;
	}
	finish=clock();
	totaltime=finish-start;
	cout << totaltime << endl;
	return 0;
	
}























