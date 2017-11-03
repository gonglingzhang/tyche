#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void printPrime(int num);
int main() {
	int n,i;
	cin >> n;
	while (n--) {
		cin >> i;
		printPrime(i);
	}
	return 0;
}
void printPrime(int num) {
	int tmp = num;
	int a[100];
	cout << tmp << "=";
	int count = 0;
	for (int i = 2; i <= tmp; i++) {
		for (int j = 2; j <= num; j++) {
			if (num % j == 0) {
				num = num / j;
				a[count] = j;
				count++;
				break;
			}
		}
	}
	for (int i = 0; i < count-1; i++) {
		cout << a[i] << "*";
	}
	cout << a[count-1] << endl;
}
