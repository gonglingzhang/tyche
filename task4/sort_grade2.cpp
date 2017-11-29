#include <iostream>
#include <string>
using namespace std;
int main() {
	int N,X,Y;
	int multiplier[100], count = 0;
	cin >> N >> X >> Y;
	string student_name[N],goodfriend_name[X],badfriend_name[Y];
	int student_score[N];
	for (int i = 0; i < N; i++) {	//get all student
		cin >> student_name[i];
		cin >> student_score[i];
	}
	for (int i = 0; i < X; i++) {	//get goodfriend
		cin >> goodfriend_name[i];
	}
	for (int i = 0; i < Y; i++) {	//get badfriend
		cin >> badfriend_name[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < X; j++) {
			if (student_name[i] == goodfriend_name[j]) {
				if(student_score[i] < 60) {
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}
	
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < X; j++) { //if is goodfriend
			if (student_name[i] == goodfriend_name[j]) {
				if (student_score[i] == 95) {
					multiplier[count] = 6;
					count++;
				} else if (student_score[i] == 60) {
					multiplier[count] = 56;
					count++;
				}
			}
		}
		for (int j = 0; j < Y; j++) {
			if (student_name[i] == badfriend_name[j]) {
				if (student_score[i] == 60) {
					multiplier[count] = 6;
					count++;
				}
			}
		}
	}
	int out = 1;
	for(int i = 0; i < count; i++) {
		out = out * multiplier[i];
	}
	cout << out << endl;
	return 0;
}
