#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int val[100000][2];
int dp[100000][2];
int main(void){

    int T,n;
    cin>>T;
    for(int t=0;t<T;t++){

        cin>>n;
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>val[j][i];
            }
        }
        dp[0][0]=val[0][0];
        dp[0][1]=val[0][1];

        for(int i=1;i<n;i++){
            dp[i][0]+=max((dp[i-1][1]+val[i][0]),dp[i-1][0]);
            dp[i][1]+=max((dp[i-1][0]+val[i][1]),dp[i-1][1]);
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<endl;

    }
}