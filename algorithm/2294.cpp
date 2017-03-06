#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K;

int coin[101];
int dp[10001];
int main(void){
    cin>>N>>K;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        cin>>coin[i];
        //dp[coin[i]]=1;

    }
    dp[0]=0;
    for(int i=0; i<N; i++){
        for(int j = 0; j<=K;j++){
            if(j>=coin[i] && dp[j-coin[i]]!=-1){
                if(dp[j]==-1)
                    dp[j] = dp[j-coin[i]]+1;
                else
                    dp[j] = min(dp[j],dp[j-coin[i]]+1);
            }
        }
    }
/*    for(int i=0;i<=K;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    cout<<dp[K]<<endl;
}