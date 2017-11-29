/*
题目描述
从inp文件读入数据，并写入oup文件中，长度不超过1000
输入描述
没有输入数据。你需要从名为"inp"的文件中读入数据。
输出描述
你需要将所有的输出，写入名为"oup"的文件中。
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string s;
    ifstream readin;
    ofstream writeout;
    readin.open("inp");
    writeout.open("oup");
    while (getline(readin,s)) {
	writeout << s << endl;
    }
    writeout.close();
    readin.close();

    return 0;
}
