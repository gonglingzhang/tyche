/*
题目描述
期末考试结束后，徐老师让助教统计所有同学的成绩并排名。助教觉得这个问题很简单，决定交给小明去做。小明暗暗窃喜，决定在排序之前先偷偷修改成绩，把好朋友的成绩都提高5分，不喜欢的同学的成绩都降低5分。但是，为了不被助教发现，小明遵循了这样的原则：1. 如果本来就高于95分，则不再提高分数；2. 如果提高后高于95分，则按95分计；3. 如果提高后的分数仍低于60分，则按60分计； 4. 如果降低后的分数低于60分，则按60分计； 5. 如果本来就低于60分，则不再降低分数。改完分数后，小明将新分数按从高到低排名，分数相同的按姓名的字典序排列，字典序小的在前。（本题纯属虚构，如有雷同，那是不可能的~）
输入描述
第一行为三个整数N、X、Y，分别表示总人数，好朋友数，不喜欢的人数
接下来N行，每行第一个是字符串，表示人名，第二个是整数，表示初始分数，用空格隔开（名字中可能包含0-9，A-Z和a-z）
接下来X行，每行一个字符串，表示好朋友的名字
接下来Y行，每行一个字符串，表示不喜欢的人的名字
输出描述
排好序的N行，每行第一个是字符串，表示人名，第二个是整数，表示修改后的分数，用空格隔开
样例输入
7 4 1
xiaomingZ 95
xiaoming 90
xiaoming0 93
xiaohong 98
xiaogang 54
xiaohua 88
xiaoqiang 50
xiaoming
xiaoming0
xiaohong
xiaogang
xiaoqiang
样例输出
xiaohong 98
xiaoming 95
xiaoming0 95
xiaomingZ 95
xiaohua 88
xiaogang 60
xiaoqiang 50
注释
数模约定：N，X，Y<=1000, 0 <= X,Y <=N，分数范围 [0,100]，名字长度(0，100)，X行和Y行中的名字不交叉，N行、X行、Y行中的名字均不重复。
字典序从小到大依次为：0,1,2,…,9,A,B,C,…,Z,a,b,c,...,z
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	int N,X,Y;
	string student_name[100],goodfriend_name[100],badfriend_name[100];
	int student_score[100];
	cin >> N >> X >> Y;
	for (int i = 0; i < N; i++) {	//get the count of student
		cin >> student_name[i];
		cin >> student_score[i];
	}
	for (int i = 0; i < X; i++) {	//goodfriend
		cin >> goodfriend_name[i];
	}
	for (int i = 0; i < Y; i++) {	//badfriend
		cin >> badfriend_name[i];
	}
	for (int i = 0; i < N; i++) {				//+ or - score
		for (int j = 0; j < X; j++) {
			if (student_name[i] == goodfriend_name[j]) {
				if (student_score[i] > 95) {
					student_score[i] = student_score[i];
				}else if ((student_score[i] > 89) && (student_score[i] < 96)) {
					student_score[i] = 95;
				} else if (student_score[i] < 55) {
					student_score[i] = 60;
				} else {
					student_score[i] += 5;
				}
			}
			if (student_name[i] == badfriend_name[j]) {
				if (student_score[i] < 60) {
					student_score[i] = student_score[i];
				} else if ((student_score[i] > 59) && (student_score[i] < 66)) {
					student_score[i] = 60;
				} else {
					student_score[i] -= 5;
				}
			}
		}
	}
	string tmp_string;
	int tmp_int;
	for (int i = 0; i < N; i++) {								//bubble sort by student_socre
		for (int j = 0; j < i; j++) {
			if (student_score[j] < student_score[j+1]) {
				tmp_string = student_name[j];
				student_name[j] = student_name[j+1];
				student_name[j+1] = tmp_string;
				tmp_int = student_score[j];
			    student_score[j] =  student_score[j+1];
			    student_score[j+1] = tmp_int;
			}
		}
	}
	int a_int,b_int,len1,len2,longer;
	for (int i = 0; i < N; i++) {			//sort by name
		for (int j = 0; j < N; j++) {
			if (student_score[j] == student_score[j+1]) {
				len1 = student_name[j].length();
				len2 = student_name[j+1].length();
				if (len1 > len2) {
					longer = len1;			
				} else {
					longer = len2;
				}
				for (int x = 0; x < longer; x++) {
					a_int = student_name[j][x];
					b_int = student_name[j+1][x];
					if (a_int > b_int) {
						tmp_string = student_name[j];
						student_name[j] = student_name[j+1];
						student_name[j+1] = tmp_string;
						tmp_int = student_score[j];
						student_score[j] =  student_score[j+1];
						student_score[j+1] = tmp_int;
					}
				}//for (int x = 0; x < longer; x++)
			}//if (student_score[j] == student_score[j+1])
		}//for (int j = 0; j < N; j++)
	}//for (int i = 0; i < N; i++)
	for (int i = 0; i < N; i++) {
		cout << student_name[i] << " " << student_score[i] << endl;
	}
	return 0;
}
