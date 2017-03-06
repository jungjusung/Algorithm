#include <iostream>
#include <string>
#include <vector>
using namespace std;
char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int main(void){
    string str;
    string key;
    getline(cin,str);
    cin>>key;
    int j=0;
    for(int i=0;i<str.size();i++,j++){
        if(j==key.size())
            j=0;
        int temp;
        int temp2;
        if(str[i]==' '){
            cout<<" ";
        }else{
            for(int k=0;k<26;k++){

                if(str[i]==alphabet[k]){
                    temp=k;
                }
                if(key[j]==alphabet[k]){
                    temp2=k;
                }
            }

            if(temp-temp2-1>=0){
                cout<<alphabet[temp-temp2-1];

            }
            else{
                cout<<alphabet[temp-temp2-1+26];
            }
        }
    }
}