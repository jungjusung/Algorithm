#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;

long long dp[5002];
string str;
int main(void){

    str="0";
    string str1;
    cin>>str1;
    str+=str1;
    dp[0]=1;
    if(str[1]-48!=0)
        dp[1]=1;
    else
        dp[1]=0;

    for(int i=2;i<str.size();i++){
        if(str[i-1]-48!=0&&str[i]-48!=0&&(str[i-1]-48)*10+str[i]-48<=26){
            //cout<<(str[i-1]-48)*10+str[i]-48<<endl;
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        else if(str[i-1]-48==0&&str[i]-48!=0){
            dp[i]=dp[i-1]%MOD;
        }
        else if(str[i]-48==0&&str[i-1]-48!=0&&(str[i-1]-48)*10<=26){
            dp[i]=dp[i-2]%MOD;

        }else if(str[i]-48==0&&str[i-1]-48==0){

            dp[i]=0;
        }else if(str[i-1]-48!=0&&str[i]-48!=0&&(str[i-1]-48)*10+str[i]-48>26)
            dp[i]=dp[i-1]%MOD;
    }
 /*   for(int i=1;i<str.size();i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/
        cout<<dp[str.size()-1]<<endl;
}