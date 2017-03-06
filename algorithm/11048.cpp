#include <iostream>
using namespace std;

int board[1001][1001];
int dp[1001][1001];

int N,M;
void compute(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i-1>0)
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
            if(j-1>0)
                dp[i][j]=max(dp[i][j-1],dp[i][j]);
            if(j-1>0&&i-1>0)
                dp[i][j]=max(dp[i-1][j-1],dp[i][j]);

            dp[i][j]+=board[i][j];
        }
    }
}
int main(void){

    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
        }
    }
    compute();
    cout<<dp[N][M]<<endl;

}