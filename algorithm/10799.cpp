#include <iostream>
#include <stack>
using namespace std;


int main(void){

    stack<int> s;
    string str;
    cin>>str;

    int sum=0;
    int num=0;
    for(int i=0;i<str.size();i++){
         if (str[i] == '(')
            num++;
        else if(str[i]==')'){
            if(str[i-1]=='(')
                sum+=num-1;
            else
                sum++;

            num--;
        }
    }


    cout<<sum<<endl;
}