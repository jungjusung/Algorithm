#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define MOD 1000007
using namespace std;

int N,M,C;

int dp[51][51][51][51];
int board[51][51];
int ans[51];

int main(void){
    cin>>N>>M>>C;
    memset(board,-1,sizeof(board));
    for(int i=0;i<C;i++){
        int x,y;
        cin>>x>>y;
        board[x][y]=i;
    }

   dp[1][0][0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j]==-1){
                dp[i][j][0][0]+=dp[i-1][j][0][0]+dp[i][j-1][0][0];
                dp[i][j][0][0]%=MOD;
            }
            for(int len=1;len<=C;len++){
                if(board[i][j]==-1){
                    //오락실이 아닐경우
                    for(int k=0;k<C;k++){
                        dp[i][j][k][len]+=dp[i-1][j][k][len]+dp[i][j-1][k][len];
                        dp[i][j][k][len]%=MOD;
                    }
                }else{
                    //오락실인 경우
                    int m=board[i][j];
                    if(len==1){
                        dp[i][j][m][len]+=dp[i-1][j][0][0]+dp[i][j-1][0][0];
                        dp[i][j][m][len]%=MOD;
                     }else{
                        for(int k=0;k<m;k++){
                            dp[i][j][m][len]+=dp[i-1][j][k][len-1]+dp[i][j-1][k][len-1];
                            dp[i][j][m][len]%=MOD;
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<=C; i++) {
        for (int k=0; k<max(C,1); k++) {
            ans[i] += dp[N][M][k][i];
            ans[i] %= MOD;
        }
        cout<<ans[i]<<" ";
    }
}
