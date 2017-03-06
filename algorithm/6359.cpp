#include <iostream>
#include <cstring>
using namespace std;

int T,n;

int dp[101];

int main(void){

    cin>>T;

    for(int t=0;t<T;t++){
        cin>>n;
        int result=0;
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i*j<=n){
                    if(dp[i*j]==0)
                        dp[i*j]=1;
                    else
                        dp[i*j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dp[i]==0)
                result++;
        }
        cout<<result<<endl;
    }

}