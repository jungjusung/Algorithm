#include <iostream>
using namespace std;

int N;
int dp[31];
int main(void){

    cin>>N;
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    for(int i=4;i<=N;i++){
        dp[i]=dp[i-2]*3;
        for(int j=4;j<=i;j+=2){
            dp[i]+=dp[i-j]*2;
        }
    }
/*    for(int i=0;i<=N;i++){
        cout<<dp[i]<<" ";
    }*/
    cout<<dp[N]<<endl;
}