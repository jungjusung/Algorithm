#include <iostream>
#include <cstring>
using namespace std;

int N;
char str[51][51];
int main(void){

    cin>>N;
    char temp[51];
    for(int i=0;i<N;i++){
        cin>>str[i];
    }
    for(int i=0;i<51;i++){
        temp[i]=str[0][i];
    }

    for(int i=1;i<N;i++){
        for(int j=0;j<51;j++){
            if(str[i][j]==NULL)
                break;
            if(temp[j]!=str[i][j]){
                temp[j]='?';
            }
        }
    }
    cout<<temp<<endl;

}