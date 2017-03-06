#include <iostream>
#define MOD 1000000000
using namespace std;


long long dp[10][101];
int N;
int main(void){

    cin>>N;
    dp[0][1]=0;
    for(int i=1;i<10;i++){
        dp[i][1]=1;
    }

    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            if(j-1>=0&&j+1<=9)
                dp[j][i]=dp[j-1][i-1]%MOD+dp[j+1][i-1]%MOD;
            else if(j-1<0)
                dp[j][i]=dp[j+1][i-1]%MOD;
            else if(j+1>9){
                dp[j][i]=dp[j-1][i-1]%MOD;
            }
        }
    }
    long long sum=0;
    for(int i=0;i<10;i++){
        sum=(sum+dp[i][N])%MOD;
    }
    cout<<sum<<endl;

}