#include <iostream>
#include <cstring>
using namespace std;

int N;
int number[101];
long long dp[101][21];
//[x][0] 이면 +
//[x][1] 이면 -
int main(void){
    cin>>N;
    memset(number,0,sizeof(number));
    for(int i=0;i<N;i++){
        cin>>number[i];
    }

    dp[0][number[0]]=1;
    //for(int i=1;i<=N-1;i++){
    //    dp[1][number[i]]=1;
    //}
    for(int i=1;i<N;i++){
        for(int j=0;j<=20;j++){
            if(j-number[i]>=0)
                dp[i][j]+=dp[i-1][j-number[i]];
            if(j+number[i]<=20)
                dp[i][j]+=dp[i-1][j+number[i]];
        }
    }

    cout<<dp[N-2][number[N-1]]<<endl;
}