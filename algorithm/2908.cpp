#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
    string str1;
    string str2;
    cin>>str1>>str2;
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int num1=atoi(str1.c_str());
    int num2=atoi(str2.c_str());
    if(num1>num2)
        cout<<num1<<endl;
    else
        cout<<num2<<endl;
}