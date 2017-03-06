#include <iostream>
using namespace std;
#define MOD 1000000000
long long dp[201][201];
int main(void){
    int N,K;
    cin>>N>>K;
    for(int i=0;i<=N;i++){
        dp[i][1]=1;
    }
    for(int i=0;i<=N;i++){
        for(int j=2;j<=K;j++){
            for(int k=0;k<=i;k++){
               dp[i][j]=dp[i][j]%MOD+dp[k][j-1]%MOD;
            }
        }
    }
    cout<<(dp[N][K])%MOD<<endl;
}