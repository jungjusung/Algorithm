#include <iostream>
#include <algorithm>
using namespace std;


int dp[1001][31][3];
int treeNum[1001];
int main(void){

    int T,W;
    cin>>T>>W;
    for(int i=1;i<=T;i++)
        cin>>treeNum[i];


    for(int i=1;i<=T;i++){
        for(int j=0;j<=W;j++){

            if(treeNum[i]==1){
                //1번에서 떨어짐
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]+1);
                if(j-1>=0)
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][2]+1);

                dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][2]);
                if(j-1>=0)
                    dp[i][j][2]=max(dp[i][j][2],dp[i-1][j-1][1]);

            }else{

                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]);
             if(j-1>=0)
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][2]);

                dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][2]+1);
             if(j-1>=0)
                dp[i][j][2]=max(dp[i][j][2],dp[i-1][j-1][1]+1);
            }
        }
    }
    int jadoo=0;
    for(int i=0;i<=W;i++){
        jadoo=max(jadoo,dp[T][i][1]);
        jadoo=max(jadoo,dp[T][i][2]);
    }
    cout<<jadoo<<endl;
}