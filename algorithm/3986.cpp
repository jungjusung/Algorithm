#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string str;
int main(void){

    cin>>N;
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>str;
        stack<char> s;
        for(int j=0;j<str.size();j++){

            if(!s.empty()){
                if(s.top()==str[j])
                    s.pop();
                else
                    s.push(str[j]);
            }else{
                s.push(str[j]);
            }
        }
        if(s.empty())
            cnt++;
    }
    cout<<cnt<<endl;
}