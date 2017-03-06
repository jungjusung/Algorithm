#include <iostream>
using namespace std;

int N,M,K;
long long dp[16][16][2];
int board[16][16];


int main(void){

    cin>>N>>M>>K;
    int cnt=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            board[i][j]=cnt++;

        }
    }
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){

           if(board[i][j]==K){

                if(i-1>=0&&j-1>=0){
                    dp[i][j][1]=dp[i-1][j][0]+dp[i][j-1][0];
                }else if(i-1>=0){
                    dp[i][j][1]=dp[i-1][j][0];
                }else if(j-1>=0){
                    dp[i][j][1]=dp[i][j-1][0];
                }
            }else{
                if(i-1>=0&&j-1>=0){
                    dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0];
                    dp[i][j][1]=dp[i-1][j][1]+dp[i][j-1][1];
                }else if(i-1>=0){
                    dp[i][j][0]=dp[i-1][j][0];
                    dp[i][j][1]=dp[i-1][j][1];
                }else if(j-1>=0){
                    dp[i][j][0]=dp[i][j-1][0];
                    dp[i][j][1]=dp[i][j-1][1];
                }
            }

        }
    }

    if(K!=0)
        cout<<dp[N-1][M-1][1]<<endl;
    else
        cout<<dp[N-1][M-1][0]<<endl;
}