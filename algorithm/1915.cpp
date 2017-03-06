#include <iostream>
#include <algorithm>
using namespace std;

int board[1001][1001];
int dp[1001][1001];

int maxNum;
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            if(str[j]=='1'){
                board[i][j+1]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int num=-1;
        for(int j=1;j<=m;j++){
            if(board[i][j]==1){
                dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
                num=max(num,dp[i][j]);
            }
            maxNum=max(maxNum,num);
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<maxNum*maxNum<<endl;
}
