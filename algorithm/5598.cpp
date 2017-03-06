#include <iostream>
using namespace std;

char alphabet[26]={ 'A','B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

char str[1001];
int main(void){
    string temp;
    cin>>temp;
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<26;j++){
            if(temp[i]==alphabet[j]){

                if(j-3>=0)
                    str[i]=alphabet[j-3];
                else
                    str[i]=alphabet[26+j-3];
            }
        }
    }
    for(int i=0;str[i];i++)
        cout<<str[i];
}