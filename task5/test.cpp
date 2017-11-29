#include<stdio.h>  
#include<stdlib.h>
#include<iostream>
#include <fstream>
using namespace std;
#define N 1000
struct stack {  
    int top;//记录栈中有多少个元素,data[top]表示栈顶  
    string data[N];  
};  
  
struct stack mystack= {  
    -1,{0}  
};//-1代表栈中没有元素，{0}将数组全部初始化为0  
//判断栈是否为空。1代表栈为空，0代表不为空  
int isempty() {  
    if(mystack.top==-1) {  
        return 1;  
    } else {  
        return 0;  
    }  
}  
//设置栈为空  
void setempty() {  
    mystack.top=-1;  
}  
//压入一个数据，成功返回1，失败返回0(栈溢出)  
int push(string data) {  
    if(mystack.top+1<=N-1) {//没有溢出  
        mystack.data[++mystack.top]=data;  
        return 1;  
    } else {  
        return 0;  
    }  
}  
//取出一个数组  
string pop() {  
    if(isempty()) {  
        return 0;//为空，返回-1   
    } else {  
        return mystack.data[mystack.top--];  
    }  
  
}  
//一个测试，将十进制数转化为二进制  
void tenToTwo(int n){  
    if(n==0){  
        return;  
    }else{  
        int m=n%2;  
        tenToTwo(n/2);  
        printf("%d ",m);//打印出来的是逆序的   
    }  
}   
int main(){
    string a[N];
    string str;
    ifstream readin;
    ofstream writeout;
    readin.open("inp");
    int count = 0;
    while (getline(readin,str)) {
        a[count] = str;
        count++;
    }
    for(int i=0;i<count;i++){  
        push(a[i]);//压入数据   
    }  
    while(isempty()!=1){
        cout << pop() << endl;  
    }  
    readin.close();  
    return 0;
}  
