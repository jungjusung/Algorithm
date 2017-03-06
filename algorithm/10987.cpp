#include <iostream>
using namespace std;
char ch[5]={'a','e','i','o','u'};
int main(void){

    string str;
    int cnt=0;
    cin>>str;
    for(int i=0;str[i];i++){
        for(int j=0;j<5;j++){
            if(str[i]==ch[j])
                cnt++;
        }
    }
    cout<<cnt<<endl;
}