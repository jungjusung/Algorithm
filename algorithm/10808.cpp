#include <iostream>
using namespace std;

char alphabat[26]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int arr[26];
int main(void){

    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        for(int j=0;j<26;j++){
            if(str[i]==alphabat[j])
                arr[j]++;
        }
    }
    for(int i=0;i<26;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}