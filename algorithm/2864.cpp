#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    string str1;
    string str2;
    string maxStr1;
    string maxStr2;
    string minStr1;
    string minStr2;
    cin>>str1>>str2;
    maxStr1=minStr1=str1;
    maxStr2=minStr2=str2;
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]=='5')
        {
            maxStr1[i]='6';
        }
        if(str2[i]=='5')
        {
            maxStr2[i]='6';
        }
    }
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]=='6')
        {
            minStr1[i]='5';
        }
        if(str2[i]=='6')
        {
            minStr2[i]='5';
        }
    }
    cout<<atoi(minStr1.c_str())+atoi(minStr2.c_str())<<" "<<atoi(maxStr1.c_str())+atoi(maxStr2.c_str())<<endl;
}