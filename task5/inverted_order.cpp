/*
题目描述
从inp文件中读入数据，并倒序写入oup文件中，数据长度不超过1000
输入描述
没有输入数据。你需要从名为"inp"的文件中读入数据。
输出描述
你需要将所有的输出，写入名为"oup"的文件中。
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
const int N = 1000;
using namespace std;
int main() {
    string str,store[N],tmp;
    int count = 1;
    ofstream writeout;
    ifstream readin;
    readin.open("inp");
    while (getline(readin,str)) {
        store[count] = str;
        count++;
    }
    readin.close();
    writeout.open("oup");
    
    for (int i=count-1; i>0; i--) {
        string wte;
        tmp = store[i];
        for (int j=tmp.length()-1; j>=0; j--) {
            wte += tmp[j];
        }
        writeout << wte << endl;
    }
    writeout.close();

    return 0;
}
