#include <iostream>
#include <cstring>
using namespace std;

int alphabetIndex[26];
char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(void){

    string str;
    cin>>str;
    memset(alphabetIndex,-1,sizeof(alphabetIndex));
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<str.size();j++)
        {
            if(alphabet[i]==str[j])
            {
                alphabetIndex[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        cout<<alphabetIndex[i]<<" ";
    }
    cout<<endl;
}