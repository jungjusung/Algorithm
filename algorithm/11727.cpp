#include <iostream>
#define MOD 10007
using namespace std;


int dp[1001];
int N;
int main(void){

    cin>>N;

    dp[0]=1;
    dp[1]=1;


    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1]%MOD+dp[i-2]*2%MOD;
    }
    cout<<dp[N]%MOD<<endl;
}